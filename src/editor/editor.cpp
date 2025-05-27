#include "voxedit/editor.hpp"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"
#include "imgui.h"
#include "voxelengine/engine.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace Voxedit;

void Editor::Initialize() {
  VoxelEngine::Engine::Initialize(800, 600, "Game");
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  ImGuiIO& io = ImGui::GetIO();
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

  ImGui_ImplGlfw_InitForOpenGL(VoxelEngine::VoxelWindow::GetWindow(), true);
  ImGui_ImplOpenGL3_Init();
}

void Editor::Render() {
  newFrame();
  ImGui::ShowDemoWindow();
  drawFrame();
}

void Editor::Tick() {
  while (true) {
    VoxelEngine::Engine::Tick();
    Render();
    VoxelEngine::VoxelWindow::SwapBuffer();
  }
}

void Editor::newFrame() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

void Editor::drawFrame() {
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

Editor::~Editor() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

// WIP: Imgui
