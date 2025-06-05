#pragma once
#include "glm/ext/matrix_transform.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "glm/ext/quaternion_geometric.hpp"
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
    transformMatrix = glm::translate(glm::mat4(1.0f), position.ToGlm());
    transformMatrix = glm::scale(transformMatrix, scale.ToGlm());
    transformMatrix *= rotation.mat4Cast();
  }

 public:
  Vec3 position;
  Vec3 scale = Vec3(1.0f);
  Vec3 rotationEuler;
  Quaternion rotation = Quaternion(1.0f, 0.0f, 0.0f, 0.0f);
  Transform() { transformMatrix = glm::mat4(1.0f); }

  inline static Vec3 worldForward = Vec3(0.0f, 0.0f, -1.0f);
  inline static Vec3 worldRight = Vec3(1.0f, 0.0f, 0.0f);
  inline static Vec3 worldUp = Vec3(0.0f, 1.0f, 0.0f);

  inline void SetRotationEuler(Vec3 newRotationEuler) {
    Quaternion newRotation =
        Quaternion(Vec3(rotationEuler.x, rotationEuler.y, rotationEuler.z));

    rotationEuler = newRotationEuler;
    rotation = newRotation;
  }

  inline Vec3 GetForwardVector() {
    return (rotation * worldForward).Normalize();
  }

  inline Vec3 GetRightVector() { return (rotation * worldRight).Normalize(); }

  inline Vec3 GetUpVector() { return (rotation * worldUp).Normalize(); }

  inline void Tick() override {
    Component::Tick();

    updateTransformMatrix();
  }

  inline void SetPosition(Vec3 newPosition) { position = newPosition; }
  inline void Translate(Vec3 translateValue) {
    position = position + translateValue;
  }

  inline void SetScale(Vec3 newScale) { scale = newScale; }

  inline glm::mat4 GetTransformMatrix() const { return transformMatrix; }
};
}  // namespace VoxelEngine
