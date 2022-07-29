#include "MainForm.h"
#include "ui_MainForm.h"

#include <QDebug>

#include <iostream>

#include "ConfDialog.h"

MainForm::MainForm(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
	ui->setupUi(this);
	mModel = new NodeModel();
	ui->tableView->setModel(mModel);
	ui->tableView->setMouseTracking(true);
	ui->tableView->viewport()->installEventFilter(this);
}

MainForm::~MainForm()
{
	delete mModel;
	delete ui;
}

bool MainForm::eventFilter(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent *mousEv = static_cast<QMouseEvent *>(event);
		if (mousEv->button() == Qt::LeftButton)
		{
			mStartDrag = true;
			mStartDragPoint = mousEv->pos();
		}
		else if (mousEv->button() == Qt::RightButton)
		{
			ConfDialog diag;
			diag.setWindowFlag(Qt::FramelessWindowHint);
			diag.move(QCursor::pos().x() - diag.width() / 2,
								QCursor::pos().y() - diag.height() / 2);
			diag.exec();
		}
		//				QApplication::quit();
	}
	else if (event->type() == QEvent::MouseMove)
	{
		if (mStartDrag)
		{
			QPoint dragPos = QCursor::pos() - mStartDragPoint;
			this->move(dragPos);
		}
	}
	else if (event->type() == QEvent::MouseButtonRelease)
	{
		mStartDrag = false;
	}
	return false;
}
