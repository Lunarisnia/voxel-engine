#include "voxelengine/engine.hpp"
#include "voxelengine/log/logger.hpp"
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/input_manager/input_manager.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
#include "voxelengine/world/world.hpp"
using namespace VoxelEngine;

Engine::Engine(int width, int height, const char* title) {
  VoxelWindow::Initialize(width, height, title);
  InputManager::Initialize();
  Renderer::Initialize();
  World::Initialize();

  Logger::Log(LogCategory::ERROR, "Hello", "Test");
};

void Engine::Tick() {
  World::Tick();
  Renderer::Clear();

  Renderer::Tick();

  VoxelWindow::Render();
}

// TODO: add glfw keycode as our own constant
