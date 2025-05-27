#include "voxedit/editor.hpp"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"
#include "imgui.h"
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace Voxedit;

void Editor::Initialize() {
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

void Editor::Tick() {}

Editor::~Editor() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

// WIP: Imgui
