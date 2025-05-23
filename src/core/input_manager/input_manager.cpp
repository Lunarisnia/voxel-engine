#include "voxelengine/input_manager/input_manager.hpp"
#include "GLFW/glfw3.h"
#include "voxelengine/voxel_window/voxel_window.hpp"

using namespace VoxelEngine;

void InputManager::Initialize() {
  glfwSetInputMode(VoxelWindow::GetWindow(), GLFW_STICKY_KEYS, GLFW_TRUE);
  glfwSetInputMode(VoxelWindow::GetWindow(), GLFW_STICKY_MOUSE_BUTTONS,
                   GLFW_TRUE);
}

bool InputManager::GetKey(int keyCode) {
  int state = glfwGetKey(VoxelWindow::GetWindow(), keyCode);
  return state == GLFW_PRESS;
}
