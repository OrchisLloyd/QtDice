#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QDialog>
#include <QScopedPointer>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QDebug>

#ifdef ENABLE_SOUND
#include <QCheckBox>
#endif

namespace Ui
{
class Configure;
}

class Configure : public QDialog
{
	Q_OBJECT

public:
	explicit Configure(QWidget* parent);
	~Configure();

public slots:
	void show();
// #ifdef ENABLE_SOUND
// 	void createSoundMenu();
// #endif
// 	void create_generalSettings();

private:
	//QScopedPointer<Ui::Configure> configureUi;
	Ui::Configure* configureUi;
	QDialogButtonBox* buttonBox;
	QGroupBox* gridGroupBox;
	QGridLayout* gridLayout;
	QGridLayout* gridLayout_GeneralSettings;
#ifdef ENABLE_SOUND
	QCheckBox* soundCheckBox;
#endif
};

#endif // CONFIGURE_H
