#include "voxedit/tabs/inspector.hpp"
#include <string>
#include "imgui.h"
using namespace Voxedit;

void Inspector::Tick() {
  ImGui::Begin(name.c_str(), nullptr, flags);
  ImGui::ShowDemoWindow();

  ImGui::End();
}
