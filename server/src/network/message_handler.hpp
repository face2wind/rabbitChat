#pragma once

#include <network/network_manager.hpp>

class MessageHandler;

typedef void (MessageHandler::*MessageHandlerFunc)(face2wind::NetworkID net_id, const char *data, int length);

class MessageHandler
{
 public:
  MessageHandler();
  ~MessageHandler();
  
  void OnRecv(face2wind::NetworkID net_id, const char *data, int length);

 protected:
  void OnLoginRequest(face2wind::NetworkID net_id, const char *data, int length);
  
 private:
  std::map<int, MessageHandlerFunc> handler_func_map_;
  
};
