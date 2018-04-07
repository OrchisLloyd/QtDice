#include "configure.h"
#include "ui_configure.h"

Configure::Configure(QWidget* parent) : QDialog(parent), configureUi(new Ui::Configure)
{
	configureUi->setupUi(this);
	
	//Make this window modal. No interaction with parent window is possible...
	this->setModal(true);
	//...until the user clicks OK and signal done is sent
	//connect(configureUi->OkButton, &QPushButton::clicked, this, &Configure::done);
}
