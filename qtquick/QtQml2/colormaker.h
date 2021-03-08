#ifndef COLORMAKER_H
#define COLORMAKER_H

#include <QObject>
#include <QTimerEvent>
#include <QColor>
#include <QDateTime>

class ColorMaker : public QObject
{
    Q_OBJECT
    /*导出枚举值*/
    Q_ENUMS(GenerateAlgorithm)
    /*导出属性*/
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChange)
    Q_PROPERTY(QColor timeColor READ timeColor)
public:
    explicit ColorMaker(QObject *parent = nullptr);
    ~ColorMaker();

    enum GenerateAlgorithm{
        RandomRGB,
        RandomRed,
        RandomGreen,
        RandomBlue,
        LinearIncrease
    };
    inline QColor color() const {return m_currentColor;}
    void setColor(const QColor &color);
    QColor timeColor() const;
    /*导出方法*/
    Q_INVOKABLE GenerateAlgorithm algotithm() const {return m_algorithm;}
    Q_INVOKABLE void setAlgorithm(GenerateAlgorithm algotithm)
            {m_algorithm = algotithm;}

signals:
    void colorChange(const QColor &color);
    void currentTime(const QString &strTime);

public slots:
    void start();
    void stop();

private:
    GenerateAlgorithm m_algorithm;
    QColor m_currentColor;
    int m_nColorTime;

protected:
    void timerEvent(QTimerEvent *e);
};

#endif // COLORMAKER_H
