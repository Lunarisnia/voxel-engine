#include "voxelengine/object/object.hpp"
#include <ctime>
#include <memory>
using namespace VoxelEngine;

void Object::Tick() {
  for (const std::shared_ptr<Component> &comp : components) {
    comp->Tick();
  }
}
