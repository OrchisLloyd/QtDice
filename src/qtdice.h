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

#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QPixmap>
#include <QImage>
#include <QIcon>
#include <QInputDialog>

#include "userwidget.h"

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

public slots:
	void enableUserWidget();
	void deleteUserWidget();

private slots :
	void reload();
	void reload(int num);
	void disableWidgets();
	void enableWidgets();
	void stop_last_frame(QMovie* movie);
	void aboutQtDice();

signals:
	void qmovieFrameChanged(QMovie* movie);
	bool reloaded_without_spinbox();
	bool dice_stopped_rolling();
	void userModeIsOn();
	void userModeIsOff();

protected:
	void keyPressEvent(QKeyEvent* e) override;

private:
	QScopedPointer<Ui::QtDice> qtdice_ui;
	QTranslator translator;
	UserWidget* userwidget;
	int spacerSize_x;
	int spacerSize_y;
	QPixmap image;
	QImage qimage;
	QMovie* movie;
	QSize windowSize;
};

#endif // QTDICE_H
