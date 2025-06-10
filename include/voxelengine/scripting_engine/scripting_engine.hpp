#pragma once
#include <string>
#include "lua.hpp"
namespace VoxelEngine {
class ScriptingEngine {
 private:
  static lua_State *L;

 public:
  static void Initialize();
  static int LoadAndRun(const std::string &path);
  static void Tick();

 public:
  inline ScriptingEngine() {};
  ~ScriptingEngine();
};
};  // namespace VoxelEngine
