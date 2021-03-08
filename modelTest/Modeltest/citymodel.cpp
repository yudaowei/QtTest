#include "citymodel.h"

CityModel::CityModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}
int CityModel::rowCount(const QModelIndex &parent) const
{
    return cities.count();
}
int CityModel::columnCount(const QModelIndex &parent) const
{
    return cities.count();
}
//data()在显示模型,选中item,修改item内容都会被调用
QVariant CityModel::data(const QModelIndex &index, int role) const
{
    //qDebug()<<role;
    if(!index.isValid())
        return QVariant();
    if(role == Qt::TextAlignmentRole){
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }else if(role == Qt::DisplayRole){
        if(index.row() == index.column())
            return 0;
        int offset = offsetOf(index.row(), index.column());
        return distances[offset];
    }
    return QVariant();
}
QVariant CityModel::headerData(int section,
                               Qt::Orientation orientation,
                               int role) const
{
    if(role == Qt::DisplayRole)
        return cities[section];
    return QVariant();
}
bool CityModel::setData(const QModelIndex &index,
                        const QVariant &value, int role)
{
    if(index.isValid() && index.row() != index.column()
            && role == Qt::EditRole){
        int offset = offsetOf(index.row(), index.column());
        distances[offset] = value.toInt();

        QModelIndex transposedIndex = createIndex(index.column(),
                                                  index.row());
        emit dataChanged(index, index);
        emit dataChanged(transposedIndex, transposedIndex);
        return true;
    }
    return false;
}
//用flags()函数来判断一个项进行的相关操作,例如是否可以编辑
Qt::ItemFlags CityModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if(index.row() != index.column())
        flags |= Qt::ItemIsEditable;
    return flags;
}
void CityModel::setCityies(const QStringList &cityNames)
{
    cities = cityNames;
    distances.resize(cities.count() * (cities.count() - 1) / 2);
    distances.fill(0);
    endResetModel();
}
int CityModel::offsetOf(int row, int column) const
{
    if(row < column)
        qSwap(row, column);//交换
    return (row * (row - 1) / 2) + column;
}
