#include "network_agent.hpp"
#include <iostream>

using namespace face2wind;

NetworkAgent::NetworkAgent()
{
  net_mgr_.RegistHandler(this);
}

NetworkAgent::~NetworkAgent()
{

}

void NetworkAgent::Listening()
{
  net_mgr_.SyncListen(52013);
  net_mgr_.WaitAllThread();
}

void NetworkAgent::OnListenFail(Port port)
{
  std::cout<<"OnListenFail !"<<std::endl;
}

void NetworkAgent::OnAccept(IPAddr ip, Port port, Port local_port, NetworkID net_id)
{
  std::cout<<"some one connect : " <<ip<<":"<<port<<", netid("<<net_id<<")"<<std::endl;
  net_mgr_.Send(net_id, "hi i am server", 15);
}

void NetworkAgent::OnConnect(IPAddr ip, Port port, Port local_port, bool success, NetworkID net_id)
{
}


void NetworkAgent::OnRecv(NetworkID net_id, const char *data, int length)
{
  std::cout<<"receive some one : netid("<<net_id<<") data ["<<data<<"]"<<std::endl;
}

void NetworkAgent::OnDisconnect(NetworkID net_id)
{
  std::cout<<"some one disconnect : netid("<<net_id<<")"<<std::endl;
}

  
