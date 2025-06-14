#include "voxelengine/scripting_engine/lua_function.hpp"
#include "voxelengine/log/logger.hpp"
#include "voxelengine/scripting_engine/scripting_engine.hpp"
using namespace VoxelEngine;

LuaFunction::LuaFunction(const std::string &name) {
  lua_getglobal(ScriptingEngine::L, name.c_str());
  if (!lua_isfunction(ScriptingEngine::L, -1)) {
    Logger::Log(LogCategory::ERROR, lua_tostring(ScriptingEngine::L, -1),
                "LuaFunction::LuaFunction");
  }
}

// TODO: Create a LuaTable class and tie it to LuaFunction
LuaFunction::LuaFunction(const std::string &name,
                         const std::string &tableName) {
  lua_getglobal(ScriptingEngine::L, tableName.c_str());
  lua_getfield(ScriptingEngine::L, -1, name.c_str());
  if (!lua_isfunction(ScriptingEngine::L, -1)) {
    Logger::Log(LogCategory::ERROR, lua_tostring(ScriptingEngine::L, -1),
                "LuaFunction::LuaFunction");
  }
}

LuaFunction *LuaFunction::AddParamString(const std::string &value) {
  lua_pushstring(ScriptingEngine::L, value.c_str());
  nargs++;
  return this;
}

LuaFunction *LuaFunction::AddParamBoolean(bool value) {
  lua_pushboolean(ScriptingEngine::L, value);
  nargs++;
  return this;
}

LuaFunction *LuaFunction::AddParamNumber(int value) {
  lua_pushnumber(ScriptingEngine::L, value);
  nargs++;
  return this;
}

LuaFunction *LuaFunction::AddParamNumber(float value) {
  lua_pushnumber(ScriptingEngine::L, value);
  nargs++;
  return this;
}

LuaFunction *LuaFunction::AddParamNumber(double value) {
  lua_pushnumber(ScriptingEngine::L, value);
  nargs++;
  return this;
}

void LuaFunction::Execute() { ScriptingEngine::Run(nargs, nresults); }
