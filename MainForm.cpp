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
	mStartDrag = false;
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
			diag.mModel = mModel;
			diag.exec();
		}
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

void MainForm::AdjustWindowSizeAccordingToModel()
{
	int width = mModel->rowCount();
}
