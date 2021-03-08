#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QMap>
#include <QPixmap>
#include <QVector>
#include <QStylePainter>
#include "plotSettings.h"
#include <QToolButton>
#include <QMouseEvent>
#include <QDebug>
#include <QVector>
#include <QStyleOptionFocusRect>

class Plotter : public QWidget
{
    Q_OBJECT
public:
    explicit Plotter(QWidget *parent = 0);

    void setPlotSettings(const PlotSettings &setting);
    void setCurveData(int id, const QVector<QPointF> &data);//曲线顶点存储 QPointF是一个浮点数形式的QPoint
    void clearCurve(int id);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    
signals:
    
public slots:
    void zoomIn();
    void zoomOut();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    void updateRubberBandRegion();
    void refreshPixmap();
    void drawGrid(QPainter *painter);
    void drawCurves(QPainter *painter);

    enum { Margin = 50 };

    QToolButton *zoomInButton;
    QToolButton *zoomOutButton;
    QMap<int, QVector<QPointF> > curveMap;//curveMap存储了所有的曲线通过 keys访问特定曲线
    QVector<PlotSettings> zoomStack;//用于保存不同缩放级设置值
    int curZoom;//在zoomStack中保存的PlotSettings的当前索引
    bool rubberBandIsShown;
    QRect rubberBandRect;
    QPixmap pixmap;
    
};


#endif // PLOTTER_H
