#include "voxelengine/scripting_engine/lua_table.hpp"
#include <string>
#include "lua.hpp"
#include "voxelengine/log/logger.hpp"
#include "voxelengine/scripting_engine/lua_function.hpp"
#include "voxelengine/scripting_engine/scripting_engine.hpp"
using namespace VoxelEngine;

LuaTable::LuaTable(const std::string &name) {
  lua_getglobal(ScriptingEngine::L, name.c_str());
  if (!lua_istable(ScriptingEngine::L, -1)) {
    Logger::Log(LogCategory::ERROR, lua_tostring(ScriptingEngine::L, -1),
                "LuaTable::LuaTable");
  }
}

LuaFunction LuaTable::Function(const std::string &functionName) {
  return LuaFunction(functionName, name);
}

LuaTable::~LuaTable() { lua_pop(ScriptingEngine::L, 1); }
