#include "voxelengine/resource/resource.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include "stbi_image/stbi_image.h"
#include "voxelengine/log/logger.hpp"
#include "voxelengine/resource/texture_image.hpp"
using namespace VoxelEngine;

std::string Resource::LoadCodeFromPath(std::string path) {
  std::ifstream file(path);
  std::string code;
  try {
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    std::stringstream codeStream;
    codeStream << file.rdbuf();

    code = codeStream.str();

    file.close();
  } catch (const std::ifstream::failure &error) {
    std::cout << "READ::ERROR: " << error.what() << std::endl;
  }
  return code;
}

std::shared_ptr<TextureImage> Resource::LoadTextureFromImage(std::string path,
                                                             int *width,
                                                             int *height,
                                                             int *nrChannels) {
  unsigned char *data = stbi_load(path.c_str(), width, height, nrChannels, 0);
  if (data == nullptr) {
    Logger::Log(LogCategory::ERROR, "Failed to load texture",
                "Resource::LoadTextureFromImage");
    return nullptr;
  }
  std::shared_ptr<TextureImage> textureImage =
      std::make_shared<TextureImage>(data);
  return textureImage;
}
