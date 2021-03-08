#include "currencymodel.h"

CurrencyModel::CurrencyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
}
int CurrencyModel::rowCount(const QModelIndex &parent) const
{
    return currencyMap.count();
}
int CurrencyModel::columnCount(const QModelIndex &parent) const
{
    return currencyMap.count();
}
QVariant CurrencyModel::data(const QModelIndex &index, int role) const
{
    //qDebug()<<role;
    if(!index.isValid())
        return QVariant();

    if(role == Qt::TextAlignmentRole){
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }else if(role == Qt::DisplayRole){
        QString rowCurrency = currencyAt(index.row());
        QString columnCurrency = currencyAt(index.column());

        if(currencyMap.value(rowCurrency) == 0.0)
            return "####";
        double amount = currencyMap.value(columnCurrency)
                        / currencyMap.value(rowCurrency);
        return QString("%1").arg(amount, 0, 'f', 4);
    }
    return QVariant();
}
//组装水平表头和垂直表头的时候会用到这个函数
QVariant CurrencyModel::headerData(int section,
                        Qt::Orientation orientation,
                        int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    return currencyAt(section);
}
void CurrencyModel::setCurrencyMap(const QMap<QString, double> &map)
{
    currencyMap = map;
    endResetModel();//Qt4 reset();
}
QString CurrencyModel::currencyAt(int offset) const
{
    return (currencyMap.begin() + offset).key();
}
