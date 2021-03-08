#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    scene = new QGraphicsScene(0, 0, 600, 500);//实例化一个场景
    view = new QGraphicsView;//实例化一个视图
    view->setScene(scene);    // 在视图中显示场景
    view->setDragMode(QGraphicsView::RubberBandDrag);//允许圈选
    view->setRenderHints(QPainter::Antialiasing |
                         QPainter::TextAntialiasing);//设置默认渲染:反走样,文字反走样
    view->setContextMenuPolicy(Qt::ActionsContextMenu);//右键上下文菜单策略 显示QWidget::actions()
    setCentralWidget(view);

    minZ = 0;
    maxZ = 0;
    seqNumber = 0;

    createActions();
    createMenus();
    createToolBars();

    connect(scene, SIGNAL(selectionChanged()),
            this, SLOT(updateActions()));//选取发生改变时, 场景scene发出selectionChanged()信号
    setWindowTitle(tr("Diagram"));
    updateActions();
}
void MainWindow::addNode()
{
    Node *node = new Node;
    node->setText(tr("Node %1").arg(seqNumber + 1));
    setupNode(node);//设置节点刚出生时的位置
}
void MainWindow::setupNode(Node *node)
{
    node->setPos(QPoint(80 + (100 * (seqNumber % 5)),
                        80 + (50 * ((seqNumber / 5) % 7))));
    scene->addItem(node);//添加一个项
    ++seqNumber;

    scene->clearSelection();//清除当前选中
    node->setSelected(true);//刚出生的节点为被选中状态
    bringToFront();//设置节点层次,确保新节点最靠前
}
void MainWindow::bringToFront()
{
    ++maxZ;
    setZValue(maxZ);
    qDebug() << maxZ;
}
void MainWindow::sendToBack()
{
    --minZ;
    setZValue(minZ);
    qDebug() << minZ;
}
void MainWindow::setZValue(int z)
{
    Node *node = selectedNode();
    if(node)
        node->setZValue(z);
}
Node *MainWindow::selectedNode() const//选中的节点只有一个会被强制转换为Node*类型并将其返回
{
    QList<QGraphicsItem *> items = scene->selectedItems();//返回被选中节点的列表
    if(items.count() == 1){
        return dynamic_cast<Node *> (items.first());
        /*
         *C++的四种安全强制转换static_cast, dynamic_cast, const_cast, reinterpret_cast
        */
    }else{
        return 0;
    }
}
void MainWindow::addLink()
{
    NodePair nodes = selectedNodePair();
    if(nodes == NodePair())
        return;

    Link *link = new Link(nodes.first, nodes.second);
    scene->addItem(link);//将线放进场景中
}
MainWindow::NodePair MainWindow::selectedNodePair() const
{
    QList<QGraphicsItem *> items = scene->selectedItems();
    if(items.count() == 2){
        Node *first = dynamic_cast<Node *>(items.first());
        Node *second = dynamic_cast<Node *>(items.last());
        if(first && second)
            return NodePair(first, second);
    }
    return NodePair();//返回一对空的项
}
void MainWindow::del()
{
    QList<QGraphicsItem *> items = scene->selectedItems();
    QMutableListIterator<QGraphicsItem *> i(items);//一个java风格的迭代器,当需要对一个列表依次操作时即可使用
    while(i.hasNext()){//当选中的诸多对象中既有node又有link时, 先将link进行删除,以避免在node的析构函数中对link进行二次删除
        Link *link = dynamic_cast<Link *>(i.next());
        if(link){
            delete link;
            i.remove();
        }
    }
    qDeleteAll(items);//删除容器, 会调用node的析构函数
}
void MainWindow::properties()
{
    Node *node = selectedNode();
    Link *link = selectedLink();

    if(node){
        Propertiesdialog dialog(node, this);
        dialog.exec();
    }else if(link){
        QColor color = QColorDialog::getColor(link->color(), this);//弹出颜色对话框
        if(color.isValid())
            link->setColor(color);
    }
}
void MainWindow::cut()
{
    Node *node = selectedNode();
    if(!node)
        return;

    copy();
    delete node;
}
void MainWindow::copy()
{
    Node *node = selectedNode();
    if(!node)
        return;
    QString str = QString("Node %1 %2 %3 %4")
            .arg(node->textColor().name())
            .arg(node->outlineColor().name())
            .arg(node->backgroundColor().name())
            .arg(node->text());
    QApplication::clipboard()->setText(str);//将字符串放进剪贴板中
    qDebug() << str;
}
void MainWindow::paste()
{
    QString str = QApplication::clipboard()->text();
    QStringList parts = str.split(" ");

    if (parts.count() >= 5 && parts.first() == "Node") {//头为Node的字符串进行解析
        Node *node = new Node;
        qDebug()<<QStringList(parts.mid(4)).join(" ");
        node->setText(QStringList(parts.mid(4)).join(" ")); // 连接字符串列表
        node->setTextColor(QColor(parts[1]));
        node->setOutlineColor(QColor(parts[2]));
        node->setBackgroundColor(QColor(parts[3]));
        setupNode(node);
    }
}
void MainWindow::createActions()
{
    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    addNodeAction = new QAction(tr("Add &Node"), this);
    addNodeAction->setIcon(QIcon(":/images/node.png"));
    addNodeAction->setShortcut(tr("Ctrl+N"));
    connect(addNodeAction, SIGNAL(triggered()), this, SLOT(addNode()));

    addLinkAction = new QAction(tr("Add &Link"), this);
    addLinkAction->setIcon(QIcon(":/images/link.png"));
    addLinkAction->setShortcut(tr("Ctrl+L"));
    connect(addLinkAction, SIGNAL(triggered()), this, SLOT(addLink()));

    deleteAction = new QAction(tr("&Delete"), this);
    deleteAction->setIcon(QIcon(":/images/delete.png"));
    deleteAction->setShortcut(tr("Del"));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(del()));

    cutAction = new QAction(tr("Cu&t"), this);
    cutAction->setIcon(QIcon(":/images/cut.png"));
    cutAction->setShortcut(tr("Ctrl+X"));
    connect(cutAction, SIGNAL(triggered()), this, SLOT(cut()));

    copyAction = new QAction(tr("&Copy"), this);
    copyAction->setIcon(QIcon(":/images/copy.png"));
    copyAction->setShortcut(tr("Ctrl+C"));
    connect(copyAction, SIGNAL(triggered()), this, SLOT(copy()));

    pasteAction = new QAction(tr("&Paste"), this);
    pasteAction->setIcon(QIcon(":/images/paste.png"));
    pasteAction->setShortcut(tr("Ctrl+V"));
    connect(pasteAction, SIGNAL(triggered()), this, SLOT(paste()));

    bringToFrontAction = new QAction(tr("Bring to &Front"), this);
    bringToFrontAction->setIcon(QIcon(":/images/bringtofront.png"));
    connect(bringToFrontAction, SIGNAL(triggered()),
            this, SLOT(bringToFront()));

    sendToBackAction = new QAction(tr("&Send to Back"), this);
    sendToBackAction->setIcon(QIcon(":/images/sendtoback.png"));
    connect(sendToBackAction, SIGNAL(triggered()),
            this, SLOT(sendToBack()));

    propertiesAction = new QAction(tr("P&roperties..."), this);
    connect(propertiesAction, SIGNAL(triggered()),
            this, SLOT(properties()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(addNodeAction);
    editMenu->addAction(addLinkAction);
    editMenu->addAction(deleteAction);
    editMenu->addSeparator();
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addSeparator();
    editMenu->addAction(bringToFrontAction);
    editMenu->addAction(sendToBackAction);
    editMenu->addSeparator();
    editMenu->addAction(propertiesAction);
}

void MainWindow::createToolBars()
{
    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(addNodeAction);
    editToolBar->addAction(addLinkAction);
    editToolBar->addAction(deleteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(bringToFrontAction);
    editToolBar->addAction(sendToBackAction);
}

void MainWindow::updateActions()
{
    bool hasSelection = !scene->selectedItems().isEmpty();
    bool isNode = (selectedNode() != 0 || selectedLink() != 0);
    bool isNodePair = (selectedNodePair() != NodePair());

    cutAction->setEnabled(isNode);
    copyAction->setEnabled(isNode);
    addLinkAction->setEnabled(isNodePair);
    deleteAction->setEnabled(hasSelection);
    bringToFrontAction->setEnabled(isNode);
    sendToBackAction->setEnabled(isNode);
    propertiesAction->setEnabled(isNode);
/*
 *  每一个窗口部件都有相关的QActions列表
 *  这里重新设置QActions列表可以调整右键菜单的显示
*/
    foreach (QAction *action, view->actions())
        view->removeAction(action);  // 删除右键菜单

    foreach (QAction *action, editMenu->actions()) {
        if (action->isEnabled())
            view->addAction(action);  // 增加右键菜单
    }
}
Link *MainWindow::selectedLink() const
{
    QList<QGraphicsItem *> items = scene->selectedItems();
    if (items.count() == 1) {
        return dynamic_cast<Link *>(items.first());
    } else {
        return 0;
    }
}
MainWindow::~MainWindow()
{
}
