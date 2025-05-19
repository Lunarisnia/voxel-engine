#include "voxelengine/voxel_engine/voxel_engine.hpp"

int main() {
  VoxelEngine::Engine voxelEngine(800, 640, "Voxel Engine");
  voxelEngine.run();
  return 0;
}
