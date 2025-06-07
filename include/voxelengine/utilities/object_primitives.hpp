#pragma once

#include <memory>
#include <string>
#include "voxelengine/object/object.hpp"
namespace VoxelEngine {
class ObjectPrimitives {
 public:
  // TODO: Change all of this param to const reference
  static std::shared_ptr<Object> GenerateCube(std::string name);
  static std::shared_ptr<Object> GeneratePlane(std::string name);
  static std::shared_ptr<Object> GenerateCamera(std::string name);
  static std::shared_ptr<Object> GenerateChunk(const std::string &name,
                                               const int &size);
};
}  // namespace VoxelEngine
