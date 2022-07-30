#ifndef _NODEMODEL_H_
#define _NODEMODEL_H_
#include <QAbstractTableModel>

#include "NodeStatus.h"

class NodeModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	NodeModel(QObject *parent = nullptr);
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index,
								int role = Qt::DisplayRole) const override;

	void AddElement(QString &nodeName);

private:
	QList<NodeStatus> mNodeList;
};

#endif
