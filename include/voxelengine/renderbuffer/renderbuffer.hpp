#pragma once
namespace VoxelEngine {
class Renderbuffer {
 private:
  unsigned int id;

 public:
  int width, height;

 public:
  void Bind();
  void Unbind();
  void Resize(int width, int height);

 public:
  Renderbuffer(int width, int height);
};
};  // namespace VoxelEngine
