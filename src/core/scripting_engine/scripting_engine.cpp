#include "voxelengine/scripting_engine/scripting_engine.hpp"
#include <string>
#include "lua.hpp"
#include "voxelengine/log/logger.hpp"
#include "voxelengine/path_builder/path_builder.hpp"
using namespace VoxelEngine;

lua_State *ScriptingEngine::L = nullptr;

void ScriptingEngine::Initialize() {
  L = luaL_newstate();

  luaL_openlibs(L);
}

int ScriptingEngine::LoadAndRun(const std::string &path) {
  const std::string &codePath = buildPath(path);

  if (luaL_dofile(L, codePath.c_str())) {
    Logger::Log(LogCategory::ERROR, lua_tostring(L, -1),
                "ScriptingEngine::LoadAndRun");
    return 1;
  }
  return 0;
}

int ScriptingEngine::Load(const std::string &path) {
  const std::string &codePath = buildPath(path);

  if (luaL_loadfile(L, codePath.c_str())) {
    Logger::Log(LogCategory::ERROR, lua_tostring(L, -1),
                "ScriptingEngine::Load");
    return 1;
  }
  return 0;
}

int ScriptingEngine::Run() { return Run(0, 0); }

int ScriptingEngine::Run(int nargs, int nresults) {
  if (lua_pcall(L, 0, 0, 0)) {
    Logger::Log(LogCategory::ERROR, lua_tostring(L, -1),
                "ScriptingEngine::Run");
    return 1;
  }

  return 0;
}

void ScriptingEngine::Tick() {}

std::string ScriptingEngine::buildPath(const std::string &path) {
  return PathBuilder::Join(path);
}

ScriptingEngine::~ScriptingEngine() { lua_close(L); }
