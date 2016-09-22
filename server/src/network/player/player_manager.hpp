#pragma once

#include "base_type.hpp"
#include <network/network_manager.hpp>

class PlayerManager
{
 public:
  static PlayerManager & GetInstance();

  ~PlayerManager();

  void OnRegisterPlayer(PlayerName name, Password passwd);
  void OnPlayerLogin(face2wind::NetworkID net_id, PlayerName name, Password passwd);
  
 protected:
  PlayerManager();

  
};
