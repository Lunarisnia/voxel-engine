#include "voxelengine/material/material.hpp"
#include "voxelengine/shader/shader.hpp"
using namespace VoxelEngine;

void Material::useShader() { shader.use(); }

void Material::setMatrix4x4(std::string uniform, const glm::mat4 &mat4) {
  shader.setMatrix4x4(uniform, mat4);
}
