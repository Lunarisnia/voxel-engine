#include "voxelengine/object/object.hpp"
#include "voxelengine/components/transform.hpp"
using namespace VoxelEngine;

Object::Object(std::string name) : name(name) {
  transform = createComponent<Transform>();
}
