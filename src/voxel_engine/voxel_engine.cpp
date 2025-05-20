#include "voxelengine/voxel_engine/voxel_engine.hpp"
#include <iostream>
#include <memory>
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
  std::shared_ptr<Mesh> mesh =
      obj.createComponent<Mesh>(std::make_shared<Material>(shader));
  std::cout << "Hello: " << mesh->getType() << std::endl;
};

void Engine::tick() {
  Renderer::setBackgroundColor(0.3f, 0.3f, 0.3f, 1.0f);
  Renderer::clear();

  /*Renderer::drawMesh(mesh);*/

  VoxelWindow::render();
}
