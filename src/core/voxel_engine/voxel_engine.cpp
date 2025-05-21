#include "voxelengine/voxel_engine/voxel_engine.hpp"
#include <memory>
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/input_manager/input_manager.hpp"
#include "voxelengine/utilities/object_primitives.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace VoxelEngine;

Engine::Engine(int width, int height, const char* title) {
  VoxelWindow::initialize(width, height, title);
  InputManager::initialize();
  Renderer::initialize();

  object = ObjectPrimitives::GenerateCube("foo");
  std::shared_ptr<Mesh> mesh = object->getComponent<Mesh>();
  Renderer::addToRenderQueue(mesh);
};

void Engine::tick() {
  Renderer::setBackgroundColor(0.3f, 0.3f, 0.3f, 1.0f);
  Renderer::clear();

  Renderer::tick();

  VoxelWindow::render();
}

// TODO: Handle rotation, maybe its high time we learn about quaternion?
// TODO: add glfw keycode as our own constant
