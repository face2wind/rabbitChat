#include "player_manager.hpp"
#include "player.hpp"
#include "protocol_def.hpp"
#include "message_code.hpp"
#include "network/network_agent.hpp"

using namespace Protocol;

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

void PlayerManager::OnClientDisconnect(face2wind::NetworkID net_id)
{
  Player *player = GetPlayer(net_id);
  if (nullptr != player)
    player->SetNetID(0);
  
  net_id_to_player_map_[net_id] = nullptr;
}

void PlayerManager::OnRegisterPlayer(face2wind::NetworkID net_id, std::string name, std::string passwd)
{
  static SCLoginResult msg;
  if (name_to_player_map_.find(name) != name_to_player_map_.end())
  {
    msg.result = MessageCode_ALEADY_HAS_ACCOUNT;
  }
  else
  {
    unsigned int new_player_id = (unsigned int)player_list_.size();
    Player *player = new Player();
    player->SetID(new_player_id);
    player->SetName(name);
    player->SetPassword(passwd);
    player_list_.push_back(player);
    name_to_player_map_[name] = player;
    msg.result = MessageCode_REGISTER_SUCC;
  }
  NetworkAgent::GetInstance().SendSerialize(net_id, msg);
}

void PlayerManager::OnPlayerLogin(face2wind::NetworkID net_id, std::string name, std::string passwd)
{
  static SCLoginResult msg;
  Player *p = this->GetPlayer(name);
  if (nullptr != p)
  {
    if (p->CheckPassword(passwd))
    {
      if (p->GetNetID() == net_id) // same connection cannot login 2 times
        return;

      if (p->GetNetID() > 0) // other client with same name connect , disconnect it
        NetworkAgent::GetInstance().Disconnect(p->GetNetID());
      
      msg.result = MessageCode_LOGIN_SUCC;
      p->OnLogin();
      p->SetNetID(net_id);
      net_id_to_player_map_[net_id] = p;
    }
    else
    {
      msg.result = MessageCode_PASSWD_WRONG;
    }
  }
  else
  {
    msg.result = MessageCode_NO_THIS_ACCOUNT;
  }
  NetworkAgent::GetInstance().SendSerialize(net_id, msg);
}

void PlayerManager::OnRequestFriendList(face2wind::NetworkID net_id)
{
  Player *p = this->GetPlayer(net_id);
  if (nullptr == p)
    return;

  p->OnRequestFriendList();
}

void PlayerManager::OnRequestAllUserList(face2wind::NetworkID net_id)
{
  Player *p = this->GetPlayer(net_id);
  if (nullptr == p)
    return;

  static SCAllUserList msg;
  msg.user_list.clear();
  for (Player *tmp_player : player_list_)
  {
    if (tmp_player != p && tmp_player->GetNetID() != 0) // online and not current player
    {
      UserItem p_item;
      p_item.id = tmp_player->GetID();
      p_item.name = tmp_player->GetName();
      msg.user_list.push_back(p_item);
    }
  }
  NetworkAgent::GetInstance().SendSerialize(net_id, msg);
}

void PlayerManager::OnChatToUser(face2wind::NetworkID net_id, int user_id, const std::string &message)
{
  Player *user = this->GetPlayer(net_id);
  Player *target_user = this->GetPlayerWithPlayerID(user_id);
  if (nullptr == user || nullptr == target_user)
    return;

  static SCChatToUser msg;
  msg.sender_user_id = user->GetID();
  msg.receiver_user_id = target_user->GetID();
  msg.chat_message = message;
  NetworkAgent::GetInstance().SendSerialize(net_id, msg);
  NetworkAgent::GetInstance().SendSerialize(target_user->GetNetID(), msg);
}
