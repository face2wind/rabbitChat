#include "networkmanager.h"

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
}

void NetworkManager::Send(NetworkID net_id, const char *data, int length)
{
    QByteArray bytearr;
    bytearr.append(data, length);
    tcpSocket->write(bytearr);
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
    qDebug()<<*my_int<<"<<<<<<<<<<<<<";
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
