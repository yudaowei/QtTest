#ifndef CURRENCYMODEL_H
#define CURRENCYMODEL_H
#include <QAbstractTableModel>
#include <QModelIndex>
#include <QDebug>
#include <QMap>

class CurrencyModel : public QAbstractTableModel
{
public:
    CurrencyModel(QObject *parent = 0);
   //初始化数据的函数
   void setCurrencyMap(const QMap<QString, double> &map);
   //对于只读的表模型,必须重新实现以下三个虚函数
   int rowCount(const QModelIndex &parent) const;
   int columnCount(const QModelIndex &parent) const;
   QVariant data(const QModelIndex &index, int role) const;

   //一般情况还需实现headerDate()
   QVariant headerData(int section, Qt::Orientation orientation,
               int role) const;
private:
    QString currencyAt(int offset) const;
    QMap<QString, double> currencyMap;
};

#endif // CURRENCYMODEL_H
