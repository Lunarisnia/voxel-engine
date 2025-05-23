#include "voxelengine/world/world.hpp"
#include <stdio.h>
#include <memory>
#include "glm/ext/vector_float3.hpp"
#include "glm/geometric.hpp"
#include "glm/trigonometric.hpp"
#include "voxelengine/log/logger.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/time/time.hpp"
#include "voxelengine/utilities/object_primitives.hpp"
using namespace VoxelEngine;

void World::Initialize() {
  World::AddObject(ObjectPrimitives::GenerateCube("foo"));

  Renderer::SetBackgroundColor(0.3f, 0.3f, 0.3f, 1.0f);
  Logger::Log(LogCategory::INFO, "Initialized World", "World::Initialize");
}

void World::Tick() {
  for (const std::shared_ptr<Object> object : worldObjects) {
    // TODO: remove this
    std::shared_ptr<Transform> t = object->GetComponent<Transform>();
    t->rotation.rotate(glm::radians(20.0f) * Time::deltaTime,
                       glm::normalize(glm::vec3(0.5f, 1.0f, 0.0f)));
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
