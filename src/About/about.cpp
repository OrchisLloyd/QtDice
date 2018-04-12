/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 * This file defines a messagebox to show up
 * when the user clicks the "About QtDice" action.
 */

#include "about.h"

About::About(QWidget* parent) : QDialog(parent), about_ui(new Ui::About)
{
	about_ui->setupUi(this);

	//Make this window modal. No interaction with parent window is possible...
	this->setModal(true);
	//...until the user clicks OK and signal done is sent
	connect(about_ui->pushButton, &QPushButton::clicked, this, &About::done);

	this->setWindowTitle(QString(tr("About QtDice")));
	about_ui->label_version_number->setText(QString("%1").arg(QtDice_VERSION));
	about_ui->label_qt_version->setText(tr("Using Qt %1 (compiled with Qt %2)").arg(qVersion()).arg(QT_VERSION_STR));
	about_ui->pushButton->setIcon(QIcon::fromTheme("answer"));

	about_ui->label_email->setText("<a href=\"mailto:petross404@gmail.com\">petross404@gmail.com</a>");
	about_ui->label_email->setTextFormat(Qt::RichText);
	about_ui->label_email->setTextInteractionFlags(Qt::TextBrowserInteraction);
	about_ui->label_email->setOpenExternalLinks(true);

	about_ui->label_links_str->setText("<a href=\"https://github.com/Petross404/\">https://github.com/Petross404</a>");
	about_ui->label_links_str->setTextFormat(Qt::RichText);
	about_ui->label_links_str->setTextInteractionFlags(Qt::TextBrowserInteraction);
	about_ui->label_links_str->setOpenExternalLinks(true);

	QString license_text =
	    ""
	    "This program is free software; you can redistribute it and/or modify\n"
	    "it under the terms of the GNU General Public License as published by\n"
	    "the Free Software Foundation";
	//about_ui->label_license_text->setTextFormat(Qt::RichText);
	about_ui->label_license_text->setText(tr("This program is free software; you can redistribute it and/or modify\n"
	                                      "it under the terms of the GNU General Public License as published by\n"
	                                      "the Free Software Foundation"));

	about_ui->label_thanks->setText(tr("Special thanks to my girlfriend Aidonitsa, who tolerates my passion"
	                                   "and love for Qt/C++ and Gentoo Linux.\n\nWithout her, none of these would be possible."));
	about_ui->label_thanks->setWordWrap(true);

	about_ui->tab_info->setAutoFillBackground(true);
	about_ui->tab_contributions->setAutoFillBackground(true);
	about_ui->tab_license->setAutoFillBackground(true);
	about_ui->tab_thanks->setAutoFillBackground(true);
}

void About::show()
{
	QDialog::show();
}

void About::setName(QString name)
{
	this->setWindowTitle(tr(name.toLocal8Bit().constData()));
	this->m_name = name;
}

void About::setAboutIcon(QString imageName)
{
	QPixmap image;
	Q_ASSERT_X(image.load(imageName), "This image couldn't be loaded", "Check for grammar errors");
	about_ui->label_icon->setPixmap(image);
}

void About::setThanksText(QString thanksText)
{
	about_ui->label_thanks->setText(thanksText);
}

QString About::getName()
{
	return this->m_name;
}
