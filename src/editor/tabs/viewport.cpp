#include "voxedit/tabs/viewport.hpp"
#include "imgui.h"
#include "voxelengine/renderer/renderer.hpp"
#include "voxelengine/voxel_window/voxel_window.hpp"
using namespace Voxedit;

void Viewport::Tick() {
  ImGui::Begin("Viewport", nullptr, flags);

  ImVec2 region = ImGui::GetContentRegionAvail();
  // TODO: Texture and render buffer also needs to be resized
  VoxelEngine::VoxelWindow::width = region.x;
  VoxelEngine::VoxelWindow::height = region.y;
  VoxelEngine::Renderer::SetViewport(0, 0, (int)region.x * 2,
                                     (int)region.y * 2);

  // NOTE: If no image then it probaly just mean the generated image is out of
  // view
  ImGui::Image(
      (ImTextureID)VoxelEngine::Renderer::renderTexture->GetTextureID(), region,
      ImVec2(0, 1), ImVec2(1, 0));

  ImGui::End();
}
