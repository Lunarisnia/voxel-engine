#pragma once
namespace VoxelEngine {
class Renderbuffer {
 private:
  unsigned int id;

 public:
  int width, height;

 public:
  void Bind();

 public:
  Renderbuffer(int width, int height);
};
};  // namespace VoxelEngine
