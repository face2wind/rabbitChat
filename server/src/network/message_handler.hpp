#pragma once

#include <network/network_manager.hpp>

class MessageHandler
{
 public:
  void OnRecv(face2wind::NetworkID net_id, const char *data, int length);

};
