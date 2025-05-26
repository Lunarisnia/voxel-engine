#pragma once
#include "glm/ext/vector_float2.hpp"
#include "voxelengine/math/vec3.hpp"
namespace VoxelEngine {
class VertexData {
 public:
  Vec3 position;
  glm::vec2 textureCoordinate;
};
}  // namespace VoxelEngine
