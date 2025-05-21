#include "voxelengine/shader/shader.hpp"
#include <iostream>
#include "voxelengine/error_handling/gl_error.hpp"
#include "voxelengine/resource/resource.hpp"
using namespace VoxelEngine;

Shader::Shader(std::string vertexPath, std::string fragmentPath) {
  std::string vertexSource = Resource::loadCodeFromPath(vertexPath);
  std::string fragmentSource = Resource::loadCodeFromPath(fragmentPath);

  GLuint vertexShader = createShader(VERTEX);
  compileShader(vertexShader, vertexSource.c_str());

  GLuint fragmentShader = createShader(FRAGMENT);
  compileShader(fragmentShader, fragmentSource.c_str());

  createProgram();
  linkShader(vertexShader, fragmentShader);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void Shader::use() {
  glUseProgram(id);
  GlErrorHandler::Log(errorPrefix);
}

GLuint Shader::createShader(ShaderType type) {
  GLuint id = glCreateShader(type);
  GlErrorHandler::Log(errorPrefix);
  return id;
}

void Shader::compileShader(GLuint shaderId, const char *shaderSource) {
  glShaderSource(shaderId, 1, &shaderSource, NULL);
  GlErrorHandler::Log(errorPrefix);
  glCompileShader(shaderId);
  GlErrorHandler::Log(errorPrefix);

  int code;
  glGetShaderiv(shaderId, GL_COMPILE_STATUS, &code);
  if (!code) {
    char infoLog[512];
    glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
    std::cout << "SHADER: " << infoLog << std::endl;
  }
}

void Shader::createProgram() {
  id = glCreateProgram();
  GlErrorHandler::Log(errorPrefix);
}

void Shader::linkShader(GLuint vertexShader, GLuint fragmentShader) {
  glAttachShader(id, vertexShader);
  GlErrorHandler::Log(errorPrefix);
  glAttachShader(id, fragmentShader);
  GlErrorHandler::Log(errorPrefix);
  glLinkProgram(id);
  GlErrorHandler::Log(errorPrefix);

  int code;
  glGetProgramiv(id, GL_LINK_STATUS, &code);
  if (!code) {
    char infoLog[512];
    glGetProgramInfoLog(id, 512, NULL, infoLog);
    std::cout << "PROGRAM: " << infoLog << std::endl;
  }
}
