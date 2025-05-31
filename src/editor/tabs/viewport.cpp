#include "voxedit/tabs/viewport.hpp"
#include "imgui.h"
#include "voxelengine/renderer/renderer.hpp"
using namespace Voxedit;

void Viewport::Tick() {
  ImGui::SetNextWindowSize(ImVec2(800, 600));
  ImGui::Begin("Viewport", nullptr, flags);

  ImVec2 region = ImGui::GetContentRegionAvail();
  /*VoxelEngine::Renderer::SetViewport(0, 0, (int)region.x * 2.0f,*/
  /*                                   (int)region.y * 2.0f);*/

  // FIXME: Somehow this screen is always black. Something to do with how the
  // renderbuffer are setup maybe?
  ImGui::Image(
      (ImTextureID)VoxelEngine::Renderer::renderTexture->GetTextureID(),
      ImVec2(800.0f, 600.0f), ImVec2(0, 1), ImVec2(1, 0));

  ImGui::Text("Hello");

  ImGui::End();
}

// TODO: Display framebuffer as an texture image in this viewport
