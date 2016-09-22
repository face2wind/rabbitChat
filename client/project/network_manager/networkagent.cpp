#include "networkagent.h"

NetworkAgent::NetworkAgent() : server_ip_("192.168.11.29"), server_port_(52013), server_net_id_(0)
{
    NetworkManager::SyncConnect(server_ip_, server_port_);
}

NetworkAgent & NetworkAgent::GetInstance()
{
    static NetworkAgent instance;
    return instance;
}

void NetworkAgent::SendToServer(const char *data, int length)
{
    this->Send(data, length);
}
