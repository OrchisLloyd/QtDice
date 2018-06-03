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
# include "qtheaders.h"
#include <iostream>

#include <QMainWindow>
#include <QApplication>

class QtDice : public QMainWindow
{
        Q_OBJECT

public:

        QtDice(int number);
        ~QtDice();

        void animate_dice();
        void image_update(int image_num);

public slots:
#ifdef USER_MODE
        void enableUserWidget();
        void deleteUserWidget();
#endif

private slots:
        void reload();
        void reload(int num);
        void disableWidgets();
        void enableWidgets();
        void stop_last_frame(QMovie* movie);
        void aboutQtDice();
        void QtDiceConfiguration();
        void printWarning();

signals:
        void qmovieFrameChanged(QMovie* movie);
        bool reloaded_without_spinbox();
        bool dice_stopped_rolling();
# ifdef USER_MODE
        void userModeIsOn();
        void userModeIsOff();
# endif

protected:
        void keyPressEvent(QKeyEvent* e) override;

private:
        QScopedPointer<QPushButton> btn_roll, btn_exit;
        QScopedPointer<QWidget> central_Widget;
        QScopedPointer<QGridLayout> gridLayout, gridLabel, gridStatus, gridWarning;
        QScopedPointer<QSettings> settings;
        QTranslator translator;
        int diceNumber;
        QScopedPointer<QPixmap> image;
        QImage qimage;
        QScopedPointer<QIcon> qtdiceIcon, exitIcon;
        QScopedPointer<QMovie> movie;
        QSize windowSize;
        QScopedPointer<QLabel> label, label_status, label_warning;
        QMenu* menuFile, *menuEdit, *menuAbout;
        QScopedPointer<QAction> actionRoll_the_dice, actionQuit, actionConfigure, actionAboutQt, actionAbout;
        QScopedPointer<QSpinBox> spinBox;
        QSpacerItem* spacer_a, *spacer_b;

        void createMenus();
        void setupWidgets();
        void setupLayouts();
        bool isSoundEnabled();

# ifdef ENABLE_SOUND
        QSoundEffect roll_sound;
# endif
# ifdef USER_MODE
        UserWidget* userwidget;
        QCheckBox* checkBox;
# endif
        // Making an dynamic object of type Dice, will help upon creating one
        // only when the programm is first run by checking if it already exists.
        QScopedPointer<Dice> pDice;
};

#endif               // QTDICE_H
