#include "usermenu.h"
#include <QDebug>

UserMenu::UserMenu(QSet<QString>* uniqueUserSet, QWidget* parent) :
	QWidget(parent),
	userUi(new Ui::UserMenu),
	rows(uniqueUserSet->size()),
	columns(2)
{
	userUi->setupUi(this);

	setAttribute(Qt::WA_DeleteOnClose, true);
	model = new QStandardItemModel(rows, columns, this);

//     userUi->delButton->setEnabled(false);
//     userUi->editButton->setEnabled(false);

	model->setHorizontalHeaderItem(0, new QStandardItem(QString(tr("User name"))));
	model->setHorizontalHeaderItem(1, new QStandardItem(QString(tr("Score"))));
	userUi->tableView->setModel(model);
	userUi->tableView->setShowGrid(true);
	//Stretch the horizontal header to fill the viewport
	userUi->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	//Use close with Qt::WA_DeleteOnClose in order to delete the non-parent widget
	connect(userUi->exitButton, &QPushButton::clicked, this, &UserMenu::close);
	connect(userUi->addButton, &QPushButton::clicked, this, &UserMenu::addElement);
	connect(userUi->editButton, &QPushButton::clicked, this, &UserMenu::editElement);

	QSet<QString>::iterator setIterator;
	int i = 0;

	for(setIterator = uniqueUserSet->begin(); setIterator != uniqueUserSet->end(); ++setIterator)
	{
		index = model->index(i, 0, QModelIndex());
		model->setData(index, *setIterator);
		++i;
	}

	connect(userUi->tableView, &QTableView::pressed, this, [this]()
	{
		tempColumn = index.column();
		tempRow = index.row();
	});
}

void UserMenu::addElement()
{
	bool ok;
	QString user = QInputDialog::getText(this, tr("Set user name"),
	                                     tr("User name"), QLineEdit::Normal,
	                                     "", &ok);

	if(ok && !user.isEmpty())
	{
		model->insertRow((rows + 1), QModelIndex());
		index = model->index((rows), 0, QModelIndex());
		model->setData(index, user);
	}
}

void UserMenu::editElement()
{
	bool ok;
	QString user = QInputDialog::getText(this, tr("Set name"),
	                                     tr(""), QLineEdit::Normal,
	                                     "", &ok);

	if(ok && !user.isEmpty())
	{
		index = model->index(tempRow, 0, QModelIndex());
		model->setData(index, user);
	}
}

UserMenu::~UserMenu()
{
	qDebug() << "Deleting user menu";
	delete userUi;
}
