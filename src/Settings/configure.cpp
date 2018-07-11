<<<<<<< HEAD
#include "../headers/configure.h"
=======
#include "configure.h"
>>>>>>> remotes/origin/no-ui
#include <QPushButton>

Configure::Configure(QWidget* parent)
        : QDialog(parent),
          buttonBox(new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Cancel)),
          gridGroupBox(new QGroupBox(tr("General Settings"), this)),
          labelIcon(new QLabel(static_cast<QDialog*>(this))),
          gridGroupBox_Icon(new QGroupBox(this)),
          gridLayout(new QGridLayout(this)),
          gridLabel(new QGridLayout(this)),
          grid_GeneralSettings(new QGridLayout(this)),
<<<<<<< HEAD
          pixmapSettings(new QPixmap(":/images/SettingsL.png")),
=======
          pixmapSettings(new QPixmap(":/resources/images/SettingsL.png")),
>>>>>>> remotes/origin/no-ui
          soundCheckBox(new QCheckBox("Play rolling sound?")),
          settings(new QSettings("QtDice")),
          gridButtons(new QGridLayout(this))
{
        //Make this window modal
        setModal(true);
        setWindowTitle(tr("QtDice Settings"));
        readSettings();

        // Add Apply button to buttonBox
        QPushButton* applyBtn = new QPushButton(tr("&Apply"), this);
        buttonBox->addButton(applyBtn, QDialogButtonBox::ApplyRole);

        connect(buttonBox.data(), &QDialogButtonBox::rejected, this, &Configure::reject);
        connect(buttonBox.data(), &QDialogButtonBox::accepted, this, &Configure::accept);
        connect(buttonBox.data(), &QDialogButtonBox::accepted, this, &Configure::writeSettings);
        connect(applyBtn, &QPushButton::clicked, this, &Configure::writeSettings);

        gridLayout->addWidget(createGroupBox_Icon(), 0, 0);
        gridLayout->addWidget(createGroupBox_General(), 0, 1);

        gridButtons->addWidget(buttonBox.data(), 0, 0);
        gridLayout->addLayout(gridButtons.data(), 1, 1);

// Disable sound-related widgets if the user doesn't need them
#ifndef ENABLE_SOUND
        soundCheckBox->setChecked(false);
        gridGroupBox->setEnabled(false);
#endif

        setMinimumSize(470, 250);
        setLayout(gridLayout.data());
}

Configure::~Configure()
{
        qDebug() << "Deleting configure UI";
}

void Configure::show()
{
        QDialog::show();
}

QGroupBox* Configure::createGroupBox_General()
{
        grid_GeneralSettings->addWidget(soundCheckBox.data(), 0, 0);
        gridGroupBox->setLayout(grid_GeneralSettings.data());
        return gridGroupBox.data();
}

QGroupBox* Configure::createGroupBox_Icon()
{
        labelIcon->setPixmap(*pixmapSettings.data());
        labelIcon->setScaledContents(true);
        labelIcon->setMaximumSize(100, 100);
        Q_ASSERT_X(labelIcon->pixmap() != 0, tr("labelIcon error"), tr("Fault"));

        gridLabel->addWidget(labelIcon.data(), 0, 0);
        gridGroupBox_Icon->setLayout(gridLabel.data());

        return gridGroupBox_Icon.data();
}

void Configure::readSettings()
{
        settings->beginGroup(tr("/sound"));
        settings->sync();
        soundCheckBox->setChecked(settings->value("rolling_sound").toInt());
        settings->endGroup();
}

void Configure::writeSettings()
{
        settings->beginGroup(tr("sound"));
        settings->setValue(tr("rolling_sound"), soundCheckBox->checkState());
        settings->sync();
        settings->endGroup();
}
