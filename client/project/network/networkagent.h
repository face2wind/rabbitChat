#ifndef NETWORKAGENT_H
#define NETWORKAGENT_H

#include "memory/serialize/serialize_manager.hpp"
#include "msg_handler.h"

class NetworkAgent : public face2wind::SerializeNetworkManager
{
public:
    NetworkAgent();
    static NetworkAgent & GetInstance();

    void OnConnect();
    void SendToServer(const char *data, int length);
    virtual void OnRecvPackage(char *data, int length);
    void OnDisconnect();
    bool HasConnected() { return has_connected_; }
    void ConnectToServer();

private:
    IPAddr server_ip_;
    Port server_port_;

    bool has_connected_;
    MessageHandler msg_handler_;
};

#endif // NETWORKAGENT_H
