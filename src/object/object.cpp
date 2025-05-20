#include "voxelengine/object/object.hpp"
#include "voxelengine/components/transform.hpp"
using namespace VoxelEngine;

Object::Object() { transform = createComponent<Transform>(); }
