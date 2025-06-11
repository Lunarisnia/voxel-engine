#include "voxelengine/path_builder/path_builder.hpp"
#include <filesystem>
#include <string>
using namespace VoxelEngine;

std::string PathBuilder::basePath = std::filesystem::current_path();

std::string PathBuilder::Join(const std::string &path) {
  return basePath + path;
}
