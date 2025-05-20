#include "voxelengine/voxel_engine/voxel_engine.hpp"
#include "voxelengine/components/transform.hpp"
#include "voxelengine/input_manager/input_manager.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace VoxelEngine;

Engine::Engine(int width, int height, const char* title) {
  VoxelWindow::initialize(width, height, title);
  InputManager::initialize();
  Transform test = Transform();
  /*std::cout << "TEST: " << test.isUnique() << std::endl;*/
};

void Engine::run() { VoxelWindow::render(); }
