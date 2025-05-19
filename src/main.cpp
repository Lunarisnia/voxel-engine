#include "voxelengine/voxel_window/voxel_window.hpp"
int main() {
  VoxelEngine::VoxelWindow voxelWindow(800, 640, "Voxel Window");
  voxelWindow.show();
  return 0;
}
