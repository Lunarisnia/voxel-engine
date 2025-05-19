#pragma once
#include <string>
namespace VoxelEngine {
class Resource {
 public:
  static std::string loadCodeFromPath(std::string path);
};
}  // namespace VoxelEngine
