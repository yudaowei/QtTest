#include "DiretoryViewer.h"
#include "ui_DiretoryViewer.h"

DiretoryViewer::DiretoryViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DiretoryViewer)
{
    ui->setupUi(this);
    model = new QDirModel;
    model->setReadOnly(false);
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);

    treeView = new QTreeView;
    treeView->setModel(model);
    treeView->header()->setStretchLastSection(true);
    treeView->header()->setSortIndicator(0, Qt::AscendingOrder);
    treeView->header()->setSortIndicatorShown(true);
    treeView->header()->setClickable(true);

    QModelIndex index = model->index(QDir::currentPath());
    treeView->expand(index);
    treeView->scrollTo(index);
    treeView->resizeColumnToContents(0);

    treeView->show();
}

DiretoryViewer::~DiretoryViewer()
{
    delete ui;
    delete model;
    delete treeView;
}
