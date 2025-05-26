#pragma once
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/ext/quaternion_float.hpp"
#include "glm/ext/quaternion_geometric.hpp"
#include "glm/ext/quaternion_trigonometric.hpp"
#include "glm/ext/vector_float3.hpp"
#include "glm/gtc/quaternion.hpp"
namespace VoxelEngine {
class Quaternion {
 private:
  inline Quaternion(glm::quat newQuat) { reassignQuaternion(newQuat); };

  inline void reassignQuaternion(glm::quat q) {
    w = q.w;
    x = q.x;
    y = q.y;
    z = q.z;
  }

  inline glm::quat getGlmQuat() const { return glm::quat(w, x, y, z); }

 public:
  float w;
  float x;
  float y;
  float z;
  inline Quaternion(float w, float x, float y, float z)
      : w(w), x(x), y(y), z(z) {};
  inline Quaternion() : w(1.0f), x(0.0f), y(0.0f), z(0.0f) {};

  inline void rotate(float angle, glm::vec3 axis) {
    glm::quat q = glm::quat(w, x, y, z) * glm::angleAxis(angle, axis);
    q = glm::normalize(q);
    reassignQuaternion(q);
  }

  inline Quaternion normalize() {
    glm::quat newQuat = getGlmQuat();
    return glm::normalize(newQuat);
  }

  inline glm::mat4 mat4Cast() {
    glm::quat newQuat = getGlmQuat();
    return glm::mat4_cast(newQuat);
  }

  Quaternion operator*(Quaternion const& other) {
    Quaternion res(1.0f, 0.0f, 0.0f, 0.0f);
    return res;
  }

  glm::vec3 operator*(glm::vec3 const& other) {
    glm::quat q = getGlmQuat();
    return q * other;
  }
};
}  // namespace VoxelEngine
