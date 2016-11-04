#pragma once

#include <network/network_manager.hpp>
#include <string>
#include <vector>
#include <map>

class Player;

class PlayerManager
{
 public:
  static PlayerManager & GetInstance();

  ~PlayerManager();

  Player * GetPlayer(const std::string &acc_name);
  Player * GetPlayer(face2wind::NetworkID net_id);
  Player * GetPlayerWithPlayerID(unsigned int player_id);

  void OnClientDisconnect(face2wind::NetworkID net_id);

  void OnRegisterPlayer(face2wind::NetworkID net_id, std::string name, std::string passwd);
  void OnPlayerLogin(face2wind::NetworkID net_id, std::string name, std::string passwd);
  void OnRequestFriendList(face2wind::NetworkID net_id);
  void OnRequestAllUserList(face2wind::NetworkID net_id);
  
 protected:
  PlayerManager();


 private:
  std::vector<Player*> player_list_; // create from here, not allow delete
  std::map<face2wind::NetworkID, Player*> net_id_to_player_map_;
  std::map<std::string, Player*> name_to_player_map_;
};
