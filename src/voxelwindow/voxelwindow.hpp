#ifndef VOXEL_WINDOW_H
#define VOXEL_WINDOW_H
class VoxelWindow {
public:
  int width, height;
  VoxelWindow(int width, int height);

  void show();
};
#endif
