/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 */

#ifndef QTDICE_H
#define QTDICE_H

#include "Dice/dice.hpp"
#include "version.h"
#include "qtheaders.h"
#include <iostream>

#include <QtCore/QLoggingCategory>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QtWidgets/QAction>

Q_DECLARE_LOGGING_CATEGORY(LOG_QTDICE)

class QtDice : public QMainWindow
{

    Q_OBJECT

public:

    QtDice(int number, QWidget *parent = nullptr);

    void animateDice();
    void imageUpdate(int image_num);

private slots:
    void aboutQtDice();
    void reload();
    void reload(int num);
    void resetQtDice();
    void disableWidgets();
    void enableWidgets();
    void stopLastQMovieFrame(QMovie *movie);
    void QtDiceConfiguration();
    void printWarning();
    void printNumberOfRolls();

signals:
    void qmovieFrameChanged(QMovie *movie);
    bool isReloadedWithoutSpinbox();
    bool isNumberOfRollsIncremented(bool answer);

protected:
    void keyPressEvent(QKeyEvent *e) override;

private:
    QScopedPointer<QPushButton> btnRoll;
    QScopedPointer<QPushButton> btnReset;
    QScopedPointer<QPushButton> btnQuit;
    QScopedPointer<QWidget> widgetCentral;
    QScopedPointer<QGridLayout> gridLayout;
    QScopedPointer<QGridLayout> gridLabel;
    QScopedPointer<QGridLayout> gridStatus;
    QScopedPointer<QGridLayout> gridReset;
    QScopedPointer<QGridLayout> gridWarning;
    QScopedPointer <QSettings> settings;
    QTranslator translator;
    int diceNumber, numberOfRolls;
    QScopedPointer <QPixmap> image;
    QImage qimage;
    QScopedPointer<QIcon> qtdiceIcon;
    QScopedPointer<QIcon> exitIcon;
    QScopedPointer<QMovie> movie;
    QScopedPointer<QLabel> label;
    QScopedPointer<QLabel> labelStatus;
    QScopedPointer<QLabel> labelWarning;
    QScopedPointer<QLabel> labelNumberofRolls;
    QScopedPointer<QMenu> menuFile;
    QScopedPointer<QMenu> menuEdit;
    QScopedPointer<QMenu> menuAbout;
    QScopedPointer<QAction> actionRoll;
    QScopedPointer<QAction> actionQuit;
    QScopedPointer<QAction> actionReset;
    QScopedPointer<QAction> actionConfigure;
    QScopedPointer<QAction> actionAboutQt;
    QScopedPointer<QAction> actionAbout;
    QScopedPointer<QAction> actionSettings;
    QScopedPointer<QSpinBox> spinBox;

    void createMenus();
    void setupWidgets();
    void setupLayouts();
    bool isSoundEnabled();

#ifdef ENABLE_SOUND
    QSoundEffect roll_sound;
#endif

    // Making an dynamic object of type Dice, will help upon creating one
    // only when the programm is first run by checking if it already exists.
    QScopedPointer<Dice> pDice;
};

#endif				// QTDICE_H
