#include "voxelengine/voxel_engine/voxel_engine.hpp"
using namespace VoxelEngine;

Engine::Engine(int width, int height, const char* title)
    : window(width, height, title) {};

void Engine::run() { window.show(); }
