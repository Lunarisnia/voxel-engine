#include "voxelengine/material/material.hpp"
#include "voxelengine/shader/shader.hpp"
using namespace VoxelEngine;

void Material::UseShader() { shader.Use(); }

void Material::SetMatrix4x4(std::string uniform, const glm::mat4 &mat4) {
  shader.SetMatrix4x4(uniform, mat4);
}
