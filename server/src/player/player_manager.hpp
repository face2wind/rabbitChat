#pragma once

#include "base_type.hpp"
#include <network/network_manager.hpp>
#include <string>

class Player;

class PlayerManager
{
 public:
  static PlayerManager & GetInstance();

  ~PlayerManager();

  Player * GetPlayerWithAccountName(const std::string &acc_name);
  void OnRegisterPlayer(PlayerName name, Password passwd);
  void OnPlayerLogin(face2wind::NetworkID net_id, PlayerName name, Password passwd);
  
 protected:
  PlayerManager();

  
};
