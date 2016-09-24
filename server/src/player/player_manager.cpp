#include "player_manager.hpp"
#include "player.hpp"
#include "net_msg/login_msg.hpp"
#include "network/network_agent.hpp"

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

Player * PlayerManager::GetPlayer(const std::string &acc_name)
{
  if ("" == acc_name)
    return nullptr;

  auto p_it = name_to_player_map_.find(acc_name);
  if (p_it == name_to_player_map_.end())
    return nullptr;

  return p_it->second;
}

Player * PlayerManager::GetPlayer(face2wind::NetworkID net_id)
{
  if (net_id <= 0)
    return nullptr;

  auto p_it = net_id_to_player_map_.find(net_id);
  if (p_it == net_id_to_player_map_.end())
    return nullptr;

  return p_it->second;
}

Player * PlayerManager::GetPlayerWithPlayerID(unsigned int player_id)
{
  if (player_id >= player_list_.size())
    return nullptr;

  return player_list_[player_id];
}

void PlayerManager::OnRegisterPlayer(face2wind::NetworkID net_id, PlayerName name, Password passwd)
{
  static protocol::SCLoginResult msg;
  if (name_to_player_map_.find(name) != name_to_player_map_.end())
  {
    msg.result = protocol::MsgLoginResult_ALEADY_HAS_ACCOUNT;
  }
  else
  {
    unsigned int new_player_id = player_list_.size();
    Player *player = new Player();
    player->SetID(new_player_id);
    player->SetName(name);
    player->SetPassword(passwd);
    player_list_.push_back(player);
    msg.result = protocol::MsgLoginResult_REGISTER_SUCC;
  }
  NetworkAgent::GetInstance().Send(net_id, (char*)&msg, sizeof(msg));
}

void PlayerManager::OnPlayerLogin(face2wind::NetworkID net_id, PlayerName name, Password passwd)
{
  static protocol::SCLoginResult msg;
  Player *p = this->GetPlayer(name);
  if (nullptr != p)
  {
    if (p->CheckPassword(passwd))
    {
      msg.result = protocol::MsgLoginResult_LOGIN_SUCC;
      p->OnLogin();
      p->SetNetID(net_id);
      net_id_to_player_map_[net_id] = p;
    }
    else
    {
      msg.result = protocol::MsgLoginResult_PASSWD_WRONG;
    }
  }
  else
  {
    msg.result = protocol::MsgLoginResult_NO_THIS_ACCOUNT;
  }
  NetworkAgent::GetInstance().Send(net_id, (char*)&msg, sizeof(msg));
}

