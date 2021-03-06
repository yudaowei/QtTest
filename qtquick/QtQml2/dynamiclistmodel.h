#ifndef DYNAMICLISTMODEL_H
#define DYNAMICLISTMODEL_H
#include <QAbstractListModel>

class DynamicListModelPrivate;
class DynamicListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int pageSize READ pageSize WRITE setPageSize NOTIFY pageSizeChanged)
    Q_PROPERTY(int total READ total WRITE setTotal NOTIFY totalChanged)
public:
    DynamicListModel(QObject *parent = 0);
    ~DynamicListModel();

    int rowCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void loadMore(bool forward);

    int pageSize() const;
    void setPageSize(int size);
    int total() const;
    void setTotal(int total);

signals:
    void pageSizeChanged(int size);
    void totalChanged(int total);

private:
    DynamicListModelPrivate *m_dptr;
};

#endif // DYNAMICLISTMODEL_H
