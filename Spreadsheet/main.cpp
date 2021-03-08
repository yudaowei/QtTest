#include <QApplication>
#include "mainwindow.h"
#include "DiretoryViewer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/image/image/icon.png"));
    splash->show();

    Qt::Alignment topRight = Qt::AlignRight|Qt::AlignTop;
    splash->showMessage(QObject::tr("Setting up the main window...")
                        , topRight, Qt::white);

    splash->showMessage(QObject::tr("Loading modules..."),
                        topRight, Qt::white);
//    loadModules();
    splash->showMessage(QObject::tr("Establishing connections"),
                        topRight, Qt::white);
//    establishConnect();
    MainWindow *w = new MainWindow;
    DiretoryViewer *x = new DiretoryViewer;
    w->show();

    splash->finish(w);
    delete splash;
    
    return a.exec();
}
