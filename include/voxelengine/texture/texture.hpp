#pragma once
#include <memory>
#include <string>
#include "glad/glad.h"
#include "voxelengine/resource/resource.hpp"
#include "voxelengine/resource/texture_image.hpp"
namespace VoxelEngine {
class Texture {
 private:
  unsigned int id;

 public:
  std::string texturePath;
  int width, height, nrChannels;
  Texture();

  void SetTexture(int width, int height, unsigned char *data);

  inline unsigned int GetTextureID() { return id; };

  inline void Bind() { glBindTexture(GL_TEXTURE_2D, id); };
  inline void LoadTexture(const std::string &path) {
    texturePath = path;
    std::shared_ptr<TextureImage> textureImage = Resource::LoadTextureFromImage(
        texturePath, &width, &height, &nrChannels);

    SetTexture(width, height, textureImage->data);
    textureImage->Free();
  };
};
}  // namespace VoxelEngine
