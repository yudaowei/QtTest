#ifndef BOOLEAN_H
#define BOOLEAN_H
#include <QAbstractItemModel>
class Node
{
public:
        enum Type
        {
                Root,
                OrExpression,
                AndExpression,
                NotExpression,
                Atom,
                Identifier,
                Operator,
                Punctuator
        };

        Node(Type type, const QString &str = "");
        ~Node();

        Type type;
        QString str;
        Node *parent;
        QList<Node *> children;
};
class BooleanModel : public QAbstractItemModel
{
public:
        BooleanModel(QObject *parent = 0);
        ~BooleanModel();

        void setRootNode(Node *node);

        QModelIndex index(int row, int column,
                                            const QModelIndex &parent) const;
        QModelIndex parent(const QModelIndex &child) const;

        int rowCount(const QModelIndex &parent) const;
        int columnCount(const QModelIndex &parent) const;
        QVariant data(const QModelIndex &index, int role) const;
        QVariant headerData(int section, Qt::Orientation orientation,
                                                int role) const;
private:
        Node *nodeFromIndex(const QModelIndex &index) const;

        Node *rootNode;
};

#endif // BOOLEAN_H
