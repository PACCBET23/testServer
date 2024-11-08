#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QUdpSocket>
#include "networkthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Server; }
QT_END_NAMESPACE

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();

private slots:
    void on_Slider_a_valueChanged(int value);
    void on_Slider_x_valueChanged(int value);
    void on_Slider_y_valueChanged(int value);

    void on_Button_clicked();


private:
    Ui::Server *ui;
    NetworkThread *networkThread;
};

#endif // SERVER_H
