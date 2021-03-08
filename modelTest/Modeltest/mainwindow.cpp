#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMap<QString, double> currencyMap;
    currencyMap.insert("AUD", 1.3259); //相对于美元的汇率
    currencyMap.insert("CHF", 1.2970);
    currencyMap.insert("SGD", 1.6901);
    currencyMap.insert("USD", 1.0000);
    for(int i=0; i<10000; i++)
            currencyMap.insert(QString("%1").arg(i), 1.0000);
    qDebug()<<currencyMap.count();

    currencyModel = new CurrencyModel(this);//自定义的模型
    currencyModel->setCurrencyMap(currencyMap);

    QTableView *tableView = new QTableView(this);
    tableView->setModel(currencyModel);
    tableView->setAlternatingRowColors(true);
    setCentralWidget(tableView);

    CityWidget = new QMainWindow;
    QStringList cities;
    cities << "Arvika" << "Boden" << "Eskilstuna"
           << "Falun" <<"ben" << "cat";
    cityModel = new CityModel(CityWidget);
    cityModel->setCityies(cities);

    QTableView *tablecityView = new QTableView(CityWidget);
    tablecityView->setModel(cityModel);
    tablecityView->setAlternatingRowColors(true);
//    tablecityView->resizeColumnsToContents();
//    tablecityView->resizeRowsToContents();
//    CityWidget->setGeometry(320,320,320,320);
    CityWidget->setCentralWidget(tablecityView);
    CityWidget->show();

    Delegate = new QDialog;
    QList<Track *> tracks;
    tracks.append(new Track("Overtrue", 110));
    tracks.append(new Track("Overtrue2", 250));
    tracks.append(new Track("Overtrue3", 340));
    QTableWidget *tableWidget = new QTableWidget(tracks.count(), 2, Delegate);
    tableWidget->setItemDelegate(new TrackDelegate(1));
    tableWidget->setHorizontalHeaderLabels(QStringList() << tr("Track") << tr("Duration"));

    for(int row = 0; row < tracks.count(); ++row){
        Track *track = tracks.at(row);

        QTableWidgetItem *item0 = new QTableWidgetItem(track->title);
        tableWidget->setItem(row, 0, item0);
        QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(track->duration));
        item1->setTextAlignment(Qt::AlignRight);
        tableWidget->setItem(row, 1, item1);
    }
    Delegate->show();
}

MainWindow::~MainWindow()
{
    delete CityWidget;
}
