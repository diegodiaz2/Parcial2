#ifndef OBJETO_H
#define OBJETO_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class objeto:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    int r=4;
    double posx, posy,y0;
    double vely,ay;
    double yd;
    objeto();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void borrar();
public slots:
    void movimiento();
};

#endif // OBJETO_H
