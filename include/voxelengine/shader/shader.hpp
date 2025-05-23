#pragma once
#include "glad/glad.h"
#include <glm/gtc/matrix_transform.hpp>
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
  void Use();

  void SetMatrix4x4(const std::string& uniform, const glm::mat4& mat4);

  void SetInt(const std::string& uniform, const int i);
};
}  // namespace VoxelEngine
