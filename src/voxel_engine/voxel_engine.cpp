#include "voxelengine/voxel_engine/voxel_engine.hpp"
#include <memory>
#include "voxelengine/input_manager/input_manager.hpp"
using namespace VoxelEngine;

std::shared_ptr<InputManager> inputManager = std::make_shared<InputManager>();
void Engine::key_callback(GLFWwindow* window, int key, int scancode, int action,
                          int mods) {
  inputManager->pressKey(key, scancode, action, mods);
}

Engine::Engine(int width, int height, const char* title)
    : window(width, height, title) {
  window.registerKeyCallback(key_callback);
};

void Engine::run() { window.show(); }
