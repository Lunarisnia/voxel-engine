#pragma once
#include "glm/ext/vector_float2.hpp"
#include "glm/ext/vector_float3.hpp"
namespace VoxelEngine {
class VertexData {
 public:
  glm::vec3 position;
  glm::vec2 textureCoordinate;
};
}  // namespace VoxelEngine
