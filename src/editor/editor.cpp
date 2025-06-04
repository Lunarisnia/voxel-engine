#include "voxedit/editor.hpp"
#include <memory>
#include "ImGuizmo.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"
#include "imgui.h"
#include "voxedit/tabs/debug.hpp"
#include "voxedit/tabs/hierarchy.hpp"
#include "voxedit/tabs/inspector.hpp"
#include "voxedit/tabs/viewport.hpp"
#include "voxelengine/engine.hpp"
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/utilities/object_primitives.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
#include "voxelengine/world/world.hpp"
using namespace Voxedit;

void Editor::Initialize() {
  VoxelEngine::Engine::Initialize(1280, 800, "Voxel Engine");

  // Create the main camera
  std::shared_ptr<VoxelEngine::Object> mainCamera =
      VoxelEngine::ObjectPrimitives::GenerateCamera("MainCamera");
  mainCamera->transform->position.z = 5.0f;
  VoxelEngine::Renderer::mainCamera = mainCamera;
  VoxelEngine::World::AddObject(mainCamera);

  CreateTab<Viewport>("Viewport");
  CreateTab<Debug>("Debug");
  CreateTab<Hierarchy>("Hierarchy");
  CreateTab<Inspector>("Inspector");

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  ImGuiIO &io = ImGui::GetIO();
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

  if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_DockingEnable) {
    ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport(),
                                 ImGuiDockNodeFlags_PassthruCentralNode);
  }

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
  ImGuizmo::BeginFrame();
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
