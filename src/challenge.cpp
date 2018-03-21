#include "challenge.h"
#include "ui_challenge.h"
#include <QDebug>

Challenge::Challenge(QSet<QString>* uniqueUserSet, QWidget* parent) :
	QWidget(parent),
	challenge_ui(new Ui::Challenge)
{
	challenge_ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);

	foreach(const QString& value, *uniqueUserSet)
	{
		challenge_ui->comboBox->addItem(value);
	}

	connect(challenge_ui->exitButton, &QPushButton::clicked, this, &Challenge::close);
}

Challenge::~Challenge()
{
	qDebug() << "deleting challenge menu";
	delete challenge_ui;
}
