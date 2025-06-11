#pragma once
#include <string>
namespace VoxelEngine {
class PathBuilder {
 public:
  static std::string basePath;

 public:
  static std::string Join(const std::string &path);

 public:
  inline PathBuilder() {}
};
};  // namespace VoxelEngine
