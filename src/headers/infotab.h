/*
 * <Information tab for About QtDice dialog>
 * Copyright (C) 2018  Πέτρος Σιλιγκούνας <petross404@gmail.com>
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
#ifndef INFOTAB_H
#define INFOTAB_H

#include <QtWidgets/QScopedPointer>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

class InfoTab : public QWidget
{
		Q_OBJECT
public:

		explicit InfoTab( QWidget *parent );

private:
		QScopedPointer<QGridLayout> gridLayout;
		QScopedPointer<QLabel> labelIcon, labelName, labelEmail, labelGithub, labelVersion;

};

#endif // INFOTAB_H
// kate: indent-mode cstyle; indent-width 8; replace-tabs off; tab-width 8; 
