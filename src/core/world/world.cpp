#include "voxelengine/world/world.hpp"
#include <stdio.h>
#include <memory>
#include <string>
#include "glm/ext/vector_float3.hpp"
#include "glm/geometric.hpp"
#include "glm/trigonometric.hpp"
#include "stbi_image/stbi_image.h"
#include "voxelengine/log/logger.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/time/time.hpp"
#include "voxelengine/utilities/object_primitives.hpp"
using namespace VoxelEngine;

std::shared_ptr<Object> object;

void World::Initialize() {
  object = ObjectPrimitives::GeneratePlane("foo");
  World::AddObject(object);

  // TODO: abstract this
  int imgWidth, imgHeight, nrChannels;
  unsigned char *img = stbi_load("./assets/container.jpg", &imgWidth,
                                 &imgHeight, &nrChannels, 0);
  std::shared_ptr<Mesh> mesh = object->GetComponent<Mesh>();
  mesh->material->SetTexture(imgWidth, imgHeight, img);
  stbi_image_free(img);

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
