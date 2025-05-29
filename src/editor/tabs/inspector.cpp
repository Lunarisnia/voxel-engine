#include "voxedit/tabs/inspector.hpp"
#include <string>
#include "imgui.h"
using namespace Voxedit;
std::shared_ptr<VoxelEngine::Object> Inspector::selectedObject;

void Inspector::Tick() {
  ImGui::Begin(name.c_str(), nullptr, flags);
  if (selectedObject != nullptr) {
    ImGui::Text("%s", selectedObject->name.c_str());
  }
  /*ImGui::ShowDemoWindow();*/

  ImGui::End();
}
