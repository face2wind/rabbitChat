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

NetworkAgent & NetworkAgent::GetInstance()
{
  static NetworkAgent instance;
  return instance;
}

void NetworkAgent::Listening()
{
  net_mgr_.SyncListen(52013);
  net_mgr_.WaitAllThread();
}

void NetworkAgent::Send(NetworkID net_id, const char *data, int length)
{
  net_mgr_.Send(net_id, data, length);
}

void NetworkAgent::Disconnect(face2wind::NetworkID net_id)
{
  net_mgr_.Disconnect(net_id);
}

void NetworkAgent::OnListenFail(Port port)
{
  std::cout<<"OnListenFail !"<<std::endl;
}

void NetworkAgent::OnAccept(IPAddr ip, Port port, Port local_port, NetworkID net_id)
{
  std::cout<<"some one connect : " <<ip<<":"<<port<<", netid("<<net_id<<")"<<std::endl;
}

void NetworkAgent::OnRecv(NetworkID net_id, const char *data, int length)
{
  msg_handler_.OnRecv(net_id, data, length);
}

void NetworkAgent::OnDisconnect(NetworkID net_id)
{
  std::cout<<"some one disconnect : netid("<<net_id<<")"<<std::endl;
}

  
