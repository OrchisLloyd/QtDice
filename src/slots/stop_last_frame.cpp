/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 * This file defines the public slot stop_last_frame. What it does is
 * that it checks at every frame of the gif, if it's the last so that
 * the animation stopes right there
 *
 */

#include "../qtdice.h"

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
			this->label_status->setText(tr("Stopped"));
			qtdice_ui->spinBox->setEnabled(true);
		}
	}
}
