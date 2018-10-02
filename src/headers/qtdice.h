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
#include <iostream>

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

Q_DECLARE_LOGGING_CATEGORY( LOG_QTDICE )

class QtDice : public QMainWindow
{
	Q_OBJECT

public:
	QtDice( int number, QWidget *parent = nullptr );
	~QtDice();

	void animateDice();
	void imageUpdate( int image_num );

private slots:
	//void aboutQtDice();
	void reload();
	void reload( int num );
	void resetQtDice();
	void disableWidgets();
	void enableWidgets();
	void stopLastQMovieFrame( QMovie *movie );
	void QtDiceConfiguration();
	void printWarning();

signals:
	void qmovieFrameChanged( QMovie *movie );
	bool isNumberOfRollsIncremented( bool answer );

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
// kate: indent-mode cstyle; indent-width 8; replace-tabs off; tab-width 8; 