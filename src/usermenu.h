#ifndef USERMENU_H
#define USERMENU_H

#include <QWidget>
#include <QInputDialog>
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QHeaderView>

#include "ui_usermenu.h"

namespace Ui
{
class UserMenu;
}

class UserMenu : public QWidget
{
	Q_OBJECT

public:
	explicit UserMenu(QSet<QString>* uniqueUserSet, QWidget* parent = nullptr);
	~UserMenu();

public slots:
	void addElement();
	void editElement();

private:
	Ui::UserMenu* userUi;
	QStandardItemModel* model;
	QModelIndex index;
	int rows, columns;
	int tempRow, tempColumn;
};

#endif // USERMENU_H
