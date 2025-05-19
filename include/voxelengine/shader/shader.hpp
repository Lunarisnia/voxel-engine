#pragma once
#include "glad/glad.h"
#include <string>
namespace VoxelEngine {
enum ShaderType {
  VERTEX = GL_VERTEX_SHADER,
  FRAGMENT = GL_FRAGMENT_SHADER,
};
class Shader {
 private:
  static constexpr std::string errorPrefix = "ERROR::SHADER";
  GLuint id;

 private:
  GLuint createShader(ShaderType type);
  void compileShader(GLuint shaderId, const char* shaderSource);
  void createProgram();
  void linkShader(GLuint vertexShader, GLuint fragmentShader);

 public:
  Shader(std::string vertexPath, std::string fragmentPath);
  void use();
};
}  // namespace VoxelEngine
