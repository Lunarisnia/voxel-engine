#include "voxelengine/world/world.hpp"
#include <memory>
#include "voxelengine/object/object.hpp"
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/utilities/object_primitives.hpp"
using namespace VoxelEngine;

static std::shared_ptr<Object> object;

void World::initialize() {
  object = ObjectPrimitives::GenerateCube("foo");
  World::addObject(object);
}

void World::tick() {
  // TODO: remove this later
  std::shared_ptr<Transform> t = object->getComponent<Transform>();
  t->rotation.rotate(glm::radians(0.5f),
                     glm::normalize(glm::vec3(1.0f, 1.0f, 0.0f)));
  t->rotation.normalize();
  for (const std::shared_ptr<Object> object : worldObjects) {
    object->tick();
  }
}

void World::addObject(std::shared_ptr<Object> &object) {
  insert(object);

  std::shared_ptr<Mesh> mesh = object->getComponent<Mesh>();
  if (mesh != nullptr) {
    Renderer::addToRenderQueue(mesh);
  }
}
