#pragma once

#include <string>
#include <vector>
#include <memory/serialize/serialize_base.hpp>

using face2wind::SerializeBase;
using face2wind::SerializeDescribe;
using face2wind::ByteArray;

namespace Protocol {

class CSRegisterAccount : public SerializeBase
{
public:
  std::string name;
  std::string passwd;

  virtual void Serialize(ByteArray &collector) const;
  virtual void Unserialize(ByteArray &collector);
  virtual const std::string GetTypeName() const { return "CSRegisterAccount"; }
};

class CSLogin : public SerializeBase
{
public:
  std::string name;
  std::string passwd;

  virtual void Serialize(ByteArray &collector) const;
  virtual void Unserialize(ByteArray &collector);
  virtual const std::string GetTypeName() const { return "CSLogin"; }
};

class SCLoginResult : public SerializeBase
{
public:
  int result;

  virtual void Serialize(ByteArray &collector) const;
  virtual void Unserialize(ByteArray &collector);
  virtual const std::string GetTypeName() const { return "SCLoginResult"; }
};

class CSRequestFriendList : public SerializeBase
{
public:

  virtual void Serialize(ByteArray &collector) const;
  virtual void Unserialize(ByteArray &collector);
  virtual const std::string GetTypeName() const { return "CSRequestFriendList"; }
};

class FriendItem : public SerializeBase
{
public:
  unsigned int player_id;
  std::string name;

  virtual void Serialize(ByteArray &collector) const;
  virtual void Unserialize(ByteArray &collector);
  virtual const std::string GetTypeName() const { return "FriendItem"; }
};

class SCFriendList : public SerializeBase
{
public:
  std::vector<FriendItem> friend_list;

  virtual void Serialize(ByteArray &collector) const;
  virtual void Unserialize(ByteArray &collector);
  virtual const std::string GetTypeName() const { return "SCFriendList"; }
};

class __CSRegisterAccountDescribe__ : public SerializeDescribe
{
public:
  __CSRegisterAccountDescribe__() { name_to_object_map_["CSRegisterAccount"] = this; }
  virtual ~__CSRegisterAccountDescribe__() {}

protected:
  virtual SerializeBase * CreateSerialize() const { return new CSRegisterAccount(); }
};

class __CSLoginDescribe__ : public SerializeDescribe
{
public:
  __CSLoginDescribe__() { name_to_object_map_["CSLogin"] = this; }
  virtual ~__CSLoginDescribe__() {}

protected:
  virtual SerializeBase * CreateSerialize() const { return new CSLogin(); }
};

class __SCLoginResultDescribe__ : public SerializeDescribe
{
public:
  __SCLoginResultDescribe__() { name_to_object_map_["SCLoginResult"] = this; }
  virtual ~__SCLoginResultDescribe__() {}

protected:
  virtual SerializeBase * CreateSerialize() const { return new SCLoginResult(); }
};

class __CSRequestFriendListDescribe__ : public SerializeDescribe
{
public:
  __CSRequestFriendListDescribe__() { name_to_object_map_["CSRequestFriendList"] = this; }
  virtual ~__CSRequestFriendListDescribe__() {}

protected:
  virtual SerializeBase * CreateSerialize() const { return new CSRequestFriendList(); }
};

class __FriendItemDescribe__ : public SerializeDescribe
{
public:
  __FriendItemDescribe__() { name_to_object_map_["FriendItem"] = this; }
  virtual ~__FriendItemDescribe__() {}

protected:
  virtual SerializeBase * CreateSerialize() const { return new FriendItem(); }
};

class __SCFriendListDescribe__ : public SerializeDescribe
{
public:
  __SCFriendListDescribe__() { name_to_object_map_["SCFriendList"] = this; }
  virtual ~__SCFriendListDescribe__() {}

protected:
  virtual SerializeBase * CreateSerialize() const { return new SCFriendList(); }
};



}

