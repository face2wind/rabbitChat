#include "networkmanager.h"
#include <string.h>

NetworkManager::NetworkManager(QObject *parent) : QTcpSocket(parent)
{
}

NetworkManager::~NetworkManager()
{

}

NetworkManager & NetworkManager::GetInstance()
{
    static NetworkManager instance;
    return instance;
}

void NetworkManager::RegistHandler(INetworkHandler *handler)
{

}

void NetworkManager::UnregistHandler(INetworkHandler *handler)
{

}

void NetworkManager::SyncListen(Port port)
{

}

void NetworkManager::SyncConnect(IPAddr ip, Port port)
{
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(OnConnect()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(OnRecv()));

    tcpSocket->abort();
    tcpSocket->connectToHost(ip, port);

    tcpSocket->waitForConnected();
    tcpSocket->waitForReadyRead();
}

void NetworkManager::Send(NetworkID net_id, const char *data, int length)
{
    int HEADER_LENGTH = 4;
    QByteArray bytearr;
    bytearr.append((char*)&length, HEADER_LENGTH);
    bytearr.append(data, length);
    qDebug()<<"write : "<<tcpSocket->write(bytearr);
    tcpSocket->flush();
}

void NetworkManager::Disconnect(NetworkID net_id)
{
    tcpSocket->close();
    disconnect(tcpSocket, SIGNAL(connected()), this, SLOT(OnConnect()));
    disconnect(tcpSocket, SIGNAL(readyRead()), this, SLOT(OnRecv()));
    delete tcpSocket;
}

// protected:
void NetworkManager::OnAccept(IPAddr remote_ip, Port remote_port, Port local_port)
{

}

void NetworkManager::OnConnect()
{
    //IPAddr remote_ip, Port remote_port, Port local_port
qDebug()<<"<<<< has connect <<<<<<<<<";
}

void NetworkManager::OnRecv()
{
    //IPAddr ip, Port port, Port local_port, char *data, int length
    QByteArray data = tcpSocket->readAll();
    int *my_int = (int*)data.data();
    char *msg = data.data()+4;
   qDebug()<<"receive : ["<<msg<<"] size("<<data.size()-4<<")";
    //qDebug()<<*my_int<<"<<<<<<<<<<<<<";
}

void NetworkManager::OnDisconnect(IPAddr ip, Port port, Port local_port)
{

}

void NetworkManager::SendRaw(NetworkID net_id, const char *data, int length)
{

}

void NetworkManager::OnRecvPackage(NetworkID net_id, char *data, int length)
{

}
