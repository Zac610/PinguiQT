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
	//	std::cout << event->type() << std::endl;
	if (event->type() == QEvent::MouseButtonRelease)
	{
		std::cout << "Mouse Released" << std::endl;
		mStartDrag = false;
	}
	else if (event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent *mousEv = static_cast<QMouseEvent *>(event);
		std::cout << "Mouse Pressed" << std::endl;
		if (mousEv->button() == Qt::LeftButton)
		{
			mStartDrag = true;
			mStartDragPoint = mousEv->pos();
		}
		else if (mousEv->button() == Qt::RightButton)
			QApplication::quit();
	}
	else if (event->type() == QEvent::MouseMove)
	{
		std::cout << "Mouse Move" << std::endl;
		//		QMouseEvent *mev =
		//		qDebug() << QString::number(mev->pos().x());
		//		qDebug() << QString::number(mev->pos().y());
		//		this->pos() = QCursor::pos();
		if (mStartDrag)
		{
			QPoint dragPos = QCursor::pos() - mStartDragPoint;
			this->move(dragPos.x(), dragPos.y());
		}
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
