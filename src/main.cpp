/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 */

#include "qtdice.h"
#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

int main(int argc, char* argv[])
{
        QApplication app(argc, argv);
        QCommandLineParser parser;
        QCommandLineOption diceNumber(QStringList() << "n" << "number",
                                      QApplication::translate("Main",
                                                      "number that dice has to start with"), "number", "0");

        parser.addOption(diceNumber);
        parser.process(app);
        int number = QString("%1").arg(parser.value(diceNumber)).toInt();

        QtDice diceWindow(number);
        diceWindow.show();

        return app.exec();
}
