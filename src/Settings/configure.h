#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QApplication>
#include <QDialog>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QWidget>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QDebug>
#include <QPixmap>
#include <QLabel>
#include <QtGlobal>
#include <QSettings>
#include <QCheckBox>

class Configure : public QDialog
{
	Q_OBJECT

public:
	explicit Configure(QWidget* parent);
	~Configure();

public slots:
	void show();

private slots:
	void writeSettings();

private:
	QScopedPointer<QDialogButtonBox> buttonBox;
	QScopedPointer<QLabel> labelIcon;
	QScopedPointer<QGroupBox> gridGroupBox, gridGroupBox_Icon;
	QScopedPointer<QGridLayout> gridLayout, grid_GeneralSettings, gridButtons, gridLabel;
	QScopedPointer<QPixmap> pixmapSettings;
	QScopedPointer<QSettings> settings;
	QScopedPointer<QCheckBox> soundCheckBox;
	QGroupBox* createGroupBox_General(), *createGroupBox_Icon();
	void readSettings();
};

#endif // CONFIGURE_H
