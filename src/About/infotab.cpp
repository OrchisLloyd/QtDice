/*
 * <one line to give the program's name and a brief idea of what it does.>
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

#include "../../headers/infotab.h"

InfoTab::InfoTab(QWidget* parent)
        : QWidget(parent),
          gridLayout(new QGridLayout(this)),
          labelIcon(new QLabel("images/dice.png", this)),
          labelName(new QLabel(tr("Petross404"), this)),
          labelEmail(new QLabel(tr("<petross404@gmail.com>"), this)),
          labelGithub(new QLabel(tr(""), this)),
          labelVersion(new QLabel(tr(""), this))
{
        gridLayout->addWidget(labelIcon.data(), 0, 0);
        gridLayout->addWidget(labelName.data(), 0, 1);
        gridLayout->addWidget(labelVersion.data(), 1, 1);
        gridLayout->addWidget(labelEmail.data(), 2, 1);
        gridLayout->addWidget(labelGithub.data(), 3, 1);

        setLayout(gridLayout.data());
}
