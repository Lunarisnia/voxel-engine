#pragma once
#include "voxelengine/object/object.hpp"
namespace VoxelEngine {
class Engine {
 public:
  Object obj = Object("test");
  Engine(int width, int height, const char* title);

  void tick();
  void run();
};
}  // namespace VoxelEngine
