#pragma once

#include <memory>
#include <string>
#include "voxelengine/object/object.hpp"
namespace VoxelEngine {
class ObjectPrimitives {
 public:
  static std::shared_ptr<Object> GenerateCube(std::string name);
  static std::shared_ptr<Object> GeneratePlane(std::string name);
};
}  // namespace VoxelEngine
