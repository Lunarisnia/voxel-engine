#pragma once
#include "glad/glad.h"
namespace VoxelEngine {
class Texture {
 private:
  unsigned int id;

 public:
  Texture();

  void SetTexture(int width, int height, unsigned char* data);

  inline void Bind() { glBindTexture(GL_TEXTURE_2D, id); };
};
}  // namespace VoxelEngine
