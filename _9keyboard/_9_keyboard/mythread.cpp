#include "mythread.h"

MyThread::MyThread()
{
}
void MyThread::run()
{
    while(1)
    {
//        sleep(1);
        qDebug()<<"1";
        msleep(500);
    }
}
