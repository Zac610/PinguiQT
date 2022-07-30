#include "NodeStatus.h"

NodeStatus::NodeStatus(QString confLine) :
		status(DOWN), cyclesNotReplying(0), replied(false)
{
	QStringList fields = confLine.split(CONF_FILE_SEP);
	ip = fields[0];
	if (fields.size() > 1)
		nodeName = fields[1];
	else
		nodeName = "";
}
