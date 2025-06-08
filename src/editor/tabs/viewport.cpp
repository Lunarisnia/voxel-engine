#include "imgui_internal.h"
#include "voxelengine/input_manager/input_manager.hpp"
#include "voxelengine/input_manager/key_codes.hpp"
#include "voxedit/tabs/viewport.hpp"
#include <memory>
#include "ImGuizmo.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "imgui.h"
#include "voxedit/tabs/inspector.hpp"
#include "voxelengine/components/camera.hpp"
#include "voxelengine/components/transform.hpp"
#include "voxelengine/math/vec2.hpp"
#include "voxelengine/math/vec3.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/renderer/renderer.hpp"
using namespace Voxedit;

void Viewport::Tick() {
  ImGui::Begin("Viewport", nullptr, flags);

  ImVec2 region = ImGui::GetContentRegionAvail();
  size = VoxelEngine::Vec2(region.x, region.y);

  ImVec2 pos = ImGui::GetCursorScreenPos();
  position = VoxelEngine::Vec2(pos.x, pos.y);

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
  if (!ImGuizmo::IsUsing()) {
    if (VoxelEngine::InputManager::GetKey(KEY_Q)) {
      operation = ImGuizmo::OPERATION::TRANSLATE;
    } else if (VoxelEngine::InputManager::GetKey(KEY_R)) {
      operation = ImGuizmo::OPERATION::ROTATE;
    } else if (VoxelEngine::InputManager::GetKey(KEY_E)) {
      operation = ImGuizmo::OPERATION::SCALE;
    }
  }

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
  // FIXME: use delta instead of modifying the matrix directly later
  /*glm::mat4 delta;*/

  bool isModified =
      ImGuizmo::Manipulate(glm::value_ptr(view), glm::value_ptr(proj),
                           operation, mode, glm::value_ptr(model));

  if (ImGuizmo::IsUsing() && isModified) {
    VoxelEngine::Vec3 position;
    VoxelEngine::Vec3 rotationEuler;
    VoxelEngine::Vec3 scale;
    ImGuizmo::DecomposeMatrixToComponents(glm::value_ptr(model), &position.x,
                                          &rotationEuler.x, &scale.x);

    std::shared_ptr<VoxelEngine::Transform> transform =
        Inspector::selectedObject->GetComponent<VoxelEngine::Transform>();
    if (operation == ImGuizmo::OPERATION::TRANSLATE) {
      transform->SetPosition(position);
    } else if (operation == ImGuizmo::OPERATION::ROTATE) {
      // FIXME: Rotation is also acting weird in some angles
      transform->SetRotationEuler(rotationEuler.Deg2Rad());
    } else if (operation == ImGuizmo::OPERATION::SCALE) {
      // FIXME: no idea why its quite weird on some angle
      // FIXME: Scale and rotate don't really play well for some reason
      transform->SetScale(scale);
    }
  }
}
