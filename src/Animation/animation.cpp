#include "../headers/animation.h"
#include <qevent.h>
#include <QCloseEvent>

Animation::Animation( QWidget *parent )
	: QLabel( parent )
	, label( new QLabel )
	, movie( new QMovie( ":resources/images/bluedice.gif" ) )
	, image( new QPixmap( ":/resources/images/dice.png" ) )
	, pDice( Dice::instance() )
{
	label->setPixmap( QPixmap( ":/resources/images/128-apps-dice.png" ) );
	label->setBackgroundRole( QPalette::Base );
	label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
	label->setScaledContents( true );
	label->setFrameStyle( QFrame::StyledPanel | QFrame::Raised );
	label->setLineWidth( 2 );
}

Animation::~Animation() = default;

void Animation::createActions()
{
	reloadAct.reset( new QAction( tr( "Reload" ), this ) );
	connect( reloadAct.data(), &QAction::triggered,
		 this, &Animation::reload );
}

void Animation::reload()
{
	label->setMovie( movie.data() );

	//Just to make sure that movie has a valid type or exit
	if ( movie->isValid() ) { movie->start(); }
	else
	{
		QString animationError {"Animation type is not supported! Did you forget to include *.qrc file?"};
		label->setText( tr( animationError.toLocal8Bit().constData() ) );
		QMessageBox::critical( this, tr( "Error" ), tr( animationError.toLocal8Bit().constData() ) );
	}

	pDice->roll();
}

void Animation::setupConnectionsOfAnimation()
{
	// When animation starts, disable spinBox, the buttons etc...
	//connect( movie.data(), &QMovie::started, this, &Animation::disableWidgets );

	//Thanks to the guys at this thread :
	//https://forum.qt.io/topic/88197/custom-signal-to-slot-the-slot-requires-more-arguments-than-the-signal-provides
	connect( movie.data(), &QMovie::frameChanged,
		 this, std::bind( &Animation::qmovieFrameChanged, this, movie.data() ) );

	connect( this, &Animation::qmovieFrameChanged, this, &Animation::stopLastQMovieFrame );

	// When movie is finished, re-enable spinBox, buttons etc
	//connect( movie.data(), &QMovie::finished, this, &Animation::enableWidgets );
	//
}

void Animation::setupConnectionsOfReload()
{
	connect( movie.data(), &QMovie::frameChanged, this,
		 [ = ]()
	{
// 			 if ( movie->state() == QMovie::NotRunning )
// 			 {
// 				 spinBox->blockSignals( true );
// 				 spinBox->setValue( imageNumber );
// 				 spinBox->blockSignals( false );
// 			 }
	} );
}

// Check if the frame is the last one and stop the dice animation
void Animation::stopLastQMovieFrame( QMovie *movie )
{
	if ( movie->currentFrameNumber() == ( movie->frameCount() - 1 ) )
	{
		movie->stop();

		//Explicity emit finished signal
		//https://bugreports.qt.io/browse/QTBUG-66733
		if ( movie->state() == QMovie::NotRunning )
		{
			emit movie->finished();
// 			labelStatus->setText( tr( "Ready" ) );
// 			spinBox->setEnabled( true );
		}
	}
}

// This function declares image_update(int image_number)
// This function accepts an image_number which is already have been
// generated randomly in Dice class members. Based on image_number it
// selects the proper dice image to show
void Animation::imageUpdate( int imageNumber )
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


void Animation::contextMenuEvent( QContextMenuEvent *event )
{
	switch ( event->reason() )
	{
	case QContextMenuEvent::Mouse:
		event->accept();
	default:
		QMenu menu;
		menu.addAction( reloadAct.data() );
		menu.exec( event->globalPos() );
	}
}
