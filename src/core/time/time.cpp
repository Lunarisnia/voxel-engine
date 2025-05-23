#include "voxelengine/time/time.hpp"
#include "GLFW/glfw3.h"
using namespace VoxelEngine;

float Time::timeSinceStartup;
float Time::deltaTime;

void Time::Initialize() {
  timeSinceStartup = 0.0f;
  deltaTime = 0.0f;
}

void Time::Tick() {
  const float currentTime = (float)glfwGetTime();

  deltaTime = currentTime - timeSinceStartup;
  timeSinceStartup = currentTime;
}
