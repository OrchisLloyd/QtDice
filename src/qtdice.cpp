/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 */

#include "qtdice.h"
#include "About/about.h"
#include "Settings/configure.h"

QtDice::QtDice() : qtdice_ui(new Ui::QtDice)
{
	qtdice_ui->setupUi(this);

	QtDice::setWindowTitle("QtDice");
	QIcon* qico = new QIcon(":/images/dice.ico");
	QtDice::setWindowIcon(QIcon::fromTheme("roll", *qico));
	qtdice_ui->m_button->setIcon(QIcon::fromTheme("roll", *qico));

#ifdef ENABLE_SOUND
	roll_sound.setSource(QUrl("qrc:resources/sound/roll.wav"));
	Q_ASSERT_X(roll_sound.isLoaded(), "Error loading roll.wav", "");
	roll_sound.setVolume(1.0f);
#endif

	movie = new QMovie(this);
	label_status = new QLabel("Haven't rolled yet", this);
	qtdice_ui->gridLayout_Status->addWidget(label_status, 0, 0);

	// Just for experimenting with submenus. Ignore this
#ifdef ENABLE_POPUP
	QMenu* menu = new QMenu(tr("Sub Menu"));
	QAction* roll = new QAction(tr("Roll the dice"));
	menu->addAction(roll);
	connect(roll, &QAction::triggered, this, static_cast<void (QtDice::*)(void)>(&QtDice::reload));
	qtdice_ui->m_button->setMenu(menu);
#endif

	qtdice_ui->spinBox->setRange(1, 6);

	//Create the image to show our red dice in the beggining
	QPixmap image(":/resources/images/dice.png");
	qtdice_ui->label->setPixmap(image);
	qtdice_ui->label->setBackgroundRole(QPalette::Base);
	qtdice_ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	qtdice_ui->label->setScaledContents(true);

	qtdice_ui->label->show();

	//Take the focus out of spinBox because when it looses
	//it later it trigers the warning message
	qtdice_ui->m_button_quit->setFocus();

	qtdice_ui->action_Roll_the_dice->setIcon(QIcon::fromTheme("roll", *qico));
	qtdice_ui->m_button_quit->setIcon(QIcon::fromTheme("application-exit", QIcon(":/resources/images/exit.ico")));
	qtdice_ui->action_Quit->setIcon(QIcon::fromTheme("application-exit", QIcon(":/resources/images/exit.ico")));
	qtdice_ui->action_About_QtDice->setIcon(QIcon::fromTheme("help-about", QIcon(":/resources/images/dice.ico")));
	qtdice_ui->action_About_Qt->setIcon(QIcon(":/resources/images/Qt_logo_2016.svg.ico"));
	qtdice_ui->action_Configure->setIcon(QIcon::fromTheme("settings"));

	connect(qtdice_ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged),
	        this, static_cast<void (QtDice::*)(int)>(&QtDice::reload));

	connect(qtdice_ui->spinBox, &QSpinBox::editingFinished, this, [&]()
	{
		qtdice_ui->label_warning->setText(tr("Did you cheat?"));
	});
	connect(this, &QtDice::reloaded_without_spinbox, qtdice_ui->label_warning, &QLabel::clear);

	//Connect buttons to functions
	connect(qtdice_ui->m_button, &QPushButton::clicked,
	        this, static_cast<void (QtDice::*)(void)>(&QtDice::reload));
	connect(qtdice_ui->m_button_quit, &QPushButton::clicked, this, &QApplication::exit);

	//Let's connect the menus with some functions
	connect(qtdice_ui->action_Roll_the_dice, &QAction::triggered,
	        this, static_cast<void (QtDice::*)(void)>(&QtDice::reload));
	connect(qtdice_ui->action_Quit, &QAction::triggered, this, &QApplication::quit);
	connect(qtdice_ui->action_About_QtDice, &QAction::triggered, this, &QtDice::aboutQtDice);
	connect(qtdice_ui->action_About_Qt, &QAction::triggered,  &QApplication::aboutQt);
	connect(qtdice_ui->action_Configure, &QAction::triggered, this, &QtDice::QtDiceConfiguration);

	qtdice_ui->label_warning->clear();
	qtdice_ui->centralwidget->adjustSize();
	adjustSize();
}

void QtDice::keyPressEvent(QKeyEvent* e)
{
	if(e->key() == Qt::Key_R)
	{
		reload();
	}
	else if(e->key() == Qt::Key_Escape)
	{
		QApplication::quit();
	}
}

void QtDice::aboutQtDice()
{
	About* a = new About(this);
	a->show();
}

void QtDice::QtDiceConfiguration()
{
	Configure* c = new Configure(this);
	c->show();
}

