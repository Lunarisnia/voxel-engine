#include "voxelengine/object/object.hpp"
#include <ctime>
#include "voxelengine/components/transform.hpp"
using namespace VoxelEngine;

Object::Object(std::string name) : name(name) {
  id = std::time(nullptr);
  transform = createComponent<Transform>();
}
