/* Petros S <petross404@gmail.com>
*
* For more information about the license
* take a look at ../License/GPL-3.txt
*
* Before showing the image, it plays a small animation of
* a dice that is rolling for enhanced user experience
*/

#include "qtdice.h"

void QtDice::animate_dice()
{
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
		movie->setFileName(":images/bluedice.gif");
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
