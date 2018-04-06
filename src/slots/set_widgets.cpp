#include "../qtdice.h"

void QtDice::disableWidgets()
{
	//Now that movie is started, set the following...
	qtdice_ui->m_button_quit->setFocus();
	qtdice_ui->action_Roll_the_dice->setEnabled(false);
	qtdice_ui->m_button->setEnabled(false);
	//...also set the QLabel's that show the status
	label_status->setText(tr("Rolling..."));
	qtdice_ui->spinBox->setEnabled(false);
}

void QtDice::enableWidgets()
{
	qtdice_ui->label->setPixmap(image);
	qtdice_ui->label->show();
	qtdice_ui->m_button->setEnabled(true);
	qtdice_ui->m_button->setFocus();
	qtdice_ui->action_Roll_the_dice->setEnabled(true);

	emit dice_stopped_rolling();
}
