#include "NodeModel.h"

#include "appInfo.h"

#include <QApplication>
#include <QBrush>
#include <QDir>
#include <QFile>
#include <QSettings>
#include <QTextStream>
#include <iostream>

enum ColumList
{
	COL_IP = 0,
	COL_LAST_SEEN
};

NodeModel::NodeModel(QObject *parent) : QAbstractTableModel(parent)
{
	QString confFile = QDir::currentPath() + QDir::separator() + "Pingui.conf";
	QFile file(confFile);
	if (file.open(QIODevice::ReadOnly))
	{
		QTextStream in(&file);

		while (!in.atEnd())
		{
			QString line = in.readLine();
			// remove comments
			QString lineClean = line.mid(0, line.indexOf("#"));
			if (!lineClean.isEmpty())
				mNodeList << NodeStatus(lineClean);
		}

		file.close();
	}
	if (mNodeList.empty())
		mNodeList << NodeStatus("127.0.0.1");
}

int NodeModel::rowCount(const QModelIndex & /*parent*/) const
{
	return mNodeList.size();
}

int NodeModel::columnCount(const QModelIndex & /*parent*/) const { return 2; }

QVariant NodeModel::data(const QModelIndex &index, int role) const
{
	switch (role)
	{
		case Qt::DisplayRole:
			switch (index.column())
			{
				case COL_IP: return mNodeList.at(index.row()).ip;
				case COL_LAST_SEEN: return mNodeList.at(index.row()).cyclesNotReplying;
				default: break;
			}
		case Qt::BackgroundRole:
			if (mNodeList.at(index.row()).replied)
				return QBrush(Qt::green);
			else
				return QBrush(Qt::red);
	}

	return QVariant();
}

void NodeModel::AddElement(QString &nodeName)
{
	mNodeList << NodeStatus(nodeName);
	// emit dataChanged()
}
