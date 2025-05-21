#include "voxelengine/input_manager/input_manager.hpp"
#include "GLFW/glfw3.h"
#include "voxelengine/voxel_window/voxel_window.hpp"

using namespace VoxelEngine;

void InputManager::initialize() {
  glfwSetInputMode(VoxelWindow::getWindow(), GLFW_STICKY_KEYS, GLFW_TRUE);
  glfwSetInputMode(VoxelWindow::getWindow(), GLFW_STICKY_MOUSE_BUTTONS,
                   GLFW_TRUE);
}

bool InputManager::getKey(int keyCode) {
  int state = glfwGetKey(VoxelWindow::getWindow(), keyCode);
  return state == GLFW_PRESS;
}
