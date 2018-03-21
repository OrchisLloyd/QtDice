/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2018  <copyright holder> <email>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ui_userwidget.h"
#include "userwidget.h"
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>

UserWidget::UserWidget(QWidget* parent) :
	QWidget(parent),
	user_ui(new Ui::UserWidget)
{
	user_ui->setupUi(this);
	// Set up the buttons
	user_ui->addUserButton->setIcon(QIcon::fromTheme("list-add-user"));
	user_ui->delUserButton->setIcon(QIcon::fromTheme("list-remove-user"));
	connect(user_ui->addUserButton, &QPushButton::clicked, this, &UserWidget::addUser);
	connect(user_ui->delUserButton, &QPushButton::clicked, this, &UserWidget::delUser);
	connect(user_ui->userMenuButton, &QPushButton::clicked, this, &UserWidget::showUserMenu);
	connect(user_ui->challengeButton, &QPushButton::clicked, this, &UserWidget::showChallengeMenu);

	user_ui->comboBox->setDuplicatesEnabled(false);

	qtdiceDir = new QDir(QString("%1/.config/qtdice").arg(QDir::homePath()));

	if(!qtdiceDir->exists())
	{
		qDebug() << QString(tr("%1 doesn't exist, going to create")).arg(qtdiceDir->absolutePath());
		QDir().mkdir(qtdiceDir->absolutePath());
	}
}

void UserWidget::delUser()
{
	if(user_ui->comboBox->count())
	{
		user_ui->comboBox->removeItem(user_ui->comboBox->currentIndex());
	}
	else
	{
		QMessageBox::warning(this, tr("QtDice"),
		                     tr("Combobox is already empty"));
	}
}

void UserWidget::addUser()
{
	bool ok;
	QString user = QInputDialog::getText(this, tr("Set user name"),
	                                     tr("User name:"),
	                                     QLineEdit::Normal, "", &ok);

	if(ok && !user.isEmpty())
	{
		qDebug() << QString(tr("%1").arg(user));

		scoreFile = new QFile(QString("%1/%2.score").arg(qtdiceDir->absolutePath()).arg(user));

		if(!uniqueUserSet.contains(user))
		{
			uniqueUserSet.insert(user);
		}

		foreach(const QString& value, uniqueUserSet)
		{
			user_ui->comboBox->addItem(value);
		}
	}
}

void UserWidget::showUserMenu()
{
	userMenu = new UserMenu(&uniqueUserSet);
	userMenu->show();
}

void UserWidget::showChallengeMenu()
{
	challengeWindow = new Challenge(&uniqueUserSet);
	challengeWindow->show();
}

UserWidget::~UserWidget()
{
	qDebug() << "Deleting user widget";
	delete user_ui;
}
