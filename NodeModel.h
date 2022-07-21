#include <QAbstractTableModel>

class NodeModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    NodeModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};
