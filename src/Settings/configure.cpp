#include "configure.h"
#include "ui_configure.h"

Configure::Configure(QWidget* parent) : QDialog(parent), configureUi(new Ui::Configure)
{
	configureUi->setupUi(this);

	//Make this window modal
	setModal(true);

	gridGroupBox = new QGroupBox(tr("General Settings"), this);
	gridLayout = new QGridLayout(this);
	gridLayout_GeneralSettings = new QGridLayout(this);
	buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
	                                 | QDialogButtonBox::Cancel);
	connect(buttonBox, &QDialogButtonBox::accepted, this, &Configure::accept);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &Configure::reject);
	gridLayout->addWidget(buttonBox);
	gridLayout->setSpacing(2);
	gridLayout->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	
	

#ifdef ENABLE_SOUND
	qDebug() << "Ok";
	create_generalSettings();
	//createSoundMenu();
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
	gridLayout->addLayout(gridLayout_GeneralSettings, 0, 0);
#ifdef ENABLE_SOUND
	soundCheckBox = new QCheckBox(tr("&Enable sound when rolling?"), this);
	gridLayout_GeneralSettings->addWidget(soundCheckBox);
#endif
}

#ifdef ENABLE_SOUND
void Configure::createSoundMenu()
{
}
#endif
