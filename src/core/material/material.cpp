#include "voxelengine/material/material.hpp"
#include "voxelengine/shader/shader.hpp"
using namespace VoxelEngine;

void Material::Use() {
  texture.Bind();
  shader.Use();
}

void Material::SetMatrix4x4(const std::string &uniform, const glm::mat4 &mat4) {
  shader.SetMatrix4x4(uniform, mat4);
}

void Material::SetInt(const std::string &uniform, const int &i) {
  shader.SetInt(uniform, i);
}
