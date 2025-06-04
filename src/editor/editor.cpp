#include "voxedit/editor.hpp"
#include <memory>
#include <string>
#include "ImGuizmo.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"
#include "imgui.h"
#include "imgui_internal.h"
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

  ImGuiViewport *viewport = ImGui::GetMainViewport();
  ImGui::SetNextWindowPos(viewport->WorkPos);
  ImGui::SetNextWindowSize(viewport->WorkSize);
  ImGui::SetNextWindowViewport(viewport->ID);

  std::string name = "Editor";
  ImGui::Begin(name.c_str(), nullptr,
               ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar |
                   ImGuiWindowFlags_NoDocking);

  if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_DockingEnable) {
    const ImGuiID windowId = ImGui::GetID(name.c_str());
    if (ImGui::DockBuilderGetNode(windowId) == nullptr) {
      ImGui::DockBuilderRemoveNode(windowId);

      ImGui::DockBuilderAddNode(windowId, ImGuiDockNodeFlags_DockSpace);
      ImGui::DockBuilderSetNodeSize(windowId, ImGui::GetWindowSize());

      ImGuiID viewportId = windowId;
      ImGuiID hierarchyId = ImGui::DockBuilderSplitNode(
          viewportId, ImGuiDir_Left, 0.50f, nullptr, &viewportId);
      ImGuiID inspectorId = ImGui::DockBuilderSplitNode(
          viewportId, ImGuiDir_Right, 0.50f, nullptr, &viewportId);
      ImGuiID debugId = ImGui::DockBuilderSplitNode(
          inspectorId, ImGuiDir_Down, 0.50f, nullptr, &inspectorId);

      ImGui::DockBuilderDockWindow("Viewport", viewportId);
      ImGui::DockBuilderDockWindow("Hierarchy", hierarchyId);
      ImGui::DockBuilderDockWindow("Inspector", inspectorId);
      ImGui::DockBuilderDockWindow("Debug", debugId);
    }
    ImGui::DockSpace(windowId, ImVec2(0.0f, 0.0f),
                     ImGuiDockNodeFlags_PassthruCentralNode);
  }

  for (const std::shared_ptr<EditorTab> &tab : tabs) {
    tab->Tick();
  }

  ImGui::End();

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
