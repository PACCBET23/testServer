#ifndef NETWORKTHREAD_H
#define NETWORKTHREAD_H

#include <QThread>
#include <QUdpSocket>
#include <QHostAddress>

class NetworkThread : public QThread
{
    Q_OBJECT

public:
    NetworkThread(QObject *parent = nullptr);
    void run() override;

signals:
    void dataSent(qreal label_a, qreal val_x, qreal val_y);

public slots:
    void sendData(qreal label_a, qreal val_x, qreal val_y);

private:
    QUdpSocket udpSocket;
};

#endif // NETWORKTHREAD_H
