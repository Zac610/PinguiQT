#include "ConfDialog.h"
#include "ui_ConfDialog.h"

ConfDialog::ConfDialog(QWidget *parent) :
		QDialog(parent), ui(new Ui::ConfDialog)
{
	ui->setupUi(this);
}

ConfDialog::~ConfDialog() { delete ui; }

void ConfDialog::on_pushButton_2_clicked() { QApplication::quit(); }

void ConfDialog::on_pushButton_3_clicked() { close(); }
