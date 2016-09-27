#pragma once

#include "base_type.hpp"
#include "msg_base.hpp"

namespace protocol {

struct CSRequestFriendList
{
  CSRequestFriendList() : head(11000) {}
  
  MsgHead head;
};

static const int MSG_FRIEND_LIST_MAX_COUNT = 20;
struct SCFriendList
{
  SCFriendList() : head(11000) {}

  MsgHead head;

  struct FriendItem
  {
    unsigned int player_id;
    PlayerName name;
  };

  FriendItem friend_list[MSG_FRIEND_LIST_MAX_COUNT];
};

}
