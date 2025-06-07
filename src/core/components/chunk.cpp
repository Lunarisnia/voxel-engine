#include "voxelengine/components/chunk.hpp"
#include <memory>
#include "voxelengine/components/mesh.hpp"
#include "voxelengine/object/object.hpp"
#include "voxelengine/utilities/procedural_mesh.hpp"
using namespace VoxelEngine;

Chunk::Chunk(int size) : size(size) {}

void Chunk::Tick() {}

void Chunk::rebuild() {
  Object *o = owner;
  std::shared_ptr<Mesh> mesh = o->GetComponent<Mesh>();
  std::shared_ptr<Chunk> chunk = o->GetComponent<Chunk>();
  mesh->ClearVertice();
  ProceduralMesh::GenerateChunk(mesh, chunk);
  mesh->SetupMesh();
}

void Chunk::SetBlockActiveState(const int &x, const int &y, const int &z,
                                const bool &state) {
  if (state != blocks[x][y][z].isActive) {
    blocks[x][y][z].isActive = state;
    rebuild();
  }
}
