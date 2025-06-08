#include "voxelengine/input_manager/input_manager.hpp"
#include "GLFW/glfw3.h"
#include "voxelengine/input_manager/mouse_event.hpp"
#include "voxelengine/log/logger.hpp"
#include "voxelengine/math/vec2.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace VoxelEngine;

MouseEvent InputManager::mouse = MouseEvent();

void InputManager::Initialize() {
  glfwSetInputMode(VoxelWindow::GetWindow(), GLFW_STICKY_KEYS, GLFW_TRUE);
  glfwSetInputMode(VoxelWindow::GetWindow(), GLFW_STICKY_MOUSE_BUTTONS,
                   GLFW_TRUE);

  Logger::Log(LogCategory::INFO, "Initialized InputManager",
              "InputManager::Initialize");
}

bool InputManager::GetKey(int keyCode) {
  int state = glfwGetKey(VoxelWindow::GetWindow(), keyCode);
  return state == GLFW_PRESS;
}

void InputManager::PollMouse() {
  double xPos, yPos;
  glfwGetCursorPos(VoxelWindow::GetWindow(), &xPos, &yPos);

  mouse.position = Vec2((float)xPos, (float)yPos);
}
