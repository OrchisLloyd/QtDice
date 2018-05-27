#include "configure.h"
#include "ui_configure.h"
#include <QPushButton>

Configure::Configure(QWidget* parent)
        : QDialog(parent),
          buttonBox(new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Cancel)),
          gridGroupBox(new QGroupBox(tr("General Settings"), this)),
          gridLayout(new QGridLayout(this)),
          grid_GeneralSettings(new QGridLayout(this)),
          gridButtons(new QGridLayout(this)), 
#ifdef ENABLE_SOUND
          soundCheckBox(new QCheckBox(tr("Enable sound when rolling"), this)),
#endif
          central_Widget(new QWidget(this))
{
        //Make this window modal
        setModal(true);

        connect(buttonBox.data(), &QDialogButtonBox::rejected, this, &Configure::reject);
        connect(buttonBox.data(), &QDialogButtonBox::accepted, this, &Configure::accept);

        gridLayout->addWidget(gridGroupBox.data(), 0, 0);
        gridLayout->addWidget(buttonBox.data(), 1, 0);
        gridButtons->addWidget(buttonBox.data(), 0, 0);
        gridLayout->addLayout(gridButtons.data(), 1, 0);
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
#ifdef ENABLE_SOUND
        grid_GeneralSettings->addWidget(soundCheckBox, 0, 0);
#endif
        //grid_GeneralSettings->addWidget(buttonBox.data(), 0, 0);

        gridGroupBox->setLayout(grid_GeneralSettings.data());
        return gridGroupBox.data();
}
