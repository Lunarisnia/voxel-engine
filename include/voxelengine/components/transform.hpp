#pragma once
#include "glm/ext/vector_float3.hpp"
#include <glm/ext/matrix_transform.hpp>
#include "voxelengine/components/component.hpp"
namespace VoxelEngine {
class Transform : public Component {
  MAKE_UNIQUE_COMPONENT();

 protected:
  glm::mat4 localMatrix;

 public:
  glm::vec3 position;
  glm::vec3 scale;
};
}  // namespace VoxelEngine
