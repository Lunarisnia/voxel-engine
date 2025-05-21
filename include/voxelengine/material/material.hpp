#pragma once
#include <string>
#include "glm/ext/matrix_float4x4.hpp"
#include "voxelengine/shader/shader.hpp"
namespace VoxelEngine {
class Material {
 private:
  Shader shader;

 public:
  Material(Shader shader) : shader(shader) {}

  void useShader();
  void setMatrix4x4(std::string uniform, const glm::mat4 &mat4);
};
}  // namespace VoxelEngine
