#include "voxelengine/voxel_engine/voxel_engine.hpp"
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/input_manager/input_manager.hpp"
#include "voxelengine/utilities/object_primitives.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
#include "voxelengine/world/world.hpp"
using namespace VoxelEngine;

Engine::Engine(int width, int height, const char* title) {
  VoxelWindow::initialize(width, height, title);
  InputManager::initialize();
  Renderer::initialize();
  World::initialize();

  object = ObjectPrimitives::GenerateCube("foo");
  World::addObject(object);
};

void Engine::tick() {
  // TODO: remove this later
  std::shared_ptr<Transform> t = object->getComponent<Transform>();
  t->rotation.rotate(glm::radians((float)glfwGetTime()),
                     glm::normalize(glm::vec3(1.0f, 1.0f, 0.0f)));
  t->rotation.normalize();

  World::tick();
  Renderer::setBackgroundColor(0.3f, 0.3f, 0.3f, 1.0f);
  Renderer::clear();

  Renderer::tick();

  VoxelWindow::render();
}

// TODO: add glfw keycode as our own constant
