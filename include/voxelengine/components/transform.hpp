#pragma once
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/quaternion_float.hpp"
#include "glm/ext/vector_float3.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "glm/gtc/quaternion.hpp"
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
    transformMatrix *= glm::mat4_cast(rotation);
  }

 public:
  glm::vec3 position;
  glm::vec3 scale = glm::vec3(1.0f);
  // TODO: how about we just use quaternion for rotation and have the quaternion
  // return its euler angle for UI purpose only
  glm::vec3 eulerAngles = glm::vec3(0.0f);
  glm::quat rotation = glm::quat(eulerAngles);
  Transform() { transformMatrix = glm::mat4(1.0f); }

  inline void tick() override {
    Component::tick();

    updateTransformMatrix();
  }

  inline void setPosition(glm::vec3 newPosition) { position = newPosition; }

  inline glm::mat4 getTransformMatrix() const { return transformMatrix; }
};
}  // namespace VoxelEngine
