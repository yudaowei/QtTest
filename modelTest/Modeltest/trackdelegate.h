#ifndef TRACKDELEGATE_H
#define TRACKDELEGATE_H

#include <QItemDelegate>
#include <QTimeEdit>
class Track
{
public:
    Track(const QString &title, int duration );
    QString title;
    int duration;
};

class TrackDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit TrackDelegate(int durationColumn, QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    
signals:
    
private slots:
    void commitAndCloseEditor();

private:
    int durationColumn;
    
};

#endif // TRACKDELEGATE_H
