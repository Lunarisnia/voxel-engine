#include "glad/glad.h"
#include "voxelengine/renderbuffer/renderbuffer.hpp"
using namespace VoxelEngine;

Renderbuffer::Renderbuffer(int width, int height)
    : width(width), height(height) {
  glGenRenderbuffers(1, &id);
  Bind();
  glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
  glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
                            GL_RENDERBUFFER, id);
  Unbind();
}

void Renderbuffer::Bind() { glBindRenderbuffer(GL_RENDERBUFFER, id); }

void Renderbuffer::Unbind() { glBindRenderbuffer(GL_RENDERBUFFER, 0); }

void Renderbuffer::Resize(int width, int height) {
  Bind();
  glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
}
