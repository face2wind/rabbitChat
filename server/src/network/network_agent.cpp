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

void NetworkAgent::OnListenFail(Port port)
{
  std::cout<<"OnListenFail !"<<std::endl;
}

void NetworkAgent::OnAccept(IPAddr ip, Port port, Port local_port, NetworkID net_id)
{
  std::cout<<"some one connect : " <<ip<<":"<<port<<", netid("<<net_id<<")"<<std::endl;

  net_mgr_.Send(net_id, "do you hear me?", 16);
  Timer::Sleep(1000);
  net_mgr_.Send(net_id, "hi i am server", 15);
  Timer::Sleep(4000);
  net_mgr_.Send(net_id, "hi i am server LiuGuobiao!", 27);
}

void NetworkAgent::OnRecv(NetworkID net_id, const char *data, int length)
{
  msg_handler_.OnRecv(net_id, data, length);
}

void NetworkAgent::OnDisconnect(NetworkID net_id)
{
  std::cout<<"some one disconnect : netid("<<net_id<<")"<<std::endl;
}

  
