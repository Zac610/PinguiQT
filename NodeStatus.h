#ifndef NODESTATUS_H
#define NODESTATUS_H

#include <QString>
#include <QStringList>

const QString CONF_FILE_SEP = ";"; // allow to configure with a CSV editor

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

	NodeStatus(QString confLine);
};

#endif // NODESTATUS_H
