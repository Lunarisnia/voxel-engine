#pragma once
namespace VoxelEngine {
class Engine {
 public:
  static void Initialize(int width, int height, const char* title);
  static void Tick();
};
}  // namespace VoxelEngine
