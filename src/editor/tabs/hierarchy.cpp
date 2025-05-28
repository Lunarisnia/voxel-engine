#include "voxedit/tabs/hierarchy.hpp"
#include "imgui.h"
using namespace Voxedit;

static int itemIndex = 1;

void Hierarchy::Tick() {
  ImGui::Begin("Hierarchy");

  ImGui::Text("Hello");
  const char* items[] = {"A", "B", "C"};
  ImGui::ListBox("Objects", &itemIndex, items, IM_ARRAYSIZE(items));

  ImGui::End();
}

// TODO: Create object hierarchy that refer to the worldObjects
