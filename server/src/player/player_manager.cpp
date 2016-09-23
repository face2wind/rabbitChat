#include "player_manager.hpp"
#include "player.hpp"
#include "net_msg/login_msg.hpp"

PlayerManager::PlayerManager()
{

}

PlayerManager::~PlayerManager()
{

}

PlayerManager & PlayerManager::GetInstance()
{
  static PlayerManager instance;
  return instance;
}

Player * GetPlayerWithAccountName(const std::string &acc_name)
{
  return nullptr;
}
void PlayerManager::OnRegisterPlayer(PlayerName name, Password passwd)
{

}

void PlayerManager::OnPlayerLogin(face2wind::NetworkID net_id, PlayerName name, Password passwd)
{
  static protocol::SCLoginResult msg;
  msg->result = MsgLoginResult::LOGIN_SUCC;
  NetworkManager::GetInstance().Send(net_id, (char*)&result, sizeof(result));
}