//Before showing the image, it plays a small animation of
//a dice that is rolling for enhanced user experience
void QtDice::animate_dice()
{
#ifdef ENABLE_SOUND
	//QSound::play(":/sound/roll.wav");
	roll_sound.play();
	qDebug() << "Play sound";
#endif

	// When animation starts, disable spinBox, the buttons etc...
	connect(movie, &QMovie::started, this, &QtDice::disableWidgets);

	//Thanks to the guys at this thread :
	//https://forum.qt.io/topic/88197/custom-signal-to-slot-the-slot-requires-more-arguments-than-the-signal-provides
	connect(movie, &QMovie::frameChanged, this, std::bind(&QtDice::qmovieFrameChanged, this, movie));
	connect(this, &QtDice::qmovieFrameChanged, this, &QtDice::stop_last_frame);

	// When movie is finished, re-enable spinBox, buttons etc
	connect(movie, &QMovie::finished, this, &QtDice::enableWidgets);

	//Make sure we don't constantly re-append a fileName!
	if(movie->fileName() == "")
	{
		//movie->setFileName(":/images/rolling_infinite.gif");
		movie->setFileName(":resources/images/bluedice.gif");
	}

	qtdice_ui->label->setMovie(movie);

	//Just to make sure that movie has a valid type or exit
	if(movie->isValid())
	{
		//TODO Debug why this is printed twice for every press of the m_button
		//qDebug() << "is valid";
		movie->start();
	}
	else
	{
		QString anim_error {"Animation type is not supported!"};
		qtdice_ui->label->setText(tr(anim_error.toLocal8Bit().constData()));
		QMessageBox::critical(this, tr("Error"), tr(anim_error.toLocal8Bit().constData()));
	}
}

void QtDice::enableWidgets()
{
	qtdice_ui->label->setPixmap(image);
	qtdice_ui->label->show();
	qtdice_ui->m_button->setEnabled(true);
	qtdice_ui->m_button->setFocus();
	qtdice_ui->action_Roll_the_dice->setEnabled(true);

	emit dice_stopped_rolling();
}

void QtDice::disableWidgets()
{
	//Now that movie is started, set the following...
	qtdice_ui->m_button_quit->setFocus();
	qtdice_ui->action_Roll_the_dice->setEnabled(false);
	qtdice_ui->m_button->setEnabled(false);
	//...also set the QLabel's that show the status
	label_status->setText(tr("Rolling..."));
	qtdice_ui->spinBox->setEnabled(false);
}

// This function declares image_update(int image_number)
// What this function does, is that it accepts an image_number
// which is generated randomly in Dice class members and based
// on this integer it selects the proper dice image to show
void QtDice::image_update(int image_number)
{
	//Now deal with which image will be loaded based on image_number
	//The whole point of this program is here
	QString image_name {":/resources/images/dice-%1.png"};

	if((image_number < 0) || (image_number > 6))
	{
		qDebug() << "Oops! Very wrong number...";
		QString msg_error = "A dice doesn't have this number : " + (QString("%1").arg(image_number));
		QMessageBox::critical(this, tr("QtDice"), 
		                      tr(msg_error.toLocal8Bit().constData()));
	}
	else
	{
		image.load(image_name.arg(image_number));
	}

	connect(movie, &QMovie::frameChanged, this,
	        [ = ]()
	{
		if(movie->state() == QMovie::NotRunning)
		{
			qtdice_ui->spinBox->blockSignals(true);
			qtdice_ui->spinBox->setValue(image_number);
			qtdice_ui->spinBox->blockSignals(false);
		}
	});
}

// Check if the frame is the last one and stop the dice animation
void QtDice::stop_last_frame(QMovie* movie)
{
	if(movie->currentFrameNumber() == (movie->frameCount() - 1))
	{
		movie->stop();

		//Explicity emit finished signal
		//https://bugreports.qt.io/browse/QTBUG-66733
		if(movie->state() == QMovie::NotRunning)
		{
			emit movie->finished();
			label_status->setText(tr("Stopped"));
			qtdice_ui->spinBox->setEnabled(true);
		}
	}
}

// This is the random reload function. After the animation is over,
// a dice is rolled. Look at Dice/dice.cpp for more details.
void QtDice::reload()
{
	animate_dice();

	//If Dice object doesn't exist (=first run), initialize one
	if(!pDice)
	{
		pDice = new Dice();
	}

	pDice->roll();
	image_update(pDice->get_number());

	emit reloaded_without_spinbox();
}

// This is a reload function. After the animation is over,
// a dice is given a "hardcoded" value. Look at Dice/dice.cpp for more details.
void QtDice::reload(int number)
{
	animate_dice();

	//If Dice object doesn't exist (=first run), initialize one
	if(!pDice)
	{
		pDice = new Dice(number);
	}
	else
	{
		pDice->set_number(number);
	}

	image_update(pDice->get_number());
// Actually this function doesn't even need one Dice.
// It uses a known int value, it doesn't have to use Dice::get_number to get one.
}

