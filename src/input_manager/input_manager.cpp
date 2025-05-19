#include "voxelengine/input_manager/input_manager.hpp"
#include "voxelengine/input_manager/key_event.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"

using namespace VoxelEngine;

KeyEvent InputManager::keys[349];

void InputManager::initialize() {
  VoxelWindow::registerKeyCallback(key_callback);
}

void InputManager::key_callback(GLFWwindow* window, int key, int scancode,
                                int action, int mods) {
  pressKey(key, scancode, action, mods);
}

void InputManager::pressKey(int key, int scancode, int action, int mods) {
  KeyEvent ke;
  ke.key = key;
  ke.scancode = scancode;
  ke.action = action;
  ke.mods = mods;
  keys[key] = ke;
}
