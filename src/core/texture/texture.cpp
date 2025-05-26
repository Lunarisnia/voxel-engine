#include "voxelengine/texture/texture.hpp"
#include <string>
#include "voxelengine/resource/resource.hpp"
using namespace VoxelEngine;

Texture::Texture() { glGenTextures(1, &id); }

void Texture::SetTexture(int width, int height, unsigned char *data) {
  Bind();

  // TODO: Maybe set active texture slot as a parameter somewhere?
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
               GL_UNSIGNED_BYTE, data);
}
