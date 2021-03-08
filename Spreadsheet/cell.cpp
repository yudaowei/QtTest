#include "cell.h"

Cell::Cell()
{
    setDirty();
}
QTableWidgetItem *Cell::clone() const
{
    return new Cell(*this);
}
void Cell::setFormula(const QString &formula)
{
    setData(Qt::EditRole, formula);//Qt::EditRole返回公式
}
QString Cell::formula() const
{
    return data(Qt::EditRole).toString();
}
void Cell::setData(int role, const QVariant &value)
{
    QTableWidgetItem::setData(role, value);
    if(role == Qt::EditRole)
    {
        setDirty();
    }
}
void Cell::setDirty()
{
    cacheIsDirty = true;
}
QVariant Cell::data(int role) const
{
    if(role == Qt::DisplayRole)//文本形式
    {
        if(value().isValid())
        {
            return value().toString();
        }
        else
        {
            return "####";
        }
    }
    else if(role == Qt::TextAlignmentRole)//对齐格式
    {
        if(value().type() == QVariant::String)
        {
            return int(Qt::AlignLeft | Qt::AlignVCenter);
        }
        else
        {
            return int(Qt::AlignRight | Qt::AlignVCenter);
        }
    }
    else
    {
        return QTableWidgetItem::data(role);
    }
}
const QVariant Invalid;
QVariant Cell::value() const
{
    if(cacheIsDirty)//如果是true的话就要重新计算这个值
    {
        cacheIsDirty = false;
        QString formulaStr = formula();//获取单元格公式
        if(formulaStr.startsWith('\''))//如果公式由单引号(')开始,值就是从位置1到最后一位
        {
            cachedValue = formulaStr.mid(1);
        }
        else if(formulaStr.startsWith('='))
        {
            cachedValue = Invalid;
            QString expr = formulaStr.mid(1);
            expr.replace(" ", "");//移除包含的所有空格
            expr.append(QChar::Null);

            int pos = 0;
            cachedValue = evalExpression(expr, pos);//解析公式
            if(expr[pos] != QChar::Null)//如果解析成功会在pos位置处添加QChar::Null
            {
                cachedValue = Invalid;//解析失败使cachedValue无效化
            }
        }
        else//既不是单引号(')也不是等号(=)开头的处理方案
        {
            bool ok;
            double d = formulaStr.toDouble(&ok);//toDouble()尝试把formulaStr转为浮点数,转换成功会返回浮点值并将ok设置为true,转换失败返回0.0并设置ok为false
            if(ok)
            {
                cachedValue = d;
            }
            else
            {
                cachedValue = formulaStr;
            }
        }
    }
    return cachedValue;
}
/*
 *  函数名:QVariant Cell::evalExpression()
 *  功能:返回一个电子制表软件项内公式表达式的值
 *  解析:表达式定义为由一个或多个通过'+'或'-'操作符分隔成的项
 *      项定义为由一个或多个通过'*'或'/'操作符分隔成的因子.
*/
QVariant Cell::evalExpression(const QString &str, int &pos) const
{
    QVariant result = evalTerm(str, pos);//调用evalTerm得到第一项的值
    while(str[pos] != QChar::Null)
    {
        QChar op = str[pos];
        if(op != '+' && op != '-')//当前str的pos不是'+'/'-'说明表达式已经拆解完毕
        {
            return result;
        }
        pos++;
        QVariant term = evalTerm(str, pos);
        if(result.type() == QVariant::Double &&
                term.type() == QVariant::Double)
        {
            if(op == '+')
            {
                result = result.toDouble() + term.toDouble();
            }
            else
            {
                result = result.toDouble() - term.toDouble();
            }
        }
        else
        {
            result = Invalid;
        }
    }
    return result;
}
QVariant Cell::evalTerm(const QString &str, int &pos) const
{
    QVariant result = evalFactor(str, pos);
    while(str[pos] != QChar::Null)
    {
        QChar op = str[pos];
        if(op != '*' && op != '/')
        {
            return result;
        }
        pos++;
        QVariant factor = evalFactor(str, pos);
        if(result.type() == QVariant::Double
                && factor.type() == QVariant::Double)
        {
            if(op == '*')
            {
                result = result.toDouble() * factor.toDouble();
            }
            else
            {
                if(factor.toDouble() == 0.0)//避免分母为0的情况
                {
                    result = Invalid;
                }
                else
                {
                    result = result.toDouble() / factor.toDouble();
                }
            }
        }
        else
        {
            result = Invalid;
        }
    }
    return result;
}
QVariant Cell::evalFactor(const QString &str, int &pos) const
{
    QVariant result;
    bool negative = false;
    if(str[pos] == '-')//判断因子是否为负
    {
        negative = true;
        pos++;
    }
    if(str[pos] == '(')
    {
        pos++;
        result = evalExpression(str, pos);
        if(str[pos] != ')')
        {
            result = Invalid;
        }
        pos++;
    }
    else
    {
        QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
        QString token;
        while(str[pos].isLetterOrNumber() || str[pos] == '.')
        {
            token += str[pos];
            pos++;
        }
        if(regExp.exactMatch(token))
        {
            int column = token[0].toUpper().unicode() - 'A';
            int row = token.mid(1).toInt() - 1;
            Cell *c = static_cast<Cell*>(tableWidget()->item(row, column));
            if(c)
            {
                result = c->value();
            }
            else
            {
                result = 0.0;
            }
        }
        else
        {
            bool ok;
            result = token.toDouble(&ok);
            if(!ok)
            {
                result = Invalid;
            }
        }
    }
    if(negative)
    {
        if(result.type() == QVariant::Double)
        {
            result = -result.toDouble();
        }
        else
        {
            result = Invalid;
        }
    }
    return result;
}

