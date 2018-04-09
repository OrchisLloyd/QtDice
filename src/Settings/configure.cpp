#include "configure.h"
#include "ui_configure.h"

Configure::Configure(QWidget* parent) : QDialog(parent), configureUi(new Ui::Configure)
{
	configureUi->setupUi(this);

	//Make this window modal
	setModal(true);

	gridGroupBox = new QGroupBox(tr("General Settings"), this);
	gridLayout = new QGridLayout(this);
	gridGroupBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	gridLayout_GeneralSettings = new QGridLayout;
	buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
	                                 | QDialogButtonBox::Cancel);
	connect(buttonBox, &QDialogButtonBox::accepted, this, &Configure::accept);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &Configure::reject);
	buttonBox->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
	gridLayout->addWidget(gridGroupBox, 0, 0);
	gridLayout->addWidget(buttonBox, 0, Qt::AlignRight);

#ifdef ENABLE_SOUND
	qDebug() << "Ok";
	create_generalSettings();
#endif
	setLayout(gridLayout);
}

Configure::~Configure()
{
	qDebug() << "Deleting configure UI";
	delete configureUi;
}

void Configure::show()
{
	QDialog::show();
}

void Configure::create_generalSettings()
{
	//gridLayout->addLayout(gridLayout_GeneralSettings, 0, 0);
#ifdef ENABLE_SOUND
	//soundCheckBox = new QCheckBox(tr("&Enable sound when rolling?"), this);
	//gridLayout_GeneralSettings->addWidget(soundCheckBox);
#endif
}

#ifdef ENABLE_SOUND
void Configure::createSoundMenu()
{
}
#endif
