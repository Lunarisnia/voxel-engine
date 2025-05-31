#include "glad/glad.h"
#include "voxelengine/framebuffer/framebuffer.hpp"
#include <memory>
using namespace VoxelEngine;

Framebuffer::Framebuffer() { glGenFramebuffers(1, &id); }

void Framebuffer::Bind() { glBindFramebuffer(GL_FRAMEBUFFER, id); }

void Framebuffer::Unbind() { glBindFramebuffer(GL_FRAMEBUFFER, 0); }

void Framebuffer::SetTexture(std::shared_ptr<Texture> texture) {
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
                         texture->GetTextureID(), 0);
}
