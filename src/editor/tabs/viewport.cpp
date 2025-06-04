#include "imgui_internal.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "voxedit/tabs/viewport.hpp"
#include <iostream>
#include <memory>
#include "ImGuizmo.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "imgui.h"
#include "voxedit/tabs/inspector.hpp"
#include "voxelengine/components/camera.hpp"
#include "voxelengine/components/transform.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/renderer/renderer.hpp"
using namespace Voxedit;

void Viewport::Tick() {
  ImGui::Begin("Viewport", nullptr, flags);

  ImVec2 region = ImGui::GetContentRegionAvail();
  VoxelEngine::Renderer::SetViewport(0, 0, region.x, region.y);

  ImGui::Image(
      (ImTextureID)VoxelEngine::Renderer::renderTexture->GetTextureID(), region,
      ImVec2(0, 1), ImVec2(1, 0));

  TickGizmo();

  ImGui::End();
}

void Viewport::TickGizmo() {
  ImGuizmo::SetOrthographic(false);
  ImGuizmo::SetDrawlist(ImGui::GetCurrentWindow()->DrawList);

  float width = (float)ImGui::GetWindowWidth();
  float height = (float)ImGui::GetWindowHeight();
  ImGuizmo::SetRect(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y, width,
                    height);

  std::shared_ptr<VoxelEngine::Object> camera =
      VoxelEngine::Renderer::mainCamera;
  glm::mat4 view = camera->GetComponent<VoxelEngine::Camera>()->GetViewMatrix();
  glm::mat4 proj =
      camera->GetComponent<VoxelEngine::Camera>()->GetProjectionMatrix();
  glm::mat4 model =
      Inspector::selectedObject->GetComponent<VoxelEngine::Transform>()
          ->GetTransformMatrix();

  ImGuizmo::Manipulate(glm::value_ptr(view), glm::value_ptr(proj),
                       ImGuizmo::OPERATION::TRANSLATE, ImGuizmo::MODE::LOCAL,
                       glm::value_ptr(model));

  if (ImGuizmo::IsUsing()) {
    std::cout << "USING" << std::endl;
  }
}
