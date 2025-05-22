#pragma once
#include <memory>
#include <unordered_set>
#include "voxelengine/object/object.hpp"
namespace VoxelEngine {
class World {
 private:
  static inline std::unordered_set<std::shared_ptr<Object>> worldObjects;

 public:
  static void initialize();
  static void tick();

  static void addObject(const std::shared_ptr<Object> &object);
  static void removeObject(std::shared_ptr<Object> &object);
};
};  // namespace VoxelEngine
