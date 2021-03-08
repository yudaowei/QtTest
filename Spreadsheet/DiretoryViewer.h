#ifndef DIRETORYVIEWER_H
#define DIRETORYVIEWER_H

#include <QDialog>
#include <QDirModel>
#include <QTreeView>

namespace Ui {
class DiretoryViewer;
}

class DiretoryViewer : public QDialog
{
    Q_OBJECT
    
public:
    explicit DiretoryViewer(QWidget *parent = 0);
    ~DiretoryViewer();
    
private:
    QDirModel *model;
    QTreeView *treeView;
    Ui::DiretoryViewer *ui;
};

#endif // DIRETORYVIEWER_H
