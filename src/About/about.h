/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 */

#ifndef ABOUT_H
#define ABOUT_H
#include "ui_about.h"

#include "../version.h"

#include <QApplication>
#include <QWidget>
#include <QDialog>
#include <QMainWindow>
#include <QScopedPointer>
#include <QString>
#include <QPixmap>
#include <QImage>

namespace Ui
{
class About;
} class About: public QDialog
{
Q_OBJECT public:
	About( QWidget *parent );

public slots:
	void show();
	void setName( QString name );
	void setAboutIcon( QString imageName );
	void setThanksText( QString thanksText );
	QString getName();

private:
	QScopedPointer < Ui::About > about_ui;
	QString m_name;
};
#endif
// kate: indent-mode cstyle; indent-width 8; replace-tabs off; tab-width 8; 
