#include "voxelengine/voxel_engine/voxel_engine.hpp"
#include <memory>
#include "GLFW/glfw3.h"
#include "voxelengine/components/mesh.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/input_manager/input_manager.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace VoxelEngine;

Engine::Engine(int width, int height, const char* title) {
  VoxelWindow::initialize(width, height, title);
  InputManager::initialize();
  Renderer::initialize();

  Shader shader("./shaders/default/default.vert",
                "./shaders/default/default.frag");
  mesh = obj.createComponent<Mesh>(std::make_shared<Material>(shader));
  mesh->setupMesh();

  Renderer::addToRenderQueue(mesh);
};

void Engine::tick() {
  if (InputManager::getKey(GLFW_KEY_E)) {
    std::cout << "FOO" << std::endl;
  }

  Renderer::setBackgroundColor(0.3f, 0.3f, 0.3f, 1.0f);
  Renderer::clear();

  Renderer::tick();

  VoxelWindow::render();
}
