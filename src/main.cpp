/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 */

#include "qtdice.h"
#include <QApplication>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	QtDice diceWindow;
	diceWindow.show();

	return app.exec();
}

