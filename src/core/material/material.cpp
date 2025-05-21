#include "voxelengine/material/material.hpp"
#include "voxelengine/shader/shader.hpp"
using namespace VoxelEngine;
Material::Material(Shader shader) : shader(shader) {}

void Material::useShader() { shader.use(); }
