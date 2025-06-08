#pragma once
#include "voxelengine/math/vec2.hpp"
#include "voxelengine/math/vec3.hpp"
namespace VoxelEngine {
class VertexData {
 public:
  Vec3 position;
  Vec2 textureCoordinate;
  Vec3 normal;
};
}  // namespace VoxelEngine
