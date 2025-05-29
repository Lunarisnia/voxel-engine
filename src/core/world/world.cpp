#include "voxelengine/world/world.hpp"
#include <stdio.h>
#include <memory>
#include <string>
#include "stbi_image/stbi_image.h"
#include "voxedit/tabs/hierarchy.hpp"
#include "voxelengine/log/logger.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/renderer/renderer.hpp"
using namespace VoxelEngine;

void World::Initialize() {
  Renderer::SetBackgroundColor(0.3f, 0.3f, 0.3f, 1.0f);
  Logger::Log(LogCategory::INFO, "Initialized World", "World::Initialize");
}

void World::Tick() {
  for (const std::shared_ptr<Object> object : worldObjects) {
    // TODO: REMOVE THIS
    /*if (object->name == "MainCamera") {*/
    /*  return;*/
    /*}*/
    /*object->transform->rotation.rotate(*/
    /*    glm::radians(20.0f) * Time::deltaTime,*/
    /*    glm::normalize(glm::vec3(0.5f, 0.5f, 0.1f)));*/
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
    Voxedit::Hierarchy::AddObjectToHierarchy(object->id, object);
  }
}

void World::RemoveObject(std::shared_ptr<Object> &object) {
  if (worldObjects.contains(object)) {
    worldObjects.erase(object);
  }
}
