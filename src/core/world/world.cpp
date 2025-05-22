#include "voxelengine/world/world.hpp"
#include <memory>
#include "voxelengine/object/object.hpp"
#include "voxelengine/renderer/renderer.hpp"
using namespace VoxelEngine;

void World::initialize() {}

void World::tick() {
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
