#include "networkthread.h"
#include <QDataStream>
#include <QDebug>

NetworkThread::NetworkThread(QObject *parent) : QThread(parent) {}

void NetworkThread::run(){
    exec();
}

void NetworkThread::sendData(qreal val_a, qreal val_x, qreal val_y){
    QByteArray datagram;
    QDataStream stream(&datagram, QIODevice::WriteOnly);
    stream << val_a << val_x << val_y;

    udpSocket.writeDatagram(datagram, QHostAddress::LocalHost, 12345);

    emit dataSent(val_a, val_x, val_y);
    qDebug() << "Отправлено:" << val_a << val_x << val_y;
}
