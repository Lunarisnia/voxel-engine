#include "voxedit/tabs/inspector.hpp"
#include <string>
#include "imgui.h"
#include "voxelengine/math/vec3.hpp"
using namespace Voxedit;
std::shared_ptr<VoxelEngine::Object> Inspector::selectedObject;

void Inspector::Tick() {
  ImGui::Begin(name.c_str(), nullptr, flags);
  DrawComponents();
  ImGui::End();
}

void Inspector::DrawComponents() { DrawTransform(); }

VoxelEngine::Vec3 placeholder(0.0f);
void Inspector::DrawTransform() {
  if (ImGui::CollapsingHeader("Transform")) {
    if (selectedObject != nullptr) {
      ImGui::DragFloat3("Position", &selectedObject->transform->position.x,
                        0.005f);
      ImGui::DragFloat3("Scale", &selectedObject->transform->scale.x, 0.005f);
      ImGui::DragFloat3("Rotation", &placeholder.x, 0.005f);
      selectedObject->transform->SetRotationEuler(placeholder);
    }
  }
}
