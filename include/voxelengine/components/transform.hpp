#pragma once
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/vector_float3.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "voxelengine/components/component.hpp"
namespace VoxelEngine {
class Transform : public Component {
  MAKE_UNIQUE_COMPONENT();
  MAKE_COMPONENT_TYPE(TRANSFORM);

 protected:
  glm::mat4 transformMatrix;

 private:
  inline void updateTransformMatrix() {
    transformMatrix = glm::translate(glm::mat4(1.0f), position);
    transformMatrix = glm::scale(transformMatrix, scale);
  }

 public:
  Transform() {
    transformMatrix = glm::mat4(1.0f);
    transformMatrix = glm::translate(transformMatrix, position);
    transformMatrix = glm::scale(transformMatrix, scale);
  }
  glm::vec3 position;
  glm::vec3 scale = glm::vec3(1.0f);

  inline void setPosition(glm::vec3 newPosition) {
    position = newPosition;
    updateTransformMatrix();
  }

  inline glm::mat4 getTransformMatrix() const { return transformMatrix; }
};
}  // namespace VoxelEngine
