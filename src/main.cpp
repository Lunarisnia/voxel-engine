#include "glad/glad.h"
#include "voxelengine/voxel_engine/voxel_engine.hpp"

int main() {
  VoxelEngine::Engine voxelEngine(800, 640, "Voxel Engine");
  while (true) {
    voxelEngine.tick();
  }

  return 0;
}
