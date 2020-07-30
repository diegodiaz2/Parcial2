#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    t= new QTimer;
    escena= new QGraphicsScene;
    escena->setSceneRect(0,0,1,1);
    ui->graphicsView->setScene(escena);
    planeta1=new planetas(1,200,0,0,0,0,50000);
    escena->addItem(planeta1);
    planeta2=new planetas(2,70,-5000,0,0,-2,70);
    escena->addItem(planeta2);
    planeta3=new planetas(3,70,5000,0,0,2,70);
    escena->addItem(planeta3);
    planeta4=new planetas(4,70,0,5000,2,0,70);
    escena->addItem(planeta4);
    planeta5=new planetas(5,70,0,-5000,-2,0,70);
    escena->addItem(planeta5);
    connect(t,SIGNAL(timeout()),this,SLOT(ejecutar()));
    t->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::ejecutar()
{
    double p1[5]={planeta1->getPosx(),planeta1->getPosy(),planeta1->getVx(),planeta1->getVy(),planeta1->getM()};
    double x,y,vx,vy,ax,ay; //g=6.6738*(pow(10,-11))

    double p2[5]={planeta2->getPosx(),planeta2->getPosy(),planeta2->getVx(),planeta2->getVy(),planeta2->getM()};
    double p3[5]={planeta3->getPosx(),planeta3->getPosy(),planeta3->getVx(),planeta3->getVy(),planeta3->getM()};
    double p4[5]={planeta4->getPosx(),planeta4->getPosy(),planeta4->getVx(),planeta4->getVy(),planeta4->getM()};
    double p5[5]={planeta5->getPosx(),planeta5->getPosy(),planeta5->getVx(),planeta5->getVy(),planeta5->getM()};
    double p6[5]={0,0,0,0,0};

    x=p2[0];
    y=p2[1];
    ax=(((p1[4])/pow(sqrt(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2)),3))*(p1[0]-p2[0]))+(((p3[4])/pow(sqrt(pow(p3[0]-p2[0],2)+pow(p3[1]-p2[1],2)),3))*(p3[0]-p2[0]))+(((p4[4])/pow(sqrt(pow(p4[0]-p2[0],2)+pow(p4[1]-p2[1],2)),3))*(p4[0]-p2[0]))+(((p5[4])/pow(sqrt(pow(p5[0]-p2[0],2)+pow(p5[1]-p2[1],2)),3))*(p5[0]-p2[0]))+(((p6[4])/pow(sqrt(pow(p6[0]-p2[0],2)+pow(p6[1]-p2[1],2)),3))*(p6[0]-p2[0]));
    ay=(((p1[4])/pow(sqrt(pow(p1[0]-p2[0],2)+pow(p1[1]-p2[1],2)),3))*(p1[1]-p2[1]))+(((p3[4])/pow(sqrt(pow(p3[0]-p2[0],2)+pow(p3[1]-p2[1],2)),3))*(p3[1]-p2[1]))+(((p4[4])/pow(sqrt(pow(p4[0]-p2[0],2)+pow(p4[1]-p2[1],2)),3))*(p4[1]-p2[1]))+(((p5[4])/pow(sqrt(pow(p5[0]-p2[0],2)+pow(p5[1]-p2[1],2)),3))*(p5[1]-p2[1]))+(((p6[4])/pow(sqrt(pow(p6[0]-p2[0],2)+pow(p6[1]-p2[1],2)),3))*(p6[1]-p2[1]));
    vx=p2[2]+ax;
    vy=p2[3]+ay;
    x=x+vx;
    y=y+vy;
    planeta2->setPos(x/20,-y/20);
    planeta2->actualizar(x,y,vx,vy);

    x=p3[0];
    y=p3[1];
    ax=(((p1[4])/pow(sqrt(pow(p1[0]-p3[0],2)+pow(p1[1]-p3[1],2)),3))*(p1[0]-p3[0]))+(((p2[4])/pow(sqrt(pow(p2[0]-p3[0],2)+pow(p2[1]-p3[1],2)),3))*(p2[0]-p3[0]))+(((p4[4])/pow(sqrt(pow(p4[0]-p3[0],2)+pow(p4[1]-p3[1],2)),3))*(p4[0]-p3[0]))+(((p5[4])/pow(sqrt(pow(p5[0]-p3[0],2)+pow(p5[1]-p3[1],2)),3))*(p5[0]-p3[0]))+(((p6[4])/pow(sqrt(pow(p6[0]-p3[0],2)+pow(p6[1]-p3[1],2)),3))*(p6[0]-p3[0]));
    ay=(((p1[4])/pow(sqrt(pow(p1[0]-p3[0],2)+pow(p1[1]-p3[1],2)),3))*(p1[1]-p3[1]))+(((p2[4])/pow(sqrt(pow(p2[0]-p3[0],2)+pow(p2[1]-p3[1],2)),3))*(p2[1]-p3[1]))+(((p4[4])/pow(sqrt(pow(p4[0]-p3[0],2)+pow(p4[1]-p3[1],2)),3))*(p4[1]-p3[1]))+(((p5[4])/pow(sqrt(pow(p5[0]-p3[0],2)+pow(p5[1]-p3[1],2)),3))*(p5[1]-p3[1]))+(((p6[4])/pow(sqrt(pow(p6[0]-p3[0],2)+pow(p6[1]-p3[1],2)),3))*(p6[1]-p3[1]));
    vx=p3[2]+ax;
    vy=p3[3]+ay;
    x=x+vx;
    y=y+vy;
    planeta3->setPos(x/20,-y/20);
    planeta3->actualizar(x,y,vx,vy);

    x=p4[0];
    y=p4[1];
    ax=(((p1[4])/pow(sqrt(pow(p1[0]-p4[0],2)+pow(p1[1]-p4[1],2)),3))*(p1[0]-p4[0]))+(((p3[4])/pow(sqrt(pow(p3[0]-p4[0],2)+pow(p3[1]-p4[1],2)),3))*(p3[0]-p4[0]))+(((p2[4])/pow(sqrt(pow(p2[0]-p4[0],2)+pow(p2[1]-p4[1],2)),3))*(p2[0]-p4[0]))+(((p5[4])/pow(sqrt(pow(p5[0]-p4[0],2)+pow(p5[1]-p4[1],2)),3))*(p5[0]-p4[0]))+(((p6[4])/pow(sqrt(pow(p6[0]-p4[0],2)+pow(p6[1]-p4[1],2)),3))*(p6[0]-p4[0]));
    ay=(((p1[4])/pow(sqrt(pow(p1[0]-p4[0],2)+pow(p1[1]-p4[1],2)),3))*(p1[1]-p4[1]))+(((p3[4])/pow(sqrt(pow(p3[0]-p4[0],2)+pow(p3[1]-p4[1],2)),3))*(p3[1]-p4[1]))+(((p2[4])/pow(sqrt(pow(p2[0]-p4[0],2)+pow(p2[1]-p4[1],2)),3))*(p2[1]-p4[1]))+(((p5[4])/pow(sqrt(pow(p5[0]-p4[0],2)+pow(p5[1]-p4[1],2)),3))*(p5[1]-p4[1]))+(((p6[4])/pow(sqrt(pow(p6[0]-p4[0],2)+pow(p6[1]-p4[1],2)),3))*(p6[1]-p4[1]));
    vx=p4[2]+ax;
    vy=p4[3]+ay;
    x=x+vx;
    y=y+vy;
    planeta4->setPos(x/20,-y/20);
    planeta4->actualizar(x,y,vx,vy);

    x=p5[0];
    y=p5[1];
    ax=(((p1[4])/pow(sqrt(pow(p1[0]-p5[0],2)+pow(p1[1]-p5[1],2)),3))*(p1[0]-p5[0]))+(((p3[4])/pow(sqrt(pow(p3[0]-p5[0],2)+pow(p3[1]-p5[1],2)),3))*(p3[0]-p5[0]))+(((p4[4])/pow(sqrt(pow(p4[0]-p5[0],2)+pow(p4[1]-p5[1],2)),3))*(p4[0]-p5[0]))+(((p2[4])/pow(sqrt(pow(p2[0]-p5[0],2)+pow(p2[1]-p5[1],2)),3))*(p2[0]-p5[0]))+(((p6[4])/pow(sqrt(pow(p6[0]-p5[0],2)+pow(p6[1]-p5[1],2)),3))*(p6[0]-p5[0]));
    ay=(((p1[4])/pow(sqrt(pow(p1[0]-p5[0],2)+pow(p1[1]-p5[1],2)),3))*(p1[1]-p5[1]))+(((p3[4])/pow(sqrt(pow(p3[0]-p5[0],2)+pow(p3[1]-p5[1],2)),3))*(p3[1]-p5[1]))+(((p4[4])/pow(sqrt(pow(p4[0]-p5[0],2)+pow(p4[1]-p5[1],2)),3))*(p4[1]-p5[1]))+(((p2[4])/pow(sqrt(pow(p2[0]-p5[0],2)+pow(p2[1]-p5[1],2)),3))*(p2[1]-p5[1]))+(((p6[4])/pow(sqrt(pow(p6[0]-p5[0],2)+pow(p6[1]-p5[1],2)),3))*(p6[1]-p5[1]));
    vx=p5[2]+ax;
    vy=p5[3]+ay;
    x=x+vx;
    y=y+vy;
    planeta5->setPos(x/20,-y/20);
    planeta5->actualizar(x,y,vx,vy);
}
