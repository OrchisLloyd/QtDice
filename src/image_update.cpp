/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 * This file declares image_update(int image_number)
 * What this function does, is that it accepts an image_number
 * which is generated randomly in Dice class members and based
 * on this integer it selects the proper dice image to show
 */

#include "qtdice.h"

void QtDice::image_update(int image_number)
{
	//Now deal with which image will be loaded based on image_number
	//The whole point of this program is here
	QString image_name {":/images/dice-%1.png"};

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
