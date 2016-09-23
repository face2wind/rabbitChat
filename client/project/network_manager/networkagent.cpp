#include "networkagent.h"

NetworkAgent::NetworkAgent() : server_ip_("127.0.0.1"), server_port_(52013)
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

void NetworkAgent::OnRecvPackage(char *data, int length)
{
    NetworkManager::OnRecvPackage(data, length);

    msg_handler_.OnRecv(data, length);
}
