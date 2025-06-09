#pragma once
#include "voxelengine/math/vec2.hpp"
#include "voxelengine/math/vec3.hpp"
#include "voxelengine/object/object.hpp"
namespace VoxelEngine {
class MouseEvent {
 public:
  Vec2 position;

 public:
  Vec3 ToWorldPosition();
};
};  // namespace VoxelEngine
