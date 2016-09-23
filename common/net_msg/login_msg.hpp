#pragma once

#include "base_type.hpp"
#include "msg_base.hpp"

namespace protocol {

struct CSRegisterAccount
{
  CSRegisterAccount() : head(10000) {}
  
  MsgHead head;

  PlayerName name;
  Password passwd;
};

struct CSLogin
{
  CSLogin() : head(10001) {}

  MsgHead head;

  PlayerName name;
  Password passwd;
};

enum class MsgLoginResult
{
  LOGIN_SUCC,
  NO_THIS_ACCOUNT,
  PASSWD_WRONG,
};

struct SCLoginResult
{
  SCLoginResult() : head(10002) {}

  MsgHead head;

  int result;
};

}
