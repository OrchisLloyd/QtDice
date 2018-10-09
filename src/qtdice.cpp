/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 */
#include "headers/qtdice.h"
#include "headers/about.h"
#include "headers/configure.h"

#include <functional>

QtDice::QtDice( int number, QWidget *parent )
	: diceNumber( number ),
	  QMainWindow( parent ),
	  btnRoll( new QPushButton( tr( "&Roll the dice" ) ) ),
	  btnReset( new QPushButton( tr( "&Reset" ) ) ),
	  btnQuit( new QPushButton( tr( "&Quit" ) ) ),
	  widgetCentral( new QWidget() ),
	  gridLayout( new QGridLayout ),
	  gridLabel( new QGridLayout ),
	  gridStatus( new QGridLayout ),
	  gridWarning( new QGridLayout ),
	  image( new QPixmap( ":/resources/images/dice.png" ) ),
	  label( new QLabel ),
	  labelStatus( new QLabel( tr( "Haven't rolled yet" ) ) ),
	  actionRoll( new QAction( tr( "&Roll the dice" ), this ) ),
	  actionQuit( new QAction( tr( "&Quit" ), this ) ),
	  actionConfigure( new QAction( tr( "&Configure" ), this ) ),
	  actionAboutQt( new QAction( tr( "&About Qt" ), this ) ),
	  actionAbout( new QAction( tr( "&About QtDice" ), this ) ),
	  movie( new QMovie( this ) ),
	  spinBox( new QSpinBox ),
	  settings( new QSettings( "QtDice" ) ),
	  qtdiceIcon( new QIcon( ":/resources/images/dice.ico" ) ),
	  exitIcon( new QIcon( ":/resources/images/exit.ico" ) ),
	  quitShortCut( new QShortcut( QKeySequence( Qt::Key_Escape ), this ) ),
	  thread( new QThread( this ) ),
	  pDice( Dice::instance() )
{
	qDebug() << QString( "The number given from argv is %1" ).arg( diceNumber );
	createMenus();

	setWindowTitle( "QtDice" );
	setWindowIcon( QIcon::fromTheme( "roll", *qtdiceIcon ) );

	setupWidgets();
	setupLayouts();

	setupConnections();
	setupConnectionsOfReload();
	setupConnectionsOfAnimation();

	setCentralWidget( widgetCentral.data() );
	centralWidget()->setLayout( gridLayout.data() );
	setMinimumSize( 520, 580 );
	setMaximumSize( 520, 580 );

	// GUI is all set, handle the argv that is passed to the QtDice ctor
	if ( ( diceNumber > 1 ) && ( diceNumber < 6 ) ) { reload( diceNumber ); }
	else if ( diceNumber != 0 )
	{
		std::cerr << "Exit, that's an inappropriate number\n";
		reload( 4 );
	}
}

QtDice::~QtDice() = default;

void QtDice::QtDiceConfiguration()
{
	Configure *confWindow = new Configure( this );
	confWindow->show();
}

// void QtDice::aboutQtDice()
// {
// 	About *aboutWindow = new About(this);
// 	aboutWindow->show();
// }

//Before showing the image, it plays a small animation of a rolling
//dice for enhanced user experience
void QtDice::animateDice()
{
#ifdef ENABLE_SOUND
	// Decide if the sound will be played...
	if ( isSoundEnabled() )
	{
		roll_sound.play();
		qDebug() << "Play sound";
	}

#endif                                                      // ENABLE_SOUND

	//Make sure we don't constantly re-append a fileName!
	if ( movie->fileName() == "" ) { movie->setFileName( ":resources/images/bluedice.gif" ); }

	label->setMovie( movie.data() );

	//Just to make sure that movie has a valid type or exit
	if ( movie->isValid() ) { movie->start(); }
	else
	{
		QString animationError {"Animation type is not supported! Did you forget to include *.qrc file?"};
		label->setText( tr( animationError.toLocal8Bit().constData() ) );
		QMessageBox::critical( this, tr( "Error" ), tr( animationError.toLocal8Bit().constData() ) );
	}
}

