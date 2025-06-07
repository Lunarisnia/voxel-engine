#pragma once
#include "voxelengine/components/chunk.hpp"
namespace VoxelEngine {
class ProceduralWorld {
 public:
  static void GenerateBlockChunk(std::shared_ptr<Chunk> &chunk);
};
};  // namespace VoxelEngine
