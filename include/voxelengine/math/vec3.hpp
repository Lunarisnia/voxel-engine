#pragma once
#include "glm/ext/vector_float3.hpp"
#include "glm/geometric.hpp"
#include "glm/trigonometric.hpp"
namespace VoxelEngine {
class Vec3 {
 private:
 public:
  float x, y, z;
  inline Vec3() : x(0.0f), y(0.0f), z(0.0f) {};
  inline Vec3(float x, float y, float z) : x(x), y(y), z(z) {};
  inline Vec3(float val) : x(val), y(val), z(val) {};
  inline Vec3(glm::vec3 vec) : x(vec.x), y(vec.y), z(vec.z) {}

  inline Vec3 Normalize() { return Vec3(glm::normalize(toGlmVec3())); }

  inline glm::vec3 ToGlm() const { return glm::vec3(x, y, z); }

  inline glm::vec3 toGlmVec3() const { return glm::vec3(x, y, z); };

  inline Vec3 Deg2Rad() const { return glm::radians(toGlmVec3()); }

  Vec3 operator*(const Vec3 &other) {
    glm::vec3 a = toGlmVec3();
    glm::vec3 b = other.toGlmVec3();
    return Vec3(a * b);
  }

  Vec3 operator+(const Vec3 &other) {
    glm::vec3 a = toGlmVec3();
    glm::vec3 b = other.toGlmVec3();
    return Vec3(a + b);
  }

  Vec3 operator-(const Vec3 &other) {
    glm::vec3 a = toGlmVec3();
    glm::vec3 b = other.toGlmVec3();
    return Vec3(a - b);
  }
};
};  // namespace VoxelEngine