void QtDice::disableWidgets()
{
	//Now that movie is started, set the following...
	btnRoll->setFocus();
	actionRoll->setEnabled( false );
	btnRoll->setEnabled( false );

	//...also set the QLabel that show the status
	labelStatus->setText( tr( "Rolling..." ) );
	spinBox->setEnabled( false );
}

void QtDice::enableWidgets()
{
	label->setPixmap( *image.data() );
	label->show();
	btnRoll->setEnabled( true );
	btnRoll->setFocus();
	actionRoll->setEnabled( true );
}

// This function declares image_update(int image_number)
// This function accepts an image_number which is already have been
// generated randomly in Dice class members. Based on image_number it
// selects the proper dice image to show
void QtDice::imageUpdate( int imageNumber )
{
	//Now deal with which image will be loaded based on image_number
	//The whole point of this program is here
	QString imageName {":/resources/images/dice-%1.png"};

	if ( ( imageNumber < 0 ) || ( imageNumber > 6 ) )
	{
		QString errorMsg = "A dice doesn't have this number : "
				   + ( QString( "%1" ).arg( imageNumber ) );
		QMessageBox::critical( this, tr( "QtDice" ),
				       tr( errorMsg.toLocal8Bit().constData() ) );
	}
	else { image->load( imageName.arg( imageNumber ) ); }
}

bool QtDice::isSoundEnabled()
{
	settings->beginGroup( tr( "/sound" ) );
	settings->sync();

	if ( settings->value( "rolling_sound" ).toBool() )
	{
		settings->endGroup();
		return true;
	}
	else
	{
		settings->endGroup();
		return false;
	}
}

// This is the random reload function. After the animation is over, a dice
// is rolled. Look at Dice/dice.cpp for more details.
void QtDice::reload()
{
	animateDice();

	pDice->roll();
	imageUpdate( pDice->getNumber() );

}

// This is a reload function. After the animation is over,
// a dice is given a "hardcoded" value. Look at Dice/dice.cpp for more details.
void QtDice::reload( int number )
{
	animateDice();

	pDice->setNumber( number );
	imageUpdate( pDice->getNumber() );
// Actually this function doesn't even need one Dice.
// It uses a known int value, it doesn't have to use Dice::get_number to get one.
}

void QtDice::resetQtDice()
{
	numberOfRolls = 0;
	setupWidgets();
	label->setPixmap( QPixmap( ":/resources/images/128-apps-dice.png" ) );
	btnReset->setEnabled( false );
	spinBox->clear();
}

void QtDice::createMenus()
{
	menuFile.reset( menuBar()->addMenu( tr( "&File" ) ) );
	menuEdit.reset( menuBar()->addMenu( tr( "&Edit" ) ) );
	menuAbout.reset( menuBar()->addMenu( tr( "&About" ) ) );

	menuFile->addAction( actionRoll.data() );
	actionRoll->setIcon( *qtdiceIcon.data() );
	actionRoll->setShortcuts( {QKeySequence::Refresh ,
				   QKeySequence( Qt::ControlModifier + Qt::Key_R )
				  } );
	connect( actionRoll.data(), &QAction::triggered, this,
		 static_cast<void ( QtDice::* )( void ) > ( &QtDice::reload ) );

	menuFile->addSeparator();

	menuFile->addAction( actionQuit.data() );
	actionQuit->setIcon( *exitIcon.data() );
	actionQuit->setShortcuts( { QKeySequence( Qt::ControlModifier + Qt::Key_Q ),
				    QKeySequence::Close
				  } );
	connect( actionQuit.data(), &QAction::triggered, this, QApplication::quit );

	menuEdit->addAction( actionConfigure.data() );
	connect( actionConfigure.data(), &QAction::triggered, this, &QtDice::QtDiceConfiguration );
	actionConfigure->setShortcuts( { QKeySequence( Qt::ControlModifier + Qt::Key_E ),
					 QKeySequence::Preferences
				       } );
	actionConfigure->setIcon( QIcon::fromTheme( "settings-configure" ) );

	menuAbout->addAction( actionAbout.data() );
	actionAbout->setIcon( QIcon::fromTheme( "help-about", QIcon( ":/resources/images/dice.ico" ) ) );
	//connect(actionAbout.data(), &QAction::triggered, this, &QtDice::aboutQtDice);

	menuAbout->addAction( actionAboutQt.data() );
	actionAboutQt->setIcon( QIcon( ":/resources/images/Qt_logo_2016.svg.ico" ) );
	actionAboutQt->setShortcut( QKeySequence( Qt::ControlModifier + Qt::Key_B ) );
	connect( actionAboutQt.data(), &QAction::triggered, this, &QApplication::aboutQt );
}

