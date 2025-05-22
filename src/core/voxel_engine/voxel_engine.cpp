#include "voxelengine/engine.hpp"
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/input_manager/input_manager.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
#include "voxelengine/world/world.hpp"
using namespace VoxelEngine;

Engine::Engine(int width, int height, const char* title) {
  VoxelWindow::initialize(width, height, title);
  InputManager::initialize();
  Renderer::initialize();
  World::initialize();
};

void Engine::tick() {
  World::tick();
  Renderer::clear();

  Renderer::tick();

  VoxelWindow::render();
}

// TODO: add glfw keycode as our own constant
