#ifndef CONFDIALOG_H
#define CONFDIALOG_H

#include "NodeModel.h"

#include <QDialog>

namespace Ui
{
	class ConfDialog;
}

class ConfDialog : public QDialog
{
	Q_OBJECT

public:
	explicit ConfDialog(QWidget *parent = 0);
	~ConfDialog();

	NodeModel *mModel;

private slots:
	void on_pushButton_2_clicked();

	void on_pushButton_clicked();

private:
	Ui::ConfDialog *ui;
};

#endif // CONFDIALOG_H
