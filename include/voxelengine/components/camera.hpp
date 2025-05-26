#pragma once
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/vector_float3.hpp"
#include "voxelengine/components/component.hpp"
namespace VoxelEngine {
class Camera : public Component {
  MAKE_UNIQUE_COMPONENT();
  MAKE_COMPONENT_TYPE(CAMERA);

 public:
  glm::vec3 position = glm::vec3(0.0f, 0.0f, 1.0f);
  float fov = 45.0f;
  float near = 0.01f;
  float far = 100.0f;

  glm::mat4 GetViewMatrix();
  glm::mat4 GetProjectionMatrix();
};
}  // namespace VoxelEngine
