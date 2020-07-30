#include "planetas.h"

planetas::planetas(int planeta,double r_, double x, double y,double vxo, double vyo, double mo)
{
    n=planeta;
    r = r_/20;
    posx = x/20;
    posy = y/20;
    setPos(posx,posy);
    vx=vxo;
    vy=vyo;
    m=mo;
}

void planetas::actualizar(double x, double y, double vxo, double vyo)
{
    posx=x/20;
    posy=y/20;
    vx=vxo;
    vy=vyo;
}

void planetas::setPosx(double px)
{
    posx=px;
}

void planetas::setPosy(double py)
{
    posy=py;
}

double planetas::getR()
{
    return r*20;
}

double planetas::getPosx()
{
    return posx*20;
}

double planetas::getPosy()
{
    return posy*20;
}

double planetas::getVx()
{
    return vx;
}

double planetas::getVy()
{
    return vy;
}

double planetas::getM()
{
    return m;
}

QRectF planetas::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void planetas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(n==1){
        painter->setBrush(Qt::black);
        painter->drawEllipse(boundingRect());
    }
    else if(n==2){
        painter->setBrush(Qt::yellow);
        painter->drawEllipse(boundingRect());
    }
    else if(n==3){
        painter->setBrush(Qt::blue);
        painter->drawEllipse(boundingRect());
    }
    else if(n==4){
        painter->setBrush(Qt::green);
        painter->drawEllipse(boundingRect());
    }
    else{
        painter->setBrush(Qt::red);
        painter->drawEllipse(boundingRect());
    }
}
