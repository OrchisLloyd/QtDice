#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <QDialog>
#include <QScopedPointer>

namespace Ui
{
class Configure;
}

class Configure : public QDialog
{
	Q_OBJECT

public:
	explicit Configure(QWidget* parent);
	//~Configure();

public slots:
	void show();

private:
	QScopedPointer<Ui::Configure> configureUi;
};

#endif // CONFIGURE_H
