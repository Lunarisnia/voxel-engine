#include "voxelengine/error_handling/gl_error.hpp"
#include "glad/glad.h"
#include <iostream>

using namespace VoxelEngine;

void GlErrorHandler::Log(std::string prefix) {
  GLuint errorCode = glGetError();
  if (errorCode != GL_NO_ERROR) {
    std::cout << prefix << ": " << std::hex << glGetError() << std::endl;
  }
}
