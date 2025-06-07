#pragma once
#include "voxelengine/block/block_type.hpp"
namespace VoxelEngine {
// TODO: this might be better as a component
class Block {
 public:
  BlockType type = BlockType::DIRT;
  bool isActive = true;

 public:
  Block();
};
};  // namespace VoxelEngine
