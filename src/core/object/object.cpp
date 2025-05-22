#include "voxelengine/object/object.hpp"
#include <ctime>
#include <memory>
using namespace VoxelEngine;

void Object::tick() {
  for (const std::shared_ptr<Component> &comp : components) {
    comp->tick();
  }
}
