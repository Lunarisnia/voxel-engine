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

  Renderer::setBackgroundColor(0.3f, 0.3f, 0.3f, 1.0f);
}

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

// TODO: remove object
