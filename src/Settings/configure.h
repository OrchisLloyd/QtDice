#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QDialog>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QWidget>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QDebug>

#ifdef ENABLE_SOUND
#include <QCheckBox>
#endif

class Configure : public QDialog
{
        Q_OBJECT

public:
        explicit Configure(QWidget* parent);
        ~Configure();

public slots:
        void show();

private:
        QScopedPointer<QDialogButtonBox> buttonBox;
        QScopedPointer<QGroupBox> gridGroupBox;
        QScopedPointer<QGridLayout> gridLayout, grid_GeneralSettings, gridButtons;
        QGroupBox* createGroupBox_General();
#ifdef ENABLE_SOUND
        QCheckBox* soundCheckBox;
#endif
};

#endif // CONFIGURE_H
