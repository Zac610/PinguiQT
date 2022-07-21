#include "widget.h"
#include "ui_widget.h"
#include "NodeModel.h"

NodeModel gModel;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableView->setModel(&gModel);
}

Widget::~Widget()
{
    delete ui;
}

