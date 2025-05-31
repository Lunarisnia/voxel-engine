#include "voxelengine/shader/shader.hpp"
#include <iostream>
#include "glm/ext/matrix_float4x4.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "voxelengine/error_handling/gl_error.hpp"
#include "voxelengine/resource/resource.hpp"
using namespace VoxelEngine;

Shader::Shader(std::string vertexPath, std::string fragmentPath) {
  std::string vertexSource = Resource::LoadCodeFromPath(vertexPath);
  std::string fragmentSource = Resource::LoadCodeFromPath(fragmentPath);

  GLuint vertexShader = createShader(VERTEX);
  compileShader(vertexShader, vertexSource.c_str());

  GLuint fragmentShader = createShader(FRAGMENT);
  compileShader(fragmentShader, fragmentSource.c_str());

  createProgram();
  linkShader(vertexShader, fragmentShader);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void Shader::Use() {
  glUseProgram(id);
  GlErrorHandler::Log(errorPrefix + "::Use");
}

GLuint Shader::createShader(ShaderType type) {
  GLuint id = glCreateShader(type);
  GlErrorHandler::Log(errorPrefix + "::createShader");
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

void Shader::SetMatrix4x4(const std::string &uniform, const glm::mat4 &mat4) {
  Use();
  GLint location = glGetUniformLocation(id, uniform.c_str());
  if (location != -1) {
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat4));
    GlErrorHandler::Log(errorPrefix);
  }
}

void Shader::SetInt(const std::string &uniform, const int i) {
  Use();
  GLint location = glGetUniformLocation(id, uniform.c_str());
  if (location != -1) {
    glUniform1i(location, i);
    GlErrorHandler::Log(errorPrefix);
  }
}
