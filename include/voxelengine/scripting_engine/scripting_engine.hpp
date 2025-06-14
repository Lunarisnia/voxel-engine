#pragma once
#include <string>
#include "lua.hpp"
#include "voxelengine/scripting_engine/lua_function.hpp"
#include "voxelengine/scripting_engine/lua_table.hpp"
namespace VoxelEngine {
class ScriptingEngine {
  friend LuaFunction;
  friend LuaTable;

 private:
  static lua_State *L;

 private:
  static std::string buildPath(const std::string &path);

 public:
  static void Initialize();
  static LuaTable Table(const std::string &name);
  static LuaFunction Function(const std::string &name);

  static void ShowLastItemTypeOnStack();

  static int LoadAndRun(const std::string &path);
  static int Load(const std::string &path);

  static int Run(int nargs, int nresults);
  static int Run();

  static void Tick();

 public:
  inline ScriptingEngine() {};
  ~ScriptingEngine();
};

};  // namespace VoxelEngine
