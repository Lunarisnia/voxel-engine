#pragma once
namespace VoxelEngine {
class Time {
 public:
  static float timeSinceStartup;
  static float deltaTime;

 public:
  static void Initialize();

  static void Tick();
};
}  // namespace VoxelEngine
