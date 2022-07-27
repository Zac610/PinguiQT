#include "NodeModel.h"

#include "appInfo.h"

#include <QApplication>
#include <QFile>
#include <QSettings>

const QString CONF_FILE_SEP = ";"; // allow to configure with a CSV editor

enum ColumList
{
	COL_IP,
	COL_LAST_SEEN
};

enum NStatus
{
	DOWN,
	UP
};

struct NodeStatus
{
	int id;
	QString ip;
	QString nodeName;
	NStatus status;
	unsigned cyclesNotReplying;
	bool replied;

	//	NodeStatus(const int _id, const QString &_ip, const QString &_nodeName = "") :
	//			id(_id), ip(_ip), nodeName(_nodeName), status(DOWN), cyclesNotReplying(0), replied(false)
	//	{
	//		if (nodeName.isEmpty()) nodeName = ip;
	//	}
	NodeStatus(QString confLine) : status(DOWN), cyclesNotReplying(0), replied(false)
	{
		QStringList fields = confLine.split(CONF_FILE_SEP);
		ip = fields[0];
		if (fields.size() > 1)
			nodeName = fields[1];
		else
			nodeName = "";
	}
};

QList<NodeStatus> gNodeList;

NodeModel::NodeModel(QObject *parent) : QAbstractTableModel(parent)
{
	QString confFile = QApplication::applicationDirPath().left(1) + APPNAME;
	QFile file(confFile);
	if (file.open(QIODevice::ReadOnly))
	{
		QTextStream in(&file);

		while (!in.atEnd())
		{
			QString line = in.readLine();
			// remove comments
			QString lineClean = line.chopped(line.indexOf("#"));
			if (!lineClean.isEmpty()) gNodeList << NodeStatus(lineClean);
		}

		file.close();
	}
}

int NodeModel::rowCount(const QModelIndex & /*parent*/) const
{
	return 2;
}

int NodeModel::columnCount(const QModelIndex & /*parent*/) const
{
	return 3;
}

QVariant NodeModel::data(const QModelIndex &index, int role) const
{
	if (role == Qt::DisplayRole)
		return QString("Row%1, Column%2")
				.arg(index.row() + 1)
				.arg(index.column() +1);

	return QVariant();
}
