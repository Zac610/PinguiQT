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
	setWindowFlag(Qt::FramelessWindowHint);
	//	AdjustWindowSizeAccordingToModel();
}

MainForm::~MainForm()
{
	delete mModel;
	delete ui;
}

bool MainForm::eventFilter(QObject * /*obj*/, QEvent *event)
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
		//		AdjustWindowSizeAccordingToModel();
	}
	return false;
}

void MainForm::AdjustWindowSizeAccordingToModel()
{
	//	int width = 0;
	//	for (int i = 0; i < mModel->columnCount(); i++)
	//		width += ui->tableView->columnWidth(i);
	//	int height = 0;
	//	for (int i = 0; i < mModel->rowCount(); i++)
	//		height += ui->tableView->rowHeight(i);
	//	std::cout << "height : " << height << " rowCount " << mModel->rowCount()
	//						<< std ::endl;
	resize(100, 100);
	ui->tableView->resize(90, 90);
	//	ui->tableView->resizeRowsToContents();
}
