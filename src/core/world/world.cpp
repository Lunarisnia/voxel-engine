#include "voxelengine/world/world.hpp"
#include <stdio.h>
#include <memory>
#include "voxelengine/log/logger.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/utilities/object_primitives.hpp"
using namespace VoxelEngine;

void World::Initialize() {
  World::AddObject(ObjectPrimitives::GenerateCube("foo"));

  Renderer::SetBackgroundColor(0.3f, 0.3f, 0.3f, 1.0f);
  Logger::Log(LogCategory::INFO, "Initialized World", "World::Initialize");
}

void World::Tick() {
  for (const std::shared_ptr<Object> object : worldObjects) {
    object->Tick();
  }
}

void World::AddObject(const std::shared_ptr<Object> &object) {
  if (worldObjects.contains(object)) {
    return;
  }
  worldObjects.insert(object);

  std::shared_ptr<Mesh> mesh = object->GetComponent<Mesh>();
  if (mesh != nullptr) {
    Renderer::AddToRenderQueue(mesh);
  }
}

void World::RemoveObject(std::shared_ptr<Object> &object) {
  if (worldObjects.contains(object)) {
    worldObjects.erase(object);
  }
}
