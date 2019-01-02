/* Petros S <petross404@gmail.com>
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 */

#ifndef QTDICE_H
#define QTDICE_H

#include "Dice/dice.hpp"
#include "version.h"
#include <iostream>

#include <Qt>
#include <QtCore/Qthread>
#include <QtCore/QLoggingCategory>
#include <QtCore/QSettings>
#include <QtCore/QStandardPaths>
#include <QtGui/QMovie>
#include <QtWidgets/QAction>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QShortcut>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMessageBox>

#ifdef  ENABLE_SOUND
#include <QtMultimedia/QSoundEffect>
#endif

Q_DECLARE_LOGGING_CATEGORY ( LOG_QTDICE )

class QtDice : public QMainWindow
{
    Q_OBJECT
public:
    QtDice ( int number, QWidget *parent = nullptr );
    ~QtDice();

    void animateDice();
    void imageUpdate ( int imageNumber );

private slots:
    //void aboutQtDice();
    void reload();
    void reload ( int num );
    void resetQtDice();
    void disableWidgets();
    void enableWidgets();
    void stopLastQMovieFrame ( QMovie *movie );
    void QtDiceConfiguration();

signals:
    void qmovieFrameChanged ( QMovie *movie );
    bool isNumberOfRollsIncremented ( bool answer );

private:
    int diceNumber;
    QScopedPointer<QPushButton> btnRoll;
    QScopedPointer<QPushButton> btnReset;
    QScopedPointer<QPushButton> btnQuit;
    QScopedPointer<QWidget> widgetCentral;
    QScopedPointer<QGridLayout> gridLayout;
    QScopedPointer<QGridLayout> gridLabel;
    QScopedPointer<QGridLayout> gridStatus;
    QScopedPointer<QGridLayout> gridWarning;
    QScopedPointer <QSettings> settings;
    int numberOfRolls;
    QScopedPointer <QPixmap> image;
    QImage qimage;
    QScopedPointer<QIcon> qtdiceIcon;
    QScopedPointer<QIcon> exitIcon;
    QScopedPointer<QMovie> movie;
    QScopedPointer<QLabel> label;
    QScopedPointer<QLabel> labelStatus;
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
    QScopedPointer<QShortcut> quitShortCut;
    QThread *thread;
    int imageNumber;

    void createMenus();
    void setupWidgets();
    void setupLayouts();
    void setupConnections();
    void setupConnectionsOfAnimation();
    void setupConnectionsOfReload();
    bool isSoundEnabled();

#ifdef ENABLE_SOUND
    QSoundEffect roll_sound;
#endif

    Dice *pDice;
};

#endif				// QTDICE_H
// kate: indent-mode cstyle; replace-tabs on; 
