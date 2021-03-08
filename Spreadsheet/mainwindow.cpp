#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    spreadsheet = new Spreadsheet;
    setCentralWidget(spreadsheet);//将spreadsheet设置为窗口中心的小部件

    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

    readSettings();
    findDialog = 0;//设置为空指针,在调用MainWindow::find()时再创建FindDialog对象

    setWindowIcon(QIcon(":/image/image/icon.png"));//设置窗口图标 Qt支持图标文件有 BMP GIF JPEG PNG SVG TIFF XBM XPM
    setCurrentFile("");

    setAttribute(Qt::WA_DeleteOnClose);//为防止窗口关闭出现内存泄漏
    setFixedSize(800, 480);
}
/*
 *Qt中,采用了QAction的类来操作菜单选项,可以添加任意数量的菜单和工具栏上的项
*/
void MainWindow::createActions()
{
    newAction = new QAction(tr("&New"), this);
    newAction->setIcon(QIcon(":/image/image/icon.png"));
    newAction->setShortcut(/*New的默认快捷键*/QKeySequence::New);//设置快捷键
    newAction->setStatusTip(tr("Create a new spreadsheet file"));//鼠标悬停时的提示
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));//用户按下快捷键/菜单选项/工具栏触发triggered

    openAction = new QAction(tr("&Open"), this);
    openAction->setIcon(QIcon(":images/icon.png"));
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("Open spreadsheet file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":images/icon.png"));
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save spreadsheet file"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAction = new QAction(tr("&Save As"), this);
    saveAsAction->setIcon(QIcon(":images/icon.png"));
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("Save spreadsheet file"));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

    /*最近打开的文件*/
    for(int i=0; i<MaxRecentFiles; i++)
    {
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);//隐式动作
        connect(recentFileActions[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
    }

    closeAction = new QAction(tr("&Close"), this);
    closeAction->setShortcut(QKeySequence::Close);
    closeAction->setStatusTip(tr("Close this window"));
    connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));//由于没有终止程序的标准化建序列,在这里需要注明指定的快捷键
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

    selectAllAction = new QAction(QIcon(":images/icon.png"), tr("&All"), this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    selectAllAction->setStatusTip(tr("Select all the cells in the spreadsheet"));
    connect(selectAllAction, SIGNAL(triggered()), spreadsheet, SLOT(selectAll()));

    /*这是一个复选动作,在菜单中带有一个复选标记,在工具栏中可以实现成切换(toggle)按钮*/
    showGridAction = new QAction(tr("&Show Grid"), this);
    showGridAction->setCheckable(true);//初始化状态为选中的状态
    showGridAction->setChecked(spreadsheet->showGrid());
    showGridAction->setStatusTip(tr("Show or hide thie spreadsheet's grid"));
    connect(showGridAction, SIGNAL(toggled(bool)), spreadsheet, SLOT(setShowGrid(bool)));

    sortAction = new QAction(tr("&Sort"), this);
    sortAction->setStatusTip(tr("Sheet sort"));
    connect(sortAction, SIGNAL(triggered()), this, SLOT(sort()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    findAction = new QAction(tr("&Find"), this);
    findAction->setStatusTip(tr("Find sameone information"));
    connect(findAction, SIGNAL(triggered()), this, SLOT(find()));

    goToCellAction = new QAction(tr("&Cell"), this);
    goToCellAction->setStatusTip(tr("..."));
    connect(goToCellAction, SIGNAL(triggered()), this, SLOT(goToCell()));

    cutAction = new QAction(tr("Cut"), this);
    cutAction->setShortcut(tr("Ctrl+X"));
    connect(cutAction, SIGNAL(triggered()), spreadsheet, SLOT(cut()));

    copyAction = new QAction(tr("Copy"), this);
    copyAction->setShortcut(tr("Ctrl+C"));
    connect(copyAction, SIGNAL(triggered()), spreadsheet, SLOT(copy()));

    pasteAction = new QAction(tr("Paste"), this);
    pasteAction->setShortcut(tr("Ctrl+V"));
    connect(pasteAction, SIGNAL(triggered()), spreadsheet, SLOT(paste()));

    deleteAction = new QAction(tr("Delete"), this);
    connect(deleteAction, SIGNAL(triggered()), spreadsheet, SLOT(del()));

    autoRecalcAction = new QAction(tr("autoRecalc"), this);
    autoRecalcAction->setStatusTip(tr("Auto Recalc item all."));
    autoRecalcAction->setCheckable(true);
    connect(autoRecalcAction, SIGNAL(triggered(bool)), spreadsheet, SLOT(setAutoRecalculate(bool)));

    selectRowAction = new QAction(tr("SelectRow"), this);
    selectRowAction->setStatusTip(tr("Select current row"));
    connect(selectRowAction, SIGNAL(triggered()), spreadsheet, SLOT(selectCurrentRow()));

    selectColumnAction = new QAction(tr("SelectColumn"), this);
    selectColumnAction->setStatusTip((tr("Select current column")));
    connect(selectColumnAction, SIGNAL(triggered()), spreadsheet, SLOT(selectCurrentColumn()));
}
/*
 *  将创建好的Action添加到menu中
 *  Qt中菜单用QMenu实例化addMenu()函数可以创造一个QMenu窗口部件,并添加到菜单栏中
 *  QMainWindow::menuBar()函数返回一个指向QMenuBar的指针,菜单栏在第一次调用menuBar()函数时就创建出来
*/
void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&Flie"));//添加主菜单选项
    fileMenu->addAction(newAction);//添加主菜单子选项
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    separatorAction = fileMenu->addSeparator();//添加分隔符号,用一个指针指向间隔符,是为了在间隔符之间没有文件的时候做隐藏操作
    for(int i=0; i<MaxRecentFiles; i++)
    {
        fileMenu->addAction(recentFileActions[i]);
    }
    fileMenu->addSeparator();
    fileMenu->addAction(closeAction);
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(deleteAction);

    selectSubMenu = editMenu->addMenu(tr("&Select"));//添加子菜单
    selectSubMenu->addAction(selectRowAction);
    selectSubMenu->addAction(selectColumnAction);
    selectSubMenu->addAction(selectAllAction);

    editMenu->addSeparator();
    editMenu->addAction(findAction);
    editMenu->addAction(goToCellAction);
    editMenu->addAction(sortAction);

    toolsMenu = menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addMenu(tr("&Tools"));
//    toolsMenu->addAction(recalculateAction);
    toolsMenu->addAction(sortAction);

    optionsMenu = menuBar()->addMenu(tr("&Options"));
    optionsMenu->addMenu(tr("&Options"));
    optionsMenu->addAction(showGridAction);
    optionsMenu->addAction(autoRecalcAction);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
//    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}
/*
 *  Qt的上下文菜单策略,每个窗口部件都有一个与之相关的QActions列表,
 *  当用户点击右键或着在键盘上按下与平台相关的按键时,就可以激活这些上下文
*/
void MainWindow::createContextMenu()
{
    spreadsheet->addAction(cutAction);
    spreadsheet->addAction(copyAction);
    spreadsheet->addAction(pasteAction);
    spreadsheet->addAction(deleteAction);
    spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);//小部件将其Action显示为上下文菜单
}
/*
 *  设置工具栏
*/
void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    editToolBar = addToolBar(tr("&Edit"));
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
    editToolBar->addAction(deleteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(findAction);
    editToolBar->addAction(goToCellAction);
}
/*
 *  设置状态栏,包括两个状态指示器,当前单元格的位置和当前单元格的公式,
 *  同时也用于显示状态信息和一些临时的提示信息
*/
void MainWindow::createStatusBar()
{
    locationLabel = new QLabel("W999");
    locationLabel->setAlignment(Qt::AlignHCenter);
    locationLabel->setMinimumSize(locationLabel->sizeHint());//sizeHint为理想大小,取决于部件的内容

    formulaLabel = new QLabel;
    formulaLabel->setIndent(3);//缩进
//statusBar()返回主窗口状态栏,若状态栏不存在则创建一个空的状态栏
    statusBar()->addWidget(locationLabel);
    statusBar()->addWidget(formulaLabel, 1);//伸展为1

    connect(spreadsheet, SIGNAL(currentCellChanged(int,int,int,int)),
            this, SLOT(updateStatusBar()));//光标移动到一个新的单元格这个槽就会调用
    connect(spreadsheet, SIGNAL(modified()), this, SLOT(spreadsheetModified()));
    updateStatusBar();

}
void MainWindow::updateStatusBar()
{
    locationLabel->setText(spreadsheet->currentLocation());
    formulaLabel->setText(spreadsheet->currentFormula());
}
void MainWindow::spreadsheetModified()
{
    setWindowModified(true);//在标题栏显示文档是否有未保存的更改
    updateStatusBar();
}
/*
 *  实现File菜单
*/
void MainWindow::newFile()
{
    if(okToContinue())//弹出一个对话框
    {
        spreadsheet->clear();
        setCurrentFile("");//更新窗口标题
    }

    MainWindow *mainWin = new MainWindow(this);
    mainWin->show();
}
bool MainWindow::okToContinue()
{
    if(isWindowModified())//是否修改过且未保存
    {
        int r = QMessageBox::warning(this, tr("Spreadsheet"),
                                     tr("The document has been modified.\n Do you want to save your changes?"),
                                     QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);//警告对话框
        if(r == QMessageBox::Yes)
        {
            return save();
        }
        else if(r == QMessageBox::Cancel)
        {
            return false;
        }
    }
    return true;
}
void MainWindow::open()
{
    if(okToContinue())
    {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open Spreadsheet"),
                                                        ".", tr("Spreadsheet files (*.sp)"));
        if(!fileName.isEmpty())
        {
            loadFile(fileName);
        }
    }
}
bool MainWindow::loadFile(const QString &fileName)
{
    if(!spreadsheet->readFile(fileName))
    {
        statusBar()->showMessage(tr("Loading canceled"), 2000);
        return false;
    }
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
    return true;
}
bool MainWindow::save()
{
    if(curFile.isEmpty())
    {
        return saveAs();
    }
    else
    {
        return saveFile(curFile);
    }
}
bool MainWindow::saveFile(const QString &fileName)
{
    if(!spreadsheet->writeFile(fileName))
    {
        statusBar()->showMessage(tr("Saving canceled"), 2000);
        return false;
    }
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}
bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Spreadsheet"),
                                                    ".", tr("Spreadsheet files (*.sp)"));
    if(fileName.isEmpty())
    {
        return false;
    }
    return saveFile(fileName);
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    if(okToContinue())
    {
        writeSettings();
        event->accept();
    }
    else
    {
        event->ignore();
    }
}
void MainWindow::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    setWindowModified(false);//如果文档存在没有保存的变化,则应把这个属性设置为true,否则将其设置为fales

    QString shownName = tr("Untitled");
    if(!curFile.isEmpty())
    {
        shownName = strippedName(curFile);
        recentFiles.removeAll(curFile);
        recentFiles.prepend(curFile);//追加到最后
        updateRecentFileActions();
    }
    setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Spreadsheet")));
}
QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();//移除路径相关的字符,只保留下路径名
}
/*
 *  使用一个java风格的迭代器QMutableStringListIterator, 可以移除任何不再存在的文件
 *
*/
void MainWindow::updateRecentFileActions()
{
    QMutableStringListIterator i(recentFiles);//可变的字符串列表迭代器
    while(i.hasNext())
    {
        if(!QFile::exists(i.next()))//指定的文件是否存在
        {
            i.remove();//从迭代器移除这个文件
        }
        for(int j=0; j<MaxRecentFiles; j++)
        {
            if(j < recentFiles.count())
            {
                QString text = tr("&%1 %2").arg(j+1).arg(strippedName(recentFiles[j]));
                recentFileActions[j]->setText(text);
                recentFileActions[j]->setData(recentFiles[j]);//将文件的全名保存在data项中
                recentFileActions[j]->setVisible(true);
            }
            else
            {
                recentFileActions[j]->setVisible(false);
            }
        }
        separatorAction->setVisible(!recentFiles.isEmpty());
    }
}
void MainWindow::openRecentFile()
{
    if(okToContinue())
    {
        QAction *action = qobject_cast<QAction *>(sender());//qobject_cast<T>元对象编辑器在moc生成的元信息基础上执行动态类型强制转换
        if(action)//在对象不能被强制转换时会返回0
        {
            loadFile(action->data().toString());//QVariant类型可以保存许多C++和Qt型变量
        }
    }
}
/*
 *  使用自制对话框
*/
void MainWindow::find()
{
    if(!findDialog)
    {
        findDialog = new FindDialog(this);
        connect(findDialog, SIGNAL(findNext(QString,Qt::CaseSensitivity)),
                spreadsheet, SLOT(findNext(const QString &, Qt::CaseSensitivity)));
        connect(findDialog, SIGNAL(findPrevious(QString,Qt::CaseSensitivity)),
                spreadsheet, SLOT(findPrevious(const QString &, Qt::CaseSensitivity)));
    }
    findDialog->show();
    findDialog->raise();//设置窗口在最顶部
    findDialog->activateWindow();//设置为活动窗口
}
void MainWindow::goToCell()//这个窗口不希望能够与应用程序中的其他窗口切换,不可使用show()的方法来显示窗口
{
    //用show()来显示窗口也可后续调用setModal()让它变为模态对话框
    GoToCellDialog dialog(this);
    if(dialog.exec())//此方法在窗口弹出可以阻塞应用程序,直到关闭此窗口为止
    {
        QString str = dialog.lineEdit->text().toUpper();
        spreadsheet->setCurrentCell(str.mid(1).toInt() - 1, str[0].unicode() - 'A');
    }
}
void MainWindow::sort()
{
    SortDialog dialog(this);
//    dialog.setSpreadsheet(spreadsheet);
    QTableWidgetSelectionRange range = spreadsheet->selectedRange();
    dialog.setColumnRange('A' + range.leftColumn(),
                          'A' + range.rightColumn());
    if(dialog.exec())
    {
        SpreadsheetCompare compare;
        compare.Keys[0] =
                dialog.ui->primaryColumnCombo->currentIndex();
        compare.Keys[1] =
                dialog.ui->secondaryColumnCombo->currentIndex() - 1;
        compare.Keys[2] =
                dialog.ui->tertiaryColumncombo->currentIndex() - 1;

        compare.ascending[0] =
                (dialog.ui->primaryOrderCombo->currentIndex() == 0);
        compare.ascending[1] =
                (dialog.ui->secondaryOrderCombo->currentIndex() == 0);
        compare.ascending[2] =
                (dialog.ui->tertiaryOrderCombo->currentIndex() == 0);

        spreadsheet->sort(compare);
    }
//    dialog.exec();
}
void MainWindow::about()
{
    QMessageBox::about(this, tr("About Spreadsheet"),
                       tr("<h2>Spreadsheet 1.1</h2> "
                          "<p>Copyright &copy; 2019 Software Inc."
                          "<p>Spreadsheet is a small application that "
                          "demonstrates QAction, QMainWindow, QMenuBar, "
                          "QStatusBar, QTableWidget, QToolBar, and many other "
                          "Qt classes."));
}
/*
 *  存储函数
*/
void MainWindow::writeSettings()
{
    QSettings settings("Software Inc.", "Spreadsheet");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("recentFiles", recentFiles);
}
void MainWindow::readSettings()
{
    QSettings settings("Software Inc", "Spreadsheet");

    restoreGeometry(settings.value("geometry").toByteArray());

    recentFiles = settings.value("recentFiles").toStringList();
    updateRecentFileActions();

    bool showGrid = settings.value("showGrid", true).toBool();//value的第二个参数表示，在没有可用设置的时候所需的默认值
    showGridAction->setChecked(showGrid);

    bool autoRecalc = settings.value("autoRecalc", true).toBool();
    autoRecalcAction->setChecked(autoRecalc);
}
MainWindow::~MainWindow()
{
    
}
