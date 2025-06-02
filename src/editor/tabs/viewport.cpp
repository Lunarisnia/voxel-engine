#include "voxedit/tabs/viewport.hpp"
#include "imgui.h"
#include "voxelengine/renderer/renderer.hpp"
using namespace Voxedit;

void Viewport::Tick() {
  ImGui::Begin("Viewport", nullptr, flags);

  ImVec2 region = ImGui::GetContentRegionAvail();
  // TODO: Texture and render buffer also needs to be resized
  VoxelEngine::Renderer::SetViewport(0, 0, region.x, region.y);

  // NOTE: If no image then it probaly just mean the generated image is out of
  // view
  ImGui::Image(
      (ImTextureID)VoxelEngine::Renderer::renderTexture->GetTextureID(), region,
      ImVec2(0, 1), ImVec2(1, 0));

  ImGui::End();
}
