#include "glad/glad.h"
#include "voxelengine/renderbuffer/renderbuffer.hpp"
using namespace VoxelEngine;

Renderbuffer::Renderbuffer(int width, int height)
    : width(width), height(height) {
  glGenRenderbuffers(1, &id);
  glBindRenderbuffer(GL_RENDERBUFFER, id);
  glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
  glBindRenderbuffer(GL_RENDERBUFFER, 0);
  glFramebufferRenderbuffer(GL_RENDERBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
                            GL_RENDERBUFFER, id);
}

void Renderbuffer::Bind() { glBindRenderbuffer(GL_RENDERBUFFER, id); }
