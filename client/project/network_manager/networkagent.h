#ifndef NETWORKAGENT_H
#define NETWORKAGENT_H

#include "networkmanager.h"
#include "msg_handler.h"

class NetworkAgent : public NetworkManager
{
public:
    NetworkAgent();
    static NetworkAgent & GetInstance();

    void SendToServer(const char *data, int length);
    virtual void OnRecvPackage(char *data, int length);

private:
    IPAddr server_ip_;
    Port server_port_;

    MessageHandler msg_handler_;
};

#endif // NETWORKAGENT_H
