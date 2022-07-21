#include "NodeModel.h"

#include "appInfo.h"

#include <QApplication>
#include <QSettings>

enum ColumList
{
	COL_IP,
	COL_LAST_SEEN
};

NodeModel::NodeModel(QObject *parent)
	: QAbstractTableModel(parent)
{
	QString sSettingsFile = QApplication::applicationDirPath().left(1) + APPNAME;
	QSettings settings(QString(sSettingsFile), QSettings::IniFormat);
	QString someValue = settings.value("some/config/key", "default value if unset").toString(); // settings.value() returns QVariant
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
