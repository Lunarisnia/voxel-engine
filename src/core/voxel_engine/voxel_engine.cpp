#include "stbi_image/stbi_image.h"
#include "voxelengine/engine.hpp"
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/input_manager/input_manager.hpp"
#include "voxelengine/scripting_engine/scripting_engine.hpp"
#include "voxelengine/time/time.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
#include "voxelengine/world/world.hpp"
using namespace VoxelEngine;

void Engine::Initialize(int width, int height, const char *title) {
  VoxelWindow::Initialize(width, height, title);
  Time::Initialize();
  InputManager::Initialize();
  Renderer::Initialize();
  World::Initialize();
  ScriptingEngine::Initialize();
  // TODO: Remove this
  ScriptingEngine::LoadAndRun("/build/debug/test.lua");
}

void Engine::Tick() {
  VoxelWindow::PollEvent();
  InputManager::PollMouse();
  Renderer::framebuffer->Bind();
  Renderer::Clear();
  Time::Tick();
  World::Tick();
  Renderer::Tick();
  Renderer::framebuffer->Unbind();
  Renderer::Clear();
}
