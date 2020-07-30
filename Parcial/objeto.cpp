#include "objeto.h"
#include "mainwindow.h"

objeto::objeto()
{
    posx=-250+rand()%(-250+250+1);
    posy =-260;
    y0=posy;
    ay=1+rand()%10;
    //Le damos una posicion inicial
    setPos(posx,posy);
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
//    //Se verifican las colisiones
//    MainWindow *mv=MainWindow::getMainWinPtr();
//    QList<QGraphicsItem *> colliding_items=collidingItems();
//    for(int i=0, n=colliding_items.size(); i<n; i++){
//        if (typeid (*(colliding_items[i])) == typeid(personaje)){
//            //Se disminuye la vida del personaje y es removida la bala
//            mv->vida(1);
//            mv->escena->removeItem(this);
//            delete this;
//            return;
//        }
//    }
//    //Cuando el objeto se encuentre fuera del escenario sera eliminado
//    if(posx<0 or posx>1786){
//        mv->escena->removeItem(this);
//        delete this;
//        return;
//    }
//    else if(yd>570){
//        mv->escena->removeItem(this);
//        delete this;
//        return;
//    }
//    //Cuando el usuario muere el objeto se elimina
//    if(mv->vidas<=0){
//        mv->escena->removeItem(this);
//        delete this;
//        return;
//    }
}

void objeto::movimiento()
{
    posy=posy+vely-(ay)/2;
    vely=vely-(ay);
    yd=2*y0-posy;
    setPos(int(posx),int(yd));
    //borrar();
}
