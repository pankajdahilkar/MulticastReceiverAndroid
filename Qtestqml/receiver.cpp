
#include <QtNetwork>
#include "receiver.h"
#include <QDebug>

Receiver::Receiver(): groupAddress4(QStringLiteral("239.255.43.21")),
    groupAddress6(QStringLiteral("ff12::2115"))
{
    udpSocket4.bind(QHostAddress::AnyIPv4, 45454, QUdpSocket::ShareAddress);
    udpSocket4.joinMulticastGroup(groupAddress4);

    if (!udpSocket6.bind(QHostAddress::AnyIPv6, 45454, QUdpSocket::ShareAddress) ||
            !udpSocket6.joinMulticastGroup(groupAddress6))
        qDebug()<<"Listening for multicast messages on IPv4 only";

    connect(&udpSocket4, SIGNAL(readyRead()),this, SLOT(processPendingDatagrams()));
    connect(&udpSocket6, &QUdpSocket::readyRead, this, &Receiver::processPendingDatagrams);
}

void Receiver::processPendingDatagrams()
{
    QByteArray datagram;

    // using QUdpSocket::readDatagram (API since Qt 4)
    while (udpSocket4.hasPendingDatagrams()) {
        datagram.resize(int(udpSocket4.pendingDatagramSize()));
        udpSocket4.readDatagram(datagram.data(), datagram.size());
        qDebug() <<" Received Dtatagram "<< datagram.constData();
        emit data_received(QString(datagram.constData()));
      /*  statusLabel->setText(tr("Received IPv4 datagram: \"%1\"")
                             .arg(datagram.constData()));
*/
}

    // using QUdpSocket::receiveDatagram (API since Qt 5.8)
    while (udpSocket6.hasPendingDatagrams()) {
        QNetworkDatagram dgram = udpSocket6.receiveDatagram();
      /*  statusLabel->setText(statusLabel->text() +
                             tr("\nReceived IPv6 datagram from [%2]:%3: \"%1\"")
                             .arg(dgram.data().constData(), dgram.senderAddress().toString())
                             .arg(dgram.senderPort()));
                             */
     qDebug() <<" Received Dtatagram "<< datagram.constData();

    }
}
