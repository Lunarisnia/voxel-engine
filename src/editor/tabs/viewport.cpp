#include "voxedit/tabs/viewport.hpp"
#include "imgui.h"
#include "voxelengine/renderer/renderer.hpp"
using namespace Voxedit;

void Viewport::Tick() {
  ImGui::Begin("Viewport", nullptr, flags);

  ImVec2 region = ImGui::GetContentRegionAvail();
  VoxelEngine::Renderer::SetViewport(0, 0, region.x, region.y);

  ImGui::Image(
      (ImTextureID)VoxelEngine::Renderer::renderTexture->GetTextureID(), region,
      ImVec2(0, 1), ImVec2(1, 0));

  ImGui::End();
}
