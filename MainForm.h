#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include "NodeModel.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
	class Widget;
}
QT_END_NAMESPACE

class MainForm : public QWidget
{
	Q_OBJECT

public:
	MainForm(QWidget *parent = nullptr);
	~MainForm();

	// private slots:
	//	void on_tableView_pressed(const QModelIndex &index);

	// protected:
	//	virtual void mousePressEvent(QMouseEvent *event) override;
	//	virtual void mouseReleaseEvent(QMouseEvent *event) override;
	//	virtual void mouseMoveEvent(QMouseEvent *event) override;

	// public slots:
	//	void mousePressed(const QPoint &pos);

	bool eventFilter(QObject *obj, QEvent *event);

	void AdjustWindowSizeAccordingToModel();

private:
	Ui::Widget *ui;
	NodeModel *mModel;
	QPoint mStartDragPoint;
	bool mStartDrag;
};
#endif // WIDGET_H
