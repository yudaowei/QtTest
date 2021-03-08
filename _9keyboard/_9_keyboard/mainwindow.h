#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    

private slots:
    void on_pushButton_pressed();
    void catchpos();
    void on_pushButton_released();
    void released_slot();
    void pressed_slot();
    void catchpos_();
protected:
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
private:
    void ENkey_board_released();
    QPushButton* btn;
    QString released_text;
    QTimer* catchmouse;
    QTimer* catchmouse_;
    QPoint coursePoint;
    QString array[4];
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
