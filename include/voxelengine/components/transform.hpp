#pragma once
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/vector_float3.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "voxelengine/components/component.hpp"
#include "voxelengine/math/quaternion.hpp"
#include "voxelengine/math/vec3.hpp"
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
    transformMatrix *= rotation.mat4Cast();
  }

 public:
  glm::vec3 position;
  // TODO: abstract vec3 away
  glm::vec3 scale = glm::vec3(1.0f);
  Quaternion rotation = Quaternion(1.0f, 0.0f, 0.0f, 0.0f);
  Transform() { transformMatrix = glm::mat4(1.0f); }

  inline static glm::vec3 worldForward = glm::vec3(0.0f, 0.0f, -1.0f);
  inline static glm::vec3 worldRight = glm::vec3(0.0f, 1.0f, 0.0f);
  inline static glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

  inline Vec3 GetForwardVector() {
    return glm::normalize(rotation * worldForward);
  }

  inline glm::vec3 GetRightVector() {
    return glm::normalize(rotation * worldRight);
  }

  inline Vec3 GetUpVector() { return glm::normalize(rotation * worldUp); }

  inline void Tick() override {
    Component::Tick();

    updateTransformMatrix();
  }

  inline void SetPosition(glm::vec3 newPosition) { position = newPosition; }

  inline glm::mat4 GetTransformMatrix() const { return transformMatrix; }
};
}  // namespace VoxelEngine
