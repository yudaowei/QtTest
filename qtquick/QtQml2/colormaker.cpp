#include "colormaker.h"
ColorMaker::ColorMaker(QObject *parent) : QObject(parent)
  , m_algorithm(RandomRGB)
  , m_currentColor(Qt::black)
  , m_nColorTime(0)
{
    qsrand(QDateTime::currentDateTime().toTime_t());
}
ColorMaker::~ColorMaker()
{

}
void ColorMaker::setColor(const QColor &color)
{
    m_currentColor = color;
    emit colorChange(m_currentColor);
}
QColor ColorMaker::timeColor() const
{
    QTime time = QTime::currentTime();
    int r = time.hour();
    int g = time.minute()*2;
    int b = time.second()*4;
    return QColor::fromRgb(r,g,b);
}

void ColorMaker::start()
{
    if(m_nColorTime == 0){
        m_nColorTime = startTimer(1000);
    }
}
void ColorMaker::stop()
{
    if(m_nColorTime > 0){
        killTimer(m_nColorTime);
        m_nColorTime = 0;
    }
}
void ColorMaker::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == m_nColorTime){
        switch (m_algorithm) {
        case RandomRGB:
            m_currentColor.setRgb(qrand() % 255, qrand() % 255, qrand() % 255);
            break;
        case RandomRed:
            m_currentColor.setRed(qrand()%255);
            break;
        case RandomGreen:
            m_currentColor.setGreen(qrand()%255);
            break;
        case RandomBlue:
            m_currentColor.setBlue(qrand()%255);
            break;
        case LinearIncrease:{
            int r = m_currentColor.red() + 10;
            int g = m_currentColor.green() + 10;
            int b = m_currentColor.blue() + 10;
            m_currentColor.setRgb(r % 255, g % 255, b% 255);
        }
            break;
        }
        emit colorChange(m_currentColor);
        emit currentTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    }else{
        QObject::timerEvent(e);
    }
}
