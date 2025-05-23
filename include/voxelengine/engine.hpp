#pragma once
namespace VoxelEngine {
class Engine {
 public:
  Engine(int width, int height, const char* title);

  void Tick();
  void Run();
};
}  // namespace VoxelEngine
