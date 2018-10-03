/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 */

#ifndef ABOUT_H
#define ABOUT_H

#include "version.h"

#include <QApplication>
#include <QWidget>
#include <QDialog>
#include <QMainWindow>
#include <QScopedPointer>
#include <QString>
#include <QPixmap>
#include <QImage>
#include <QPushButton>
#include <QGridLayout>
#include <QTabWidget>

class About : public QDialog
{
	Q_OBJECT

public:
	About( QWidget *parent );

public slots:
//         void show();
//         void setName(QString name);
//         void setAboutIcon(QString imageName);
//         void setThanksText(QString thanksText);
//         QString getName();

private:
	QScopedPointer<QString> m_name;
	QScopedPointer<QPushButton> pushButton;
	QScopedPointer<QTabWidget> tabWidget;
	QScopedPointer<QGridLayout> gridLayout;
	QScopedPointer<QWidget> w_info, w_contributions, w_license, w_thanks;

	void setupLayouts();
};
#endif                                                      // ABOUT_H
