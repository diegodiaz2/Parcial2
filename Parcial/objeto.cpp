#include "objeto.h"
#include "mainwindow.h"

objeto::objeto()
{
    posx=-250+rand()%(500);
    posy =260;
    y0=posy;
    ay=1+rand()%8;
    //Le damos una posicion inicial
    setPos(posx,-posy);
    QTimer *t=new QTimer();
    //Conectamos la funcion movimiento al timer
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
}

QRectF objeto::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void objeto::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Le damos un color verde
    painter->setBrush(Qt::GlobalColor::darkRed);
    painter->drawEllipse(boundingRect());
}

void objeto::borrar()
{
    MainWindow *mv=MainWindow::getMainWinPtr();
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if (typeid (*(colliding_items[i])) == typeid(planetas)){
            mv->escena->removeItem(this);
//            QPainter *pa=new QPainter();
//            pa->setPen(Qt::black);
//            pa->drawEllipse(boundingRect());
//            const QStyleOptionGraphicsItem *option;
//            colliding_items[i]->paint(pa,option);
            delete this;
            return;
        }
    }
    //Cuando el objeto se encuentre fuera del escenario sera eliminado
}

void objeto::movimiento()
{
    if(posy<=-250){
        vely=-vely;
    }
    posy=posy+vely-(ay)/2;
    vely=vely-(ay);
    setPos(int(posx),-int(posy));
    borrar();
}