void QtDice::setupConnections()
{
	//Connect spinBox to reload function and the label_warning
	connect( spinBox.data(), static_cast<void ( QSpinBox::* )( int )> ( &QSpinBox::valueChanged ), this,
		 static_cast<void ( QtDice::* )( int ) > ( &QtDice::reload ) );

	//Connect buttons to functions
	connect( btnRoll.data(), &QPushButton::clicked, this,
		 static_cast<void ( QtDice::* )( void ) > ( &QtDice::reload ) );

	connect( btnQuit.data(), &QPushButton::clicked, this, &QApplication::quit );

	connect( btnReset.data(), &QPushButton::clicked, this, &QtDice::resetQtDice );
}

void QtDice::setupConnectionsOfAnimation()
{
	// When animation starts, disable spinBox, the buttons etc...
	connect( movie.data(), &QMovie::started, this, &QtDice::disableWidgets );

	//Thanks to the guys at this thread :
	//https://forum.qt.io/topic/88197/custom-signal-to-slot-the-slot-requires-more-arguments-than-the-signal-provides
	connect( movie.data(), &QMovie::frameChanged,
		 this, std::bind( &QtDice::qmovieFrameChanged, this, movie.data() ) );

	connect( this, &QtDice::qmovieFrameChanged, this, &QtDice::stopLastQMovieFrame );

	// When movie is finished, re-enable spinBox, buttons etc
	connect( movie.data(), &QMovie::finished, this, &QtDice::enableWidgets );
	//
}

void QtDice::setupConnectionsOfReload()
{
	connect( movie.data(), &QMovie::frameChanged, this,
		 [ = ]()
	{
		if ( movie->state() == QMovie::NotRunning )
		{
			spinBox->blockSignals( true );
			spinBox->setValue( imageNumber );
			spinBox->blockSignals( false );
		}
	} );
}

void QtDice::setupLayouts()
{
	gridLayout->addLayout( gridLabel.data(), 0, 0 );
	gridLayout->addLayout( gridStatus.data(), 1, 0 );
	gridLayout->addLayout( gridWarning.data(), 2, 0 );

	gridLabel->addWidget( label.data(), 0, 0 );

	gridStatus->addWidget( labelStatus.data(), 0, 0 );
	gridStatus->addWidget( spinBox.data(), 0, 1 );
	gridStatus->addWidget( btnRoll.data(), 0, 2 );

	gridWarning->addWidget( btnReset.data(), 0, 0 );
	gridWarning->addWidget( btnQuit.data(), 0, 1 );
}

void QtDice::setupWidgets()
{
	btnRoll->setIcon( QIcon::fromTheme( "roll", *qtdiceIcon.data() ) );
	btnQuit->setIcon( QIcon::fromTheme( "application-exit", *exitIcon.data() ) );


	btnReset->setEnabled( false );

	spinBox->setRange( 1, 6 );

	label->setPixmap( *image.data() );
	label->setBackgroundRole( QPalette::Base );
	label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
	label->setScaledContents( true );
	label->setFrameStyle( QFrame::StyledPanel | QFrame::Raised );
	label->setLineWidth( 2 );
}

// Check if the frame is the last one and stop the dice animation
void QtDice::stopLastQMovieFrame( QMovie *movie )
{
	if ( movie->currentFrameNumber() == ( movie->frameCount() - 1 ) )
	{
		movie->stop();

		//Explicity emit finished signal
		//https://bugreports.qt.io/browse/QTBUG-66733
		if ( movie->state() == QMovie::NotRunning )
		{
			emit movie->finished();
			labelStatus->setText( tr( "Ready" ) );
			spinBox->setEnabled( true );
		}
	}
}
#include "headers/moc_qtdice.cpp"
// kate: indent-mode cstyle; indent-width 8; replace-tabs off; tab-width 8; 
