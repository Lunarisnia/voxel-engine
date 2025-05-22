#pragma once
namespace VoxelEngine {
class Engine {
 public:
  Engine(int width, int height, const char* title);

  void tick();
  void run();
};
}  // namespace VoxelEngine
