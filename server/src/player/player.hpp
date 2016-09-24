#pragma once

#include <string>
#include <network/network_manager.hpp>

class Player
{
 public:
  unsigned int GetID() { return player_id_; }
  void SetID(unsigned int new_player_id) { player_id_ = new_player_id; }

  const std::string & GetName() { return player_name_; }
  void SetName(const std::string &name) { player_name_ = name; }

  bool CheckPassword(const std::string &passwd) { return (password_ == passwd); }
  void SetPassword(const std::string &passwd) { password_ = passwd; }

  face2wind::NetworkID GetNetID() { return net_id_; }
  void SetNetID(face2wind::NetworkID net_id) { net_id_ = net_id; }
  
  void OnLogin();
  void OnLogout();

 private:
  std::string player_name_;
  std::string password_;
  unsigned int player_id_;
  face2wind::NetworkID net_id_;
  bool is_online_;
  
};
