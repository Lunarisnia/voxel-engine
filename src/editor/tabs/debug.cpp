#include "voxedit/tabs/debug.hpp"
#include "imgui.h"
using namespace Voxedit;

void Debug::Tick() {
  ImGui::Begin(name.c_str(), nullptr, flags);

  ImGuiIO io = ImGui::GetIO();
  ImGui::Text("Framerate: %.1f", io.Framerate);

  ImGui::End();
}
