#include "voxelengine/scripting_engine/scripting_engine.hpp"
#include <string>
#include "voxelengine/log/logger.hpp"
#include "voxelengine/path_builder/path_builder.hpp"
using namespace VoxelEngine;

lua_State *ScriptingEngine::L = nullptr;

void ScriptingEngine::Initialize() {
  L = luaL_newstate();

  luaL_openlibs(L);
}

int ScriptingEngine::LoadAndRun(const std::string &path) {
  const std::string &codePath = PathBuilder::Join(path);

  if (luaL_dofile(L, codePath.c_str())) {
    Logger::Log(LogCategory::ERROR, lua_tostring(L, -1),
                "ScriptingEngine::LoadAndRun");
    return 1;
  }
  return 0;
}

void ScriptingEngine::Tick() {}

ScriptingEngine::~ScriptingEngine() { lua_close(L); }

// TODO: Load file function
// TODO: Run file function
