#pragma once

#include "message_handler.hpp"

#include <network/network_manager.hpp>
#include <elegance.hpp>

class NetworkAgent : public face2wind::INetworkHandler
{
public:
  NetworkAgent();
  ~NetworkAgent();
  
  void Listening();

  virtual void OnListenFail(face2wind::Port port);
  virtual void OnAccept(face2wind::IPAddr ip, face2wind::Port port, face2wind::Port local_port, face2wind::NetworkID net_id);
  virtual void OnConnect(face2wind::IPAddr ip, face2wind::Port port, face2wind::Port local_port, bool success, face2wind::NetworkID net_id) {}

  virtual void OnRecv(face2wind::NetworkID net_id, const char *data, int length);
  virtual void OnDisconnect(face2wind::NetworkID net_id);
  
private:
  face2wind::NetworkManager net_mgr_;

  MessageHandler msg_handler_;
};
