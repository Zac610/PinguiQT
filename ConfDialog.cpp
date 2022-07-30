#include "ConfDialog.h"
#include "ui_ConfDialog.h"

ConfDialog::ConfDialog(QWidget *parent) :
		QDialog(parent), ui(new Ui::ConfDialog)
{
	ui->setupUi(this);
	setWindowFlag(Qt::CustomizeWindowHint);
	move(QCursor::pos().x() - width() / 2, QCursor::pos().y() - height() / 2);
}

ConfDialog::~ConfDialog() { delete ui; }

void ConfDialog::on_pushButton_2_clicked() { QApplication::quit(); }

void ConfDialog::on_pushButton_clicked()
{
	QString nodeName = ui->lineEdit->text();
	if (!nodeName.isEmpty())
		mModel->AddElement(nodeName);
}
