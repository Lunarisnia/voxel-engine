#include "voxelengine/voxel_engine/voxel_engine.hpp"
#include <memory>
#include "GLFW/glfw3.h"
#include "glm/ext/quaternion_geometric.hpp"
#include "voxelengine/math/quaternion.hpp"
#include "voxelengine/renderer/renderer.hpp"
#include "glm/ext/quaternion_float.hpp"
#include "glm/ext/quaternion_trigonometric.hpp"
#include "glm/ext/vector_float3.hpp"
#include "glm/trigonometric.hpp"
#include "voxelengine/input_manager/input_manager.hpp"
#include "voxelengine/utilities/object_primitives.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace VoxelEngine;

Engine::Engine(int width, int height, const char* title) {
  VoxelWindow::initialize(width, height, title);
  InputManager::initialize();
  Renderer::initialize();
  // TODO: WORLD: to manage all the component tick

  Quaternion q(1.0f, 0.0f, 0.0f, 0.0f);
  object = ObjectPrimitives::GenerateCube("foo");
  std::shared_ptr<Mesh> mesh = object->getComponent<Mesh>();
  Renderer::addToRenderQueue(mesh);
};

void Engine::tick() {
  // TODO: remove this after abstracting quaternion
  std::shared_ptr<Transform> t = object->getComponent<Transform>();
  t->rotation.rotate(glm::radians((float)glfwGetTime()),
                     glm::normalize(glm::vec3(1.0f, 1.0f, 0.0f)));
  t->rotation.normalize();
  t->tick();

  Renderer::setBackgroundColor(0.3f, 0.3f, 0.3f, 1.0f);
  Renderer::clear();

  Renderer::tick();

  VoxelWindow::render();
}

// TODO: add glfw keycode as our own constant
