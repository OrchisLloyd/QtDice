#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QtCore/QDebug>
#include <QtCore/QScopedPointer>
#include <QtCore/QSettings>
#include <QtCore/QtGlobal>
#include <QtGui/QCloseEvent>
#include <QtGui/QPixmap>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

class Configure : public QDialog
{
    Q_OBJECT

public:
    explicit Configure ( QWidget *parent );
    ~Configure();

protected:
    virtual void closeEvent ( QCloseEvent *closeEv );
public slots:
    void show();

private slots:
    void writeSettings();
    bool isCheckBoxUnsaved();
signals:
    void checkBoxToggled();
    void soundCheckUnsaved();
private:
    QScopedPointer<QDialogButtonBox> buttonBox;
    QScopedPointer<QLabel> labelIcon;
    QScopedPointer<QGroupBox> gridGroupBox;
    QScopedPointer<QGroupBox> gridGroupBox_Icon;
    QScopedPointer<QGridLayout> gridLayout;
    QScopedPointer<QGridLayout> grid_GeneralSettings;
    QScopedPointer<QGridLayout> gridButtons;
    QScopedPointer<QGridLayout> gridLabel;
    QScopedPointer<QPixmap> pixmapSettings;
    QScopedPointer<QSettings> settings;
    QScopedPointer<QCheckBox> soundCheckBox;
    QGroupBox *createGroupBox_General();
    QGroupBox *createGroupBox_Icon();
    bool b_isSoundBoxUnSaved;
    void readSettings();
};

#endif // CONFIGURE_H
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
