#pragma once
#include <string>
#include "lua.hpp"
#include "voxelengine/log/logger.hpp"
namespace VoxelEngine {
class ScriptingEngine {
 private:
  static lua_State *L;

 private:
  static std::string buildPath(const std::string &path);

 public:
  static void Initialize();
  template <typename... Parameter, typename... ReturnTarget>
  static int CallFunction(const std::string &name, Parameter... params,
                          ReturnTarget &...returnTargets);

  static int LoadAndRun(const std::string &path);
  static int Load(const std::string &path);

  static int Run(int nargs, int nresults);
  static int Run();

  static void Tick();

 public:
  inline ScriptingEngine() {};
  ~ScriptingEngine();
};

template <typename... Parameter, typename... ReturnTarget>
int ScriptingEngine::CallFunction(const std::string &name, Parameter... params,
                                  ReturnTarget &...returnTargets) {
  lua_getglobal(L, name.c_str());
  if (!lua_isfunction(L, -1)) {
    Logger::Log(LogCategory::ERROR, lua_tostring(L, -1),
                "ScriptingEngine::CallFunction");
    return 1;
  }

  return 0;
}

};  // namespace VoxelEngine
