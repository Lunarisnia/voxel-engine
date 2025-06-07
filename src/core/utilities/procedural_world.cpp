#include "voxelengine/utilities/procedural_world.hpp"
#include <vector>
#include "voxelengine/block/block.hpp"
using namespace VoxelEngine;

void ProceduralWorld::GenerateBlockChunk(std::shared_ptr<Chunk> &chunk) {
  for (int i = 0; i < chunk->size; i++) {
    std::vector<std::vector<Block>> blockX;
    for (int j = 0; j < chunk->size; j++) {
      std::vector<Block> blockY;
      for (int k = 0; k < chunk->size; k++) {
        Block block;
        blockY.emplace_back(block);
      }
      blockX.emplace_back(blockY);
    }
    chunk->blocks.emplace_back(blockX);
  }
}
