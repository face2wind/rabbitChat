#include "networkagent.h"
#include "ui/ui_manager.hpp"

NetworkAgent::NetworkAgent() : server_ip_("192.168.11.29"), server_port_(52013)
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

void NetworkAgent::OnDisconnect()
{
    NetworkManager::OnDisconnect();

    UIManager::GetInstance().ShowLogin();
    NetworkManager::SyncConnect(server_ip_, server_port_);
}