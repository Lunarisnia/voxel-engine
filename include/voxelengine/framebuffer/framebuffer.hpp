#pragma once
#include <memory>
#include "voxelengine/texture/texture.hpp"
namespace VoxelEngine {
class Framebuffer {
 private:
  unsigned int id;

 public:
  void Bind();
  void Unbind();
  void SetTexture(std::shared_ptr<Texture> texture);

 public:
  Framebuffer();
};
};  // namespace VoxelEngine
