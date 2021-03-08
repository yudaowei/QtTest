#ifndef CELL_H
#define CELL_H

#include <QTableWidgetItem>

class Cell : public QTableWidgetItem
{
public:
    Cell();
    QTableWidgetItem *clone()const;
    void setData(int role, const QVariant &value);
    QVariant data(int role) const;
    void setFormula(const QString &formula);
    QString formula() const;
    void setDirty();

private:
    /*
     *QVariant类提供了一种多样的数据类型,
     *通过内置方法可将存储的数据
     *转化为任意的基础类型
     */
    QVariant value() const;
    QVariant evalExpression(const QString &str, int &pos) const;
    QVariant evalTerm(const QString &str, int &pos) const;
    QVariant evalFactor(const QString &str, int &pos) const;

    mutable QVariant cachedValue;//把单元格的值缓存为QVariant
    mutable bool cacheIsDirty;//缓存不是最新值设置为true
    
};

#endif // CELL_H
