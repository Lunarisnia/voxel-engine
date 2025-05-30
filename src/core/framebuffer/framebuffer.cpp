#include "voxelengine/framebuffer/framebuffer.hpp"
#include <memory>
#include "voxelengine/texture/texture.hpp"
using namespace VoxelEngine;

Framebuffer::Framebuffer() { glGenFramebuffers(1, &fbo); }

void Framebuffer::Bind() { glBindFramebuffer(GL_FRAMEBUFFER, fbo); }

void Framebuffer::SetTexture(std::shared_ptr<Texture> texture) {
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
                         texture->GetTextureID(), 0);
}

// TODO: Setup the render buffer object
// TODO: Create a render target
// TODO: Render to texture
