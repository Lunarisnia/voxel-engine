#include "glad/glad.h"
#include "voxedit/editor.hpp"

int main() {
  Voxedit::Editor editor;
  editor.Initialize();

  editor.Tick();
  /*VoxelEngine::Engine voxelEngine(800, 640, "Voxel Engine");*/
  /*while (true) {*/
  /*  voxelEngine.Tick();*/
  /*}*/

  return 0;
}
