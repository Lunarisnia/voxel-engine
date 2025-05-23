#pragma once
#include <string>
#include "glm/ext/matrix_float4x4.hpp"
#include "voxelengine/shader/shader.hpp"
#include "voxelengine/texture/texture.hpp"
namespace VoxelEngine {
class Material {
 private:
  Shader shader;

 public:
  Texture texture;
  Material(Shader shader) : shader(shader) {}

  void Use();
  void SetMatrix4x4(const std::string &uniform, const glm::mat4 &mat4);
  void SetInt(const std::string &uniform, const int &i);
  inline void SetTexture(int &width, int &height, unsigned char *data) {
    texture.SetTexture(width, height, data);
  };
};
}  // namespace VoxelEngine
