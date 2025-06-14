#pragma once
#include <string>
#include "voxelengine/scripting_engine/lua_function.hpp"
namespace VoxelEngine {
class LuaTable {
 private:
  std::string name;

 public:
  LuaFunction Function(const std::string &name);

 public:
  LuaTable(const std::string &name);
  ~LuaTable();
};
};  // namespace VoxelEngine
