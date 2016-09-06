#include "networkagent.h"

NetworkAgent::NetworkAgent() : server_ip_("127.0.0.1"), server_port_(8888), server_net_id_(0)
{

}

NetworkAgent & NetworkAgent::GetInstance()
{
    static NetworkAgent instance;
    return instance;
}

void NetworkAgent::SendToServer(const char *data, int length)
{
    this->Send(server_net_id_, data, length);
}
