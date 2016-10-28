#include "protocol_def.hpp"

namespace Protocol {

__CSRegisterAccountDescribe__ for_describe_register_to___csregisteraccountdescribe__;
__CSLoginDescribe__ for_describe_register_to___cslogindescribe__;
__SCLoginResultDescribe__ for_describe_register_to___scloginresultdescribe__;
__CSRequestFriendListDescribe__ for_describe_register_to___csrequestfriendlistdescribe__;
__FriendItemDescribe__ for_describe_register_to___frienditemdescribe__;
__SCFriendListDescribe__ for_describe_register_to___scfriendlistdescribe__;


void CSRegisterAccount::Serialize(ByteArray &collector) const
{
  collector.WriteString(name);
  collector.WriteString(passwd);
}

void CSRegisterAccount::Unserialize(ByteArray &collector)
{
  name = collector.ReadString();
  passwd = collector.ReadString();
}

void CSLogin::Serialize(ByteArray &collector) const
{
  collector.WriteString(name);
  collector.WriteString(passwd);
}

void CSLogin::Unserialize(ByteArray &collector)
{
  name = collector.ReadString();
  passwd = collector.ReadString();
}

void SCLoginResult::Serialize(ByteArray &collector) const
{
  collector.WriteInt32(result);
}

void SCLoginResult::Unserialize(ByteArray &collector)
{
  result = collector.ReadInt32();
}

void CSRequestFriendList::Serialize(ByteArray &collector) const
{
}

void CSRequestFriendList::Unserialize(ByteArray &collector)
{
}

void FriendItem::Serialize(ByteArray &collector) const
{
  collector.WriteUint32(player_id);
  collector.WriteString(name);
}

void FriendItem::Unserialize(ByteArray &collector)
{
  player_id = collector.ReadUint32();
  name = collector.ReadString();
}

void SCFriendList::Serialize(ByteArray &collector) const
{
  collector.WriteUint16((unsigned short)friend_list.size());
  for (auto array_item : friend_list)
  {
    array_item.Serialize(collector);
  }
}

void SCFriendList::Unserialize(ByteArray &collector)
{
  {
    int array_size = collector.ReadUint16();
    FriendItem tmp_attr_value;
    for (int index = 0; index < array_size; ++ index)
    {
      tmp_attr_value.Unserialize(collector);
      friend_list.push_back(tmp_attr_value);
    }
  }
}

}

