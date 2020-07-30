#ifndef PLANETAS_H
#define PLANETAS_H

#include <QGraphicsItem>
#include <QPainter>

class planetas: public QGraphicsItem
{
    double r;
    double posx, posy, vx, vy, m;
public:
    int n;
    planetas(int planeta,double r_, double x, double y,double vxo, double vyo, double mo);
    void actualizar(double x, double y,double vxo, double vyo);
    void setPosx(double px);
    void setPosy(double py);
    double getR();
    double getPosx();
    double getPosy();
    double getVx();
    double getVy();
    double getM();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PLANETAS_H
