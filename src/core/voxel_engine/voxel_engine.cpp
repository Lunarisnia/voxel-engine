#include "stbi_image/stbi_image.h"
#include "voxelengine/engine.hpp"
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/input_manager/input_manager.hpp"
#include "voxelengine/time/time.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
#include "voxelengine/world/world.hpp"
using namespace VoxelEngine;

void Engine::Initialize(int width, int height, const char *title) {
  VoxelWindow::Initialize(width, height, title);
  Time::Initialize();
  InputManager::Initialize();
  Renderer::Initialize();
  World::Initialize();
}

void Engine::Tick() {
  VoxelWindow::PollEvent();
  Renderer::framebuffer->Bind();
  Renderer::Clear();
  Time::Tick();
  World::Tick();
  Renderer::Tick();
  Renderer::framebuffer->Unbind();
}

// TODO: add glfw keycode as our own constant
