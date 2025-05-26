#pragma once
#include "stbi_image/stbi_image.h"
class TextureImage {
 public:
  unsigned char *data;

  inline TextureImage(unsigned char *data) : data(data) {};

  inline void Free() { stbi_image_free(data); };
};
