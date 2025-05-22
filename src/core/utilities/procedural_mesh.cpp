#include "voxelengine/utilities/procedural_mesh.hpp"
#include "glm/ext/vector_float3.hpp"
#include "voxelengine/vertex_data.hpp"
using namespace VoxelEngine;

void ProceduralMesh::GenerateCubeMesh(std::shared_ptr<Mesh> &mesh) {
  // Cube Vertex Data
  VertexData vData;
  // Front face (Z+)
  {
    vData.position = glm::vec3(0.5f, 0.5f, 0.5f);  // Top right
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, 0.5f);  // Bottom right
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, 0.5f);  // Bottom left
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, 0.5f, 0.5f);  // Top right
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, 0.5f);  // Bottom left
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, 0.5f, 0.5f);  // Top left
    mesh->addVertexData(vData);
  }

  // Back face (Z-)
  {
    vData.position = glm::vec3(-0.5f, 0.5f, -0.5f);  // Top left
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, -0.5f);  // Bottom left
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, -0.5f);  // Bottom right
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, 0.5f, -0.5f);  // Top left
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, -0.5f);  // Bottom right
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, 0.5f, -0.5f);  // Top right
    mesh->addVertexData(vData);
  }

  // Left face (X-)
  {
    vData.position = glm::vec3(-0.5f, 0.5f, 0.5f);  // Top front
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, 0.5f);  // Bottom front
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, -0.5f);  // Bottom back
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, 0.5f, 0.5f);  // Top front
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, -0.5f);  // Bottom back
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, 0.5f, -0.5f);  // Top back
    mesh->addVertexData(vData);
  }

  // Right face (X+)
  {
    vData.position = glm::vec3(0.5f, 0.5f, -0.5f);  // Top back
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, -0.5f);  // Bottom back
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, 0.5f);  // Bottom front
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, 0.5f, -0.5f);  // Top back
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, 0.5f);  // Bottom front
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, 0.5f, 0.5f);  // Top front
    mesh->addVertexData(vData);
  }

  // Top face (Y+)
  {
    vData.position = glm::vec3(0.5f, 0.5f, -0.5f);  // Back right
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, 0.5f, 0.5f);  // Front right
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, 0.5f, 0.5f);  // Front left
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, 0.5f, -0.5f);  // Back right
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, 0.5f, 0.5f);  // Front left
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, 0.5f, -0.5f);  // Back left
    mesh->addVertexData(vData);
  }

  // Bottom face (Y-)
  {
    vData.position = glm::vec3(-0.5f, -0.5f, -0.5f);  // Back left
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, 0.5f);  // Front left
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, 0.5f);  // Front right
    mesh->addVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, -0.5f);  // Back left
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, 0.5f);  // Front right
    mesh->addVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, -0.5f);  // Back right
    mesh->addVertexData(vData);
  }
}
