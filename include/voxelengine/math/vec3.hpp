#pragma once
#include "glm/ext/vector_float3.hpp"
#include "glm/geometric.hpp"
class Vec3 {
 private:
  inline glm::vec3 toGlmVec3(float x, float y, float z) {
    return glm::vec3(x, y, z);
  };

 public:
  float x, y, z;
  inline Vec3(float x, float y, float z) : x(x), y(y), z(z) {};
  inline Vec3(float val) : x(val), y(val), z(val) {};
  inline Vec3(glm::vec3 vec) : x(vec.x), y(vec.y), z(vec.z) {}

  inline Vec3 normalize() { return Vec3(glm::normalize(toGlmVec3(x, y, z))); }

  inline glm::vec3 toGlm() { return glm::vec3(x, y, z); }

  Vec3 operator*(const Vec3 &other) {
    glm::vec3 a = toGlmVec3(x, y, z);
    glm::vec3 b = toGlmVec3(other.x, other.y, other.z);
    return Vec3(a * b);
  }

  Vec3 operator+(const Vec3 &other) {
    glm::vec3 a = toGlmVec3(x, y, z);
    glm::vec3 b = toGlmVec3(other.x, other.y, other.z);
    return Vec3(a + b);
  }

  Vec3 operator-(const Vec3 &other) {
    glm::vec3 a = toGlmVec3(x, y, z);
    glm::vec3 b = toGlmVec3(other.x, other.y, other.z);
    return Vec3(a - b);
  }
};
