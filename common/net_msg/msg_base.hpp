#pragma once

namespace protocol {

struct MsgHead
{
  MsgHead(short code) : msg_code(code), reserve_sh(0) {}
  
  short msg_code;
  short reserve_sh;
};

}

