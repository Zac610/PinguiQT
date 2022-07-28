#include "NodeModel.h"

#include "appInfo.h"

#include <QApplication>
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
	std::cout << "----test scrittura " << confFile.toLocal8Bit().data()
						<< std::endl;
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
}

int NodeModel::rowCount(const QModelIndex & /*parent*/) const
{
	return mNodeList.size();
}

int NodeModel::columnCount(const QModelIndex & /*parent*/) const { return 2; }

QVariant NodeModel::data(const QModelIndex &index, int role) const
{
	QString retVal = "";
	if (role == Qt::DisplayRole)
		switch (index.column())
		{
			case COL_IP:
				retVal = "prova"; // gNodeList.at(index.row()).ip;
				break;
			case COL_LAST_SEEN:
				retVal = "p2"; //""+gNodeList.at(index.row()).cyclesNotReplying;
				break;
			default: break;
		}

	return QVariant();
}
