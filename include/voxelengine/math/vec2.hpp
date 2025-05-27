#pragma once
#include "glm/ext/vector_float2.hpp"
#include "glm/geometric.hpp"
namespace VoxelEngine {
class Vec2 {
 private:
 public:
  float x, y;
  inline Vec2() : x(0.0f), y(0.0f) {};
  inline Vec2(float x, float y) : x(x), y(y) {};
  inline Vec2(float val) : x(val), y(val) {};
  inline Vec2(glm::vec2 vec) : x(vec.x), y(vec.y) {};

  inline Vec2 Normalize() { return Vec2(glm::normalize(toGlmVec2())); };

  inline glm::vec2 toGlmVec2() const { return glm::vec2(x, y); };

  Vec2 operator*(const Vec2 &other) {
    glm::vec2 a = toGlmVec2();
    glm::vec2 b = other.toGlmVec2();
    return Vec2(a * b);
  }

  Vec2 operator+(const Vec2 &other) {
    glm::vec2 a = toGlmVec2();
    glm::vec2 b = other.toGlmVec2();
    return Vec2(a + b);
  }

  Vec2 operator-(const Vec2 &other) {
    glm::vec2 a = toGlmVec2();
    glm::vec2 b = other.toGlmVec2();
    return Vec2(a - b);
  }
};
};  // namespace VoxelEngine
