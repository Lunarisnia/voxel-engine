#pragma once
#include <memory>
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/object/object.hpp"
namespace VoxelEngine {
class Engine {
 public:
  std::shared_ptr<Object> object;
  Engine(int width, int height, const char* title);

  void tick();
  void run();
};
}  // namespace VoxelEngine
