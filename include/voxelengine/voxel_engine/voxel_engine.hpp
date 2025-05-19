#ifndef VOXEL_ENGINE_H
#define VOXEL_ENGINE_H
namespace VoxelEngine {
class Engine {
 public:
  Engine(int width, int height, const char* title);

  void run();
};
}  // namespace VoxelEngine
#endif
