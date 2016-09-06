#ifndef NETWORKAGENT_H
#define NETWORKAGENT_H

#include "networkmanager.h"

class NetworkAgent : public NetworkManager
{
public:
    NetworkAgent();
    static NetworkAgent & GetInstance();

    void SendToServer(const char *data, int length);

private:
    IPAddr server_ip_;
    Port server_port_;

    NetworkID server_net_id_;
};

#endif // NETWORKAGENT_H
