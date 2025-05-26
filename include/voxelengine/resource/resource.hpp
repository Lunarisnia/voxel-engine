#pragma once
#include <memory>
#include <string>
#include "voxelengine/resource/texture_image.hpp"
namespace VoxelEngine {
class Resource {
 public:
  static std::string LoadCodeFromPath(std::string path);
  static std::shared_ptr<TextureImage> LoadTextureFromImage(std::string path,
                                                            int *width,
                                                            int *height,
                                                            int *nrChannels);
};
}  // namespace VoxelEngine
