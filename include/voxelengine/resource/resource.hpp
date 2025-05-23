#pragma once
#include <string>
namespace VoxelEngine {
class Resource {
 public:
  static std::string LoadCodeFromPath(std::string path);
};
}  // namespace VoxelEngine
