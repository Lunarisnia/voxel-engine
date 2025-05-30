#include "voxedit/tabs/viewport.hpp"
#include "imgui.h"
using namespace Voxedit;

void Viewport::Tick() {
  ImGui::SetNextWindowSize(ImVec2(640, 480));
  ImGui::Begin("Viewport", nullptr, flags);

  ImVec2 region = ImGui::GetContentRegionAvail();
  /*VoxelEngine::Renderer::SetViewport(0, 0, (int)region.x * 2.0f,*/
  /*                                   (int)region.y * 2.0f);*/

  ImGui::Text("Hello");

  ImGui::End();
}

// TODO: Display framebuffer as an texture image in this viewport
