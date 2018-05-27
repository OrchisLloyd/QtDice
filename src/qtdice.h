/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 */

#ifndef QTDICE_H
#define QTDICE_H
#include "ui_qtdice.h"

#include "Dice/dice.hpp"
#include "version.h"
#include "qtdiceGuiElements.h"
#include <iostream>

#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>

#include <QString>
#include <QImage>
#include <QDir>
#include <QFile>
#include <QMovie>
#include <QTranslator>
#include <QScopedPointer>
#include <QtGlobal>

#ifdef ENABLE_SOUND
#include <QtMultimedia/QSound>
#include <QtMultimedia/QMediaPlayer>
#include <QUrl>
#include <QtMultimedia/QSoundEffect>
#endif

#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QPixmap>
#include <QImage>
#include <QIcon>
#include <QInputDialog>

#ifdef USER_MODE
#include "userwidget.h"
#include <QCheckBox>
#endif

namespace Ui
{
class QtDice;
}

class QtDice : public QMainWindow
{
        Q_OBJECT

public:
        QtDice();

        void animate_dice();
        void image_update(int image_num);

# ifdef USER_MODE
public slots:
        void enableUserWidget();
        void deleteUserWidget();
#endif

private slots :
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
#ifdef USER_MODE
        void userModeIsOn();
        void userModeIsOff();
#endif

protected:
        void keyPressEvent(QKeyEvent* e) override;

private:
        QScopedPointer<Ui::QtDice> qtdice_ui;
        QPushButton* btn_roll, *btn_exit;
        QWidget* centralWidget;
        QGridLayout* gridLayout, *gridLabel, *gridStatus, *gridWarning;
        QTranslator translator;
        int spacerSize_x;
        int spacerSize_y;
        QPixmap* image;
        QImage qimage;
        QIcon* qtdiceIcon, *exitIcon;
        QMovie* movie;
        QSize windowSize;
        QLabel* label, *label_status, *label_warning;
        QMenu* menuFile, *menuEdit, *menuAbout;
        QAction* actionRoll_the_dice, *actionQuit, *actionConfigure, *actionAboutQt, *actionAbout;
        QSpinBox* spinBox;
        QSpacerItem* spacer_a, *spacer_b;

        void createMenus();
        void instantiate();
        void setupWidgets();
        void setupLayouts();

#ifdef ENABLE_SOUND
        QSoundEffect roll_sound;
#endif
# ifdef USER_MODE
        UserWidget* userwidget;
        QCheckBox* checkBox;
# endif
// Making an dynamic object of type Dice, will help upon creating one
// only when the programm is first run by checking if it already exists.
        Dice* pDice = nullptr;
};

#endif // QTDICE_H
