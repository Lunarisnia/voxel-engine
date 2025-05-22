#pragma once
#include <memory>
#include <vector>
#include "voxelengine/object/object.hpp"
namespace VoxelEngine {
class World {
 private:
  static inline std::vector<std::shared_ptr<Object>> worldObjects;

  static inline void insert(const std::shared_ptr<Object> &object) {
    worldObjects.emplace_back(object);
  };

 public:
  static void initialize();
  static void tick();

  static void addObject(std::shared_ptr<Object> &object);
};
};  // namespace VoxelEngine
