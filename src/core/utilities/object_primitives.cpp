#include "voxelengine/utilities/object_primitives.hpp"
#include <memory>
#include "voxelengine/components/mesh.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/shader/shader.hpp"
#include "voxelengine/utilities/procedural_mesh.hpp"
using namespace VoxelEngine;

std::shared_ptr<Object> ObjectPrimitives::GenerateCube(std::string name) {
  std::shared_ptr<Object> cube = std::make_shared<Object>(name);
  // FIXME: Remove
  cube->transform->setPosition(glm::vec3(0.5f));

  Shader shader = Shader("./shaders/default/default.vert",
                         "./shaders/default/default.frag");
  std::shared_ptr<Material> material = std::make_shared<Material>(shader);
  std::shared_ptr<Mesh> mesh = cube->createComponent<Mesh>(material);

  ProceduralMesh::GenerateCubeMesh(mesh);
  mesh->setupMesh();

  return cube;
}
