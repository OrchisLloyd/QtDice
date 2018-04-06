/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 */

#include "qtdice.h"
#include "About/about.h"

QtDice::QtDice() : qtdice_ui(new Ui::QtDice)
{
	qtdice_ui->setupUi(this);

	QtDice::setWindowTitle("QtDice");
	QIcon* qico = new QIcon(":/images/dice.ico");
	QtDice::setWindowIcon(*qico);
	qtdice_ui->m_button->setIcon(*qico);

	movie = new QMovie(this);
	label_status = new QLabel("Haven't rolled yet", this);
	qtdice_ui->gridLayout_Status->addWidget(label_status, 0, 0);

	qtdice_ui->spinBox->setRange(1, 6);

#ifdef USER_MODE
 	checkBox = new QCheckBox("User mode", this);
 	label_status = new QLabel("Haven't rolled yet", this);

 	qtdice_ui->gridLayout_Status->addWidget(checkBox, 0, 0);
 	qtdice_ui->gridLayout_Status->addWidget(label_status, 0, 1);
#endif

	//Create the image to show our red dice in the beggining
	QPixmap image(":/images/dice.png");
	qtdice_ui->label->setPixmap(image);
	qtdice_ui->label->setBackgroundRole(QPalette::Base);
	qtdice_ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	qtdice_ui->label->setScaledContents(true);

	qtdice_ui->label->show();

	//Take the focus out of spinBox because when it looses
	//it later it trigers the warning message
	qtdice_ui->m_button_quit->setFocus();

	qtdice_ui->action_Roll_the_dice->setIcon(*qico);
	qtdice_ui->m_button_quit->setIcon(QIcon::fromTheme("application-exit", QIcon(":/images/exit.ico")));
	qtdice_ui->action_Quit->setIcon(QIcon::fromTheme("application-exit", QIcon(":/images/exit.ico")));
	qtdice_ui->action_About_QtDice->setIcon(QIcon::fromTheme("help-about", QIcon(":/images/dice.ico")));
	qtdice_ui->action_About_Qt->setIcon(QIcon(":/images/Qt_logo_2016.svg.ico"));

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

#ifdef USER_MODE
	//Handle the user mode and it's creation/deletion
	//At first, make the menu disabled if user mode is already
	//on. This avoids the creation of multiples UserWidget
	qtdice_ui->actionDisable_User_Menu->setEnabled(false);
	connect(this, &QtDice::userModeIsOn, this, [this]()
	{
		qtdice_ui->actionEnable_User_Menu->setEnabled(false);
		qtdice_ui->actionDisable_User_Menu->setEnabled(true);
	});
	connect(this, &QtDice::userModeIsOff, this, [this]()
	{
		qtdice_ui->actionDisable_User_Menu->setEnabled(false);
		qtdice_ui->actionEnable_User_Menu->setEnabled(true);
	});
	connect(qtdice_ui->actionEnable_User_Menu, &QAction::triggered, this, [this]()
	{
		enableUserWidget();
		checkBox->setChecked(true);
		qtdice_ui->actionDisable_User_Menu->setEnabled(true);
	});
	connect(qtdice_ui->actionDisable_User_Menu, &QAction::triggered, this, [this]()
	{
		deleteUserWidget();
		checkBox->setChecked(false);
		qtdice_ui->actionDisable_User_Menu->setEnabled(false);
	});
	connect(checkBox, &QCheckBox::clicked, this,
	        [this]()
	{
		if(checkBox->isChecked())
		{
			qtdice_ui->actionEnable_User_Menu->setEnabled(false);
			qtdice_ui->actionDisable_User_Menu->setEnabled(true);
			this->enableUserWidget();
		}
		else if(!checkBox->isChecked())
		{
			qtdice_ui->actionEnable_User_Menu->setEnabled(true);
			qtdice_ui->actionDisable_User_Menu->setEnabled(false);
			this->deleteUserWidget();
		}
	});
#endif

	qtdice_ui->label_warning->clear();
	qtdice_ui->centralwidget->adjustSize();
	adjustSize();
}

#ifdef USER_MODE
void QtDice::enableUserWidget()
{
	userwidget = new UserWidget(this);
	qtdice_ui->gridLayout_Widget->addWidget(userwidget);
	qtdice_ui->actionDisable_User_Menu->setEnabled(true);
	qtdice_ui->actionEnable_User_Menu->setEnabled(false);

	emit userModeIsOn();
}

void QtDice::deleteUserWidget()
{
	qtdice_ui->gridLayout_Widget->removeWidget(userwidget);

	userwidget->setParent(nullptr);
	delete userwidget;

	qtdice_ui->actionEnable_User_Menu->setEnabled(true);
	qtdice_ui->actionDisable_User_Menu->setEnabled(false);

	this->centralWidget()->adjustSize();
	this->adjustSize();

	emit userModeIsOff();
}
#endif

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
	//About(this).show();
}
