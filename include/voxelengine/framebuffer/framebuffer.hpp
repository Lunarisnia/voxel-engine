#pragma once
#include <memory>
#include "voxelengine/texture/texture.hpp"
namespace VoxelEngine {
class Framebuffer {
 private:
  unsigned int fbo;
  unsigned int rbo;

 public:
  void Bind();
  void SetTexture(std::shared_ptr<Texture> texture);

 public:
  Framebuffer();
};
};  // namespace VoxelEngine
