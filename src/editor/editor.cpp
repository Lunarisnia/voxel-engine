#include "voxedit/editor.hpp"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"
#include "imgui.h"
#include "voxedit/tabs/debug.hpp"
#include "voxedit/tabs/hierarchy.hpp"
#include "voxelengine/engine.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace Voxedit;

void Editor::Initialize() {
  VoxelEngine::Engine::Initialize(800, 600, "Game");

  CreateTab<Debug>("Debug");
  CreateTab<Hierarchy>("Debug");

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  ImGuiIO io = ImGui::GetIO();
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableGamepad;             // Enable Gamepad Controls
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;  // Enable docking

  ImGui_ImplGlfw_InitForOpenGL(VoxelEngine::VoxelWindow::GetWindow(), true);
  ImGui_ImplOpenGL3_Init();
}

void Editor::Render() {
  newFrame();

  for (const std::shared_ptr<EditorTab> &tab : tabs) {
    tab->Tick();
  }

  drawFrame();
}

void Editor::Tick() {
  while (!VoxelEngine::VoxelWindow::ShouldClose()) {
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
