#pragma once
#include "voxelengine/shader/shader.hpp"
namespace VoxelEngine {
class Material {
 private:
  Shader shader;

 public:
  Material(Shader shader);
};
}  // namespace VoxelEngine
