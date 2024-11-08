#include "server.h"
#include "./ui_server.h"

Server::Server(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Server)
    , networkThread(new NetworkThread()){

    ui->setupUi(this);

    ui->Slider_a->setRange(2, 5);
    ui->Slider_x->setRange(-100, 100);
    ui->Slider_y->setRange(-100, 100);

    ui->label_a->setText(QString::number(ui->Slider_a->value()));
    ui->label_x->setText(QString::number(ui->Slider_x->value() / 100.0, 'f', 2));
    ui->label_y->setText(QString::number(ui->Slider_y->value() / 100.0, 'f', 2));

    networkThread->start();
}

Server::~Server(){
    networkThread->quit();
    networkThread->wait();
    delete networkThread;
    delete ui;
}

void Server::on_Slider_a_valueChanged(int value){
    ui->label_a->setText(QString::number(value));
}

void Server::on_Slider_x_valueChanged(int value){
    qreal val_x = value / 100.0;
    ui->label_x->setText(QString::number(val_x, 'f', 2));
}

void Server::on_Slider_y_valueChanged(int value){
    qreal val_y = value / 100.0;
    ui->label_y->setText(QString::number(val_y, 'f', 2));
}

void Server::on_Button_clicked(){
    qreal val_a = ui->Slider_a->value();
    qreal val_x = ui->Slider_x->value() / 100.0;
    qreal val_y = ui->Slider_y->value() / 100.0;

    networkThread->sendData(val_a, val_x, val_y);
}



