#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <string>
#include <QtNetwork>

typedef quint16 Port;
typedef QString IPAddr;
typedef int NetworkID;

class INetworkHandler
{
public:
    virtual void OnListenFail(Port port) = 0;
    virtual void OnAccept(IPAddr ip, Port port, Port local_port, NetworkID net_id) = 0;
    virtual void OnConnect(IPAddr ip, Port port, Port local_port, bool success, NetworkID net_id) = 0;

    virtual void OnRecv(NetworkID net_id, const char *data, int length) = 0;
    virtual void OnDisconnect(NetworkID net_id) = 0;
};

class NetworkManager : public QObject
{
public:
    NetworkManager();
    ~NetworkManager();

    static NetworkManager & GetInstance();

    void RegistHandler(INetworkHandler *handler);
    void UnregistHandler(INetworkHandler *handler);

    void SyncListen(Port port);
    void SyncConnect(IPAddr ip, Port port);

    void Send(NetworkID net_id, const char *data, int length);
    void Disconnect(NetworkID net_id);

protected:
    void OnAccept(IPAddr remote_ip, Port remote_port, Port local_port);
    void OnConnect();
    void OnRecv();
    void OnDisconnect(IPAddr ip, Port port, Port local_port);

    void SendRaw(NetworkID net_id, const char *data, int length);
    void OnRecvPackage(NetworkID net_id, char *data, int length);

private:
    QTcpSocket *tcpSocket;
};

#endif // NETWORKMANAGER_H
