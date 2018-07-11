/* Petros S <petross404@gmail.com>
 *
 * For more information about the license
 * take a look at ../License/GPL-3.txt
 *
 * This file defines a messagebox to show up
 * when the user clicks the "About QtDice" action.
 */

#include "../headers/about.h"

About::About(QWidget* parent)
        : QDialog(parent),
          m_name(new QString),
          pushButton(new QPushButton(tr("&Close"), this)),
          tabWidget(new QTabWidget(this)),
          gridLayout(new QGridLayout(this)),
          w_info(new QWidget(this)),
          w_contributions(new QWidget(this)),
          w_license(new QWidget(this)),
          w_thanks(new QWidget(this))
{
<<<<<<< HEAD
        //Make this window modal. No interaction with parent window is possible...
        setModal(true);
        //...until the user clicks OK and signal done is sent
        connect(pushButton.data(), &QPushButton::clicked, this, &About::done);

        setWindowTitle(QString(tr("About QtDice")));

        tabWidget->addTab(w_info.data(), tr("About"));
        tabWidget->addTab(w_contributions.data(), tr("Contributions"));
        tabWidget->addTab(w_license.data(), tr("License"));
        tabWidget->addTab(w_thanks.data(), tr("Thanks"));


        //about_ui->label_version_number->setText(QString("%1").arg(QtDice_VERSION));
        //about_ui->label_qt_version->setText(tr("Using Qt %1 (compiled with Qt %2)").arg(qVersion()).arg(QT_VERSION_STR));
        //about_ui->pushButton->setIcon(QIcon::fromTheme("answer"));

        //about_ui->label_email->setText("<a href=\"mailto:petross404@gmail.com\">petross404@gmail.com</a>");
        //about_ui->label_email->setTextFormat(Qt::RichText);
        //about_ui->label_email->setTextInteractionFlags(Qt::TextBrowserInteraction);
        //about_ui->label_email->setOpenExternalLinks(true);

        //about_ui->label_links_str->setText("<a href=\"https://github.com/Petross404/\">https://github.com/Petross404</a>");
        //about_ui->label_links_str->setTextFormat(Qt::RichText);
        //about_ui->label_links_str->setTextInteractionFlags(Qt::TextBrowserInteraction);
        //about_ui->label_links_str->setOpenExternalLinks(true);
=======
        about_ui->setupUi(this);

        //Make this window modal. No interaction with parent window is possible...
        setModal(true);
        //...until the user clicks OK and signal done is sent
        connect(about_ui->pushButton, &QPushButton::clicked, this, &About::done);

        setWindowTitle(QString(tr("About QtDice")));
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
>>>>>>> remotes/origin/no-ui

        QString license_text =
                ""
                "This program is free software; you can redistribute it and/or modify\n"
                "it under the terms of the GNU General Public License as published by\n"
                "the Free Software Foundation";
<<<<<<< HEAD
        ////about_ui->label_license_text->setTextFormat(Qt::RichText);
        //about_ui->label_license_text->setText(tr("This program is free software; you can redistribute it and/or modify\n"
        //"it under the terms of the GNU General Public License as published by\n"
        //"the Free Software Foundation"));

        //about_ui->label_thanks->setText(tr("Special thanks to my girlfriend, Aidonitsa, who tolerates my passion\n"
        //"and love for Qt/C++ and Gentoo Linux.\n\nWithout her, none of these would be possible."));

        //about_ui->tab_info->setAutoFillBackground(true);
        //about_ui->tab_contributions->setAutoFillBackground(true);
        //about_ui->tab_license->setAutoFillBackground(true);
        //about_ui->tab_thanks->setAutoFillBackground(true);
=======
        //about_ui->label_license_text->setTextFormat(Qt::RichText);
        about_ui->label_license_text->setText(tr("This program is free software; you can redistribute it and/or modify\n"
                                              "it under the terms of the GNU General Public License as published by\n"
                                              "the Free Software Foundation"));

        about_ui->label_thanks->setText(tr("Special thanks to my girlfriend, Aidonitsa, who tolerates my passion\n"
                                           "and love for Qt/C++ and Gentoo Linux.\n\nWithout her, none of these would be possible."));

        about_ui->tab_info->setAutoFillBackground(true);
        about_ui->tab_contributions->setAutoFillBackground(true);
        about_ui->tab_license->setAutoFillBackground(true);
        about_ui->tab_thanks->setAutoFillBackground(true);
>>>>>>> remotes/origin/no-ui
}

void About::show()
{
        QDialog::show();
}

void About::setName(QString name)
{
        this->setWindowTitle(tr(name.toLocal8Bit().constData()));
<<<<<<< HEAD
        *this->m_name = name;
=======
        this->m_name = name;
>>>>>>> remotes/origin/no-ui
}

void About::setAboutIcon(QString imageName)
{
        QPixmap image;
        Q_ASSERT_X(image.load(imageName), "This image couldn't be loaded", "Check for grammar errors");
<<<<<<< HEAD
        //about_ui->label_icon->setPixmap(image);
=======
        about_ui->label_icon->setPixmap(image);
>>>>>>> remotes/origin/no-ui
}

void About::setThanksText(QString thanksText)
{
<<<<<<< HEAD
        //about_ui->label_thanks->setText(thanksText);
=======
        about_ui->label_thanks->setText(thanksText);
>>>>>>> remotes/origin/no-ui
}

QString About::getName()
{
<<<<<<< HEAD
        return *this->m_name;
}

void About::setupLayouts()
{
=======
        return this->m_name;
>>>>>>> remotes/origin/no-ui
}

