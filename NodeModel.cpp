#include "NodeModel.h"

#include "appInfo.h"

#include <QApplication>
#include <QDir>
#include <QFile>
#include <QSettings>
#include <QTextStream>
#include <iostream>

const QString CONF_FILE_SEP = ";"; // allow to configure with a CSV editor

enum ColumList
{
    COL_IP = 0,
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
    QString confFile = QDir::currentPath() + QDir::separator() + "Pingui.conf";
    std::cout << "----test scrittura " << confFile.toLocal8Bit().data() << std::endl;
    QFile file(confFile);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);

        while (!in.atEnd())
        {
            QString line = in.readLine();
            // remove comments
            QString lineClean = line.mid(0, line.indexOf("#"));
            if (!lineClean.isEmpty()) gNodeList << NodeStatus(lineClean);
        }

        file.close();
    }
}

int NodeModel::rowCount(const QModelIndex & /*parent*/) const
{
    return gNodeList.size();
}

int NodeModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 2;
}

QVariant NodeModel::data(const QModelIndex &index, int role) const
{
    QString retVal = "";
    if (role == Qt::DisplayRole)
        switch (index.column()) {
        case COL_IP:
            retVal = "prova";//gNodeList.at(index.row()).ip;
            break;
        case COL_LAST_SEEN:
            retVal = "p2";//""+gNodeList.at(index.row()).cyclesNotReplying;
            break;
        default:
            break;
            return retVal;
        }

    return QVariant();
}
