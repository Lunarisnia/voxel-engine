#include "glad/glad.h"
#include "voxelengine/engine.hpp"

int main() {
  VoxelEngine::Engine voxelEngine(800, 640, "Voxel Engine");
  while (true) {
    voxelEngine.Tick();
  }

  return 0;
}
