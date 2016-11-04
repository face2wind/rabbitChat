#include "player.hpp"
#include "network/network_agent.hpp"
#include "protocol_def.hpp"

void Player::OnLogin()
{
  is_online_ = true;
}

void Player::OnLogout()
{
  is_online_ = false;
  if (net_id_ > 0) // disconnect old client
    NetworkAgent::GetInstance().Disconnect(net_id_);
}

void Player::OnRequestFriendList()
{
  std::cout<<"Player::OnRequestFriendList"<<std::endl;
  static Protocol::SCFriendList friend_list;
  for (auto friend_id : friend_id_vec_)
  {
    Protocol::UserItem item;
    item.id = friend_id;
    item.name = "temp_name";
    friend_list.friend_list.push_back(item);
  }
  NetworkAgent::GetInstance().SendSerialize(net_id_, friend_list);
}
