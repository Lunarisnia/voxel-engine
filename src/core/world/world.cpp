#include "voxelengine/world/world.hpp"
#include <stdio.h>
#include <memory>
#include "voxelengine/object/object.hpp"
#include "voxelengine/renderer/renderer.hpp"
using namespace VoxelEngine;

void World::initialize() {
  Renderer::setBackgroundColor(0.3f, 0.3f, 0.3f, 1.0f);
}

void World::tick() {
  for (const std::shared_ptr<Object> object : worldObjects) {
    object->tick();
  }
}

void World::addObject(const std::shared_ptr<Object> &object) {
  if (worldObjects.contains(object)) {
    return;
  }
  worldObjects.insert(object);

  std::shared_ptr<Mesh> mesh = object->getComponent<Mesh>();
  if (mesh != nullptr) {
    Renderer::addToRenderQueue(mesh);
  }
}

void World::removeObject(std::shared_ptr<Object> &object) {
  if (worldObjects.contains(object)) {
    worldObjects.erase(object);
  }
}
