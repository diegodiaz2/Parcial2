#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "planetas.h"
#include "objeto.h"

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void ejecutar();

private:
    Ui::MainWindow *ui;
    int k, n=0, n_planetas=0;
    double xo,yo,vxo,vyo, T=0.01, a=-9.8;
    QTimer *t;
    QGraphicsScene *escena;
    planetas *planeta1;
    planetas *planeta2;
    planetas *planeta3;
    planetas *planeta4;
    planetas *planeta5;
    objeto *bola;
};
#endif // MAINWINDOW_H
