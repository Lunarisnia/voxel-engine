#pragma once
#include <memory>
#include <unordered_set>
#include "voxelengine/object/object.hpp"
namespace VoxelEngine {
class World {
 private:
  static inline std::unordered_set<std::shared_ptr<Object>> worldObjects;

 public:
  static void Initialize();
  static void Tick();

  static void AddObject(const std::shared_ptr<Object> &object);
  static void RemoveObject(std::shared_ptr<Object> &object);
};
};  // namespace VoxelEngine
