#include "voxelengine/utilities/procedural_mesh.hpp"
#include "glm/ext/vector_float3.hpp"
#include "voxelengine/vertex_data.hpp"
using namespace VoxelEngine;

void ProceduralMesh::GenerateCubeMesh(std::shared_ptr<Mesh> &mesh) {
  // Cube Vertex Data
  VertexData vData;
  {                                                // Front
    vData.position = glm::vec3(0.5f, 0.5f, 0.0f);  // Top right
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, 0.0f);  // Bottom right
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, 0.0f);  // Bottom left
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, 0.5f, 0.0f);  // Top right
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, 0.5f, 0.0f);  // Top left
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, 0.0f);  // Bottom left
    mesh->addVertexData(vData);
  }
}
