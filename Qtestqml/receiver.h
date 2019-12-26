#ifndef RECEIVER_H
#define RECEIVER_H
#include <QHostAddress>
#include <QUdpSocket>


class Receiver : public QObject
{
    Q_OBJECT
public:
    Receiver();
signals:
    void data_received(const QString &text);

private slots:
    void processPendingDatagrams();

private:
    QUdpSocket udpSocket4;
    QUdpSocket udpSocket6;
    QHostAddress groupAddress4;
    QHostAddress groupAddress6;
};

#endif // RECEIVER_H
