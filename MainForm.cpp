#include "MainForm.h"
#include "ui_MainForm.h"

#include <QDebug>

#include <iostream>

MainForm::MainForm(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
	ui->setupUi(this);
	mModel = new NodeModel();
	ui->tableView->setModel(mModel);
	ui->tableView->setMouseTracking(true);
	ui->tableView->viewport()->installEventFilter(this);
	//	connect(ui->tableView, &MainForm::mousePressEvent, this,
	//					&MainForm::mousePressed);
}

MainForm::~MainForm()
{
	delete mModel;
	delete ui;
}

bool MainForm::eventFilter(QObject *obj, QEvent *event)
{
	std::cout << event->type() << std::endl;
	if (event->type() == QEvent::MouseButtonRelease)
	{
		std::cout << "Mouse Released" << std::endl;
	}
	else if (event->type() == QEvent::MouseButtonPress)
	{
		std::cout << "Mouse Pressed" << std::endl;
	}
	return false;
}

// void MainForm::mousePressEvent(QMouseEvent *event)
//{
//	std::cout << "mousePressEvent" << std::endl;
//	const QPoint &punkt = event->pos();
//	emit mousePressed(punkt);
//}

// void MainForm::mouseReleaseEvent(QMouseEvent *event)
//{
//	std::cout << "mouseReleaseEvent" << std::endl;
//}

// void MainForm::mouseMoveEvent(QMouseEvent *event)
//{
//	std::cout << "mouseMoveEvent" << std::endl;
//	qDebug() << QString::number(event->pos().x());
//	qDebug() << QString::number(event->pos().y());
//}

// void MainForm::mousePressed(const QPoint &pos)
//{
//	std::cout << "mousePressed" << std::endl;
//	qDebug() << pos;
//}

// void MainForm::on_tableView_pressed(const QModelIndex &index)
//{
//	// QDesktopWidget *widget           = QApplication::desktop();
//	//	 QPosition globalCursorPosition   = widget->cursor().pos();

//	// QCursor::pos();

//	this->move(QCursor::pos());
//}
// void MainForm::mouseMoveEvent(QMouseEvent *event)
//{
//	qDebug() << QString::number(event->pos().x());
//	qDebug() << QString::number(event->pos().y());
//}

// void MainForm::on_tableView_pressed(const QModelIndex &index) {}
