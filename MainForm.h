#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "NodeModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class MainForm : public QWidget
{
	Q_OBJECT

public:
	MainForm(QWidget *parent = nullptr);
	~MainForm();

private:
	Ui::Widget *ui;
	NodeModel *mModel;
};
#endif // WIDGET_H
