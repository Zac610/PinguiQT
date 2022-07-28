#include "MainForm.h"
#include "ui_MainForm.h"

MainForm::MainForm(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
	ui->setupUi(this);
	mModel = new NodeModel();
	ui->tableView->setModel(mModel);
}

MainForm::~MainForm()
{
	delete mModel;
	delete ui;
}
