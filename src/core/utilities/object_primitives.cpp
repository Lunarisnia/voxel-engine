#include "voxelengine/utilities/object_primitives.hpp"
#include <memory>
#include <string>
#include "voxelengine/components/chunk.hpp"
#include "voxelengine/components/mesh.hpp"
#include "voxelengine/components/camera.hpp"
#include "voxelengine/shader/shader.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/utilities/procedural_mesh.hpp"
using namespace VoxelEngine;

std::shared_ptr<Object> ObjectPrimitives::GenerateCube(std::string name) {
  std::shared_ptr<Object> cube = std::make_shared<Object>(name);

  Shader shader = Shader("./shaders/default/default.vert",
                         "./shaders/default/default.frag");
  std::shared_ptr<Material> material = std::make_shared<Material>(shader);
  std::shared_ptr<Mesh> mesh = cube->CreateComponent<Mesh>(material);

  ProceduralMesh::GenerateCubeMesh(mesh);
  mesh->SetupMesh();

  mesh->material->texture.LoadTexture("./assets/container.jpg");

  return cube;
}

std::shared_ptr<Object> ObjectPrimitives::GeneratePlane(std::string name) {
  std::shared_ptr<Object> plane = std::make_shared<Object>(name);

  Shader shader = Shader("./shaders/default/default.vert",
                         "./shaders/default/default.frag");
  std::shared_ptr<Material> material = std::make_shared<Material>(shader);
  std::shared_ptr<Mesh> mesh = plane->CreateComponent<Mesh>(material);

  ProceduralMesh::GeneratePlaneMesh(mesh);
  mesh->SetupMesh();

  mesh->material->texture.LoadTexture("./assets/container.jpg");

  return plane;
}

std::shared_ptr<Object> ObjectPrimitives::GenerateChunk(const std::string &name,
                                                        const int &size) {
  std::shared_ptr<Object> object = std::make_shared<Object>(name);

  Shader shader = Shader("./shaders/default/default.vert",
                         "./shaders/default/default.frag");
  std::shared_ptr<Material> material = std::make_shared<Material>(shader);
  std::shared_ptr<Mesh> mesh = object->CreateComponent<Mesh>(material);
  std::shared_ptr<Chunk> chunk = object->CreateComponent<Chunk>(size);

  ProceduralMesh::GenerateChunk(mesh, chunk);
  mesh->SetupMesh();

  mesh->material->texture.LoadTexture("./assets/container.jpg");

  return object;
}

std::shared_ptr<Object> ObjectPrimitives::GenerateCamera(std::string name) {
  std::shared_ptr<Object> cam = std::make_shared<Object>(name);

  std::shared_ptr<Camera> cameraComponent = cam->CreateComponent<Camera>();

  return cam;
}
