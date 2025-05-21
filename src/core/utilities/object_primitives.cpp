#include "voxelengine/utilities/object_primitives.hpp"
#include <iostream>
#include <memory>
#include "voxelengine/components/mesh.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/shader/shader.hpp"
using namespace VoxelEngine;

std::shared_ptr<Object> ObjectPrimitives::GenerateCube(std::string name) {
  std::shared_ptr<Object> cube = std::make_shared<Object>(name);

  Shader shader = Shader("./shaders/default/default.vert",
                         "./shaders/default/default.frag");
  std::shared_ptr<Material> material = std::make_shared<Material>(shader);
  cube->createComponent<Mesh>(material);

  std::cout << cube->id << std::endl;
  // TODO: Populate mesh with the cube vertices

  return cube;
}
