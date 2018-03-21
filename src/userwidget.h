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

#ifndef USERWIDGET_H
#define USERWIDGET_H
#include "usermenu.h"
#include "challenge.h"

#include <QWidget>
#include <QString>
#include <QSet>

# include <QDir>
# include <QFile>

namespace Ui
{
class UserWidget;
}

class UserWidget : public QWidget
{
	Q_OBJECT

public:
	explicit UserWidget(QWidget* parent = nullptr);
	~UserWidget();
	QString name() const;

public slots:
	void addUser();
	void delUser();
	void showUserMenu();
	void showChallengeMenu();


private:
	Ui::UserWidget* user_ui;
	QSet<QString> uniqueUserSet;
	QDir* qtdiceDir;
	QFile* scoreFile;
	UserMenu* userMenu;
	Challenge* challengeWindow;
};

#endif // USERWIDGET_H
