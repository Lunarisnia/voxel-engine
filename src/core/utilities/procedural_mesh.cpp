#include "voxelengine/utilities/procedural_mesh.hpp"
#include "glm/ext/vector_float2.hpp"
#include "glm/ext/vector_float3.hpp"
#include "voxelengine/vertex_data.hpp"
using namespace VoxelEngine;

void ProceduralMesh::GenerateCubeMesh(std::shared_ptr<Mesh> &mesh) {
  // Cube Vertex Data
  VertexData vData;
  // Front face (z = 0.5)
  vData.position = glm::vec3(0.5f, 0.5f, 0.5f);  // Top right
  vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, -0.5f, 0.5f);  // Bottom right
  vData.textureCoordinate = glm::vec2(1.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(-0.5f, -0.5f, 0.5f);  // Bottom left
  vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, 0.5f, 0.5f);  // Top right
  vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(-0.5f, -0.5f, 0.5f);  // Bottom left
  vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(-0.5f, 0.5f, 0.5f);  // Top left
  vData.textureCoordinate = glm::vec2(0.0f, 1.0f);
  mesh->AddVertexData(vData);

  // Back face (z = -0.5)
  vData.position = glm::vec3(-0.5f, 0.5f, -0.5f);  // Top right
  vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(-0.5f, -0.5f, -0.5f);  // Bottom right
  vData.textureCoordinate = glm::vec2(1.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, -0.5f, -0.5f);  // Bottom left
  vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(-0.5f, 0.5f, -0.5f);  // Top right
  vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, -0.5f, -0.5f);  // Bottom left
  vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, 0.5f, -0.5f);  // Top left
  vData.textureCoordinate = glm::vec2(0.0f, 1.0f);
  mesh->AddVertexData(vData);

  // Left face (x = -0.5)
  vData.position = glm::vec3(-0.5f, 0.5f, 0.5f);  // Top right
  vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(-0.5f, -0.5f, 0.5f);  // Bottom right
  vData.textureCoordinate = glm::vec2(1.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(-0.5f, -0.5f, -0.5f);  // Bottom left
  vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(-0.5f, 0.5f, 0.5f);  // Top right
  vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(-0.5f, -0.5f, -0.5f);  // Bottom left
  vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(-0.5f, 0.5f, -0.5f);  // Top left
  vData.textureCoordinate = glm::vec2(0.0f, 1.0f);
  mesh->AddVertexData(vData);

  // Right face (x = 0.5)
  vData.position = glm::vec3(0.5f, 0.5f, -0.5f);  // Top right
  vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, -0.5f, -0.5f);  // Bottom right
  vData.textureCoordinate = glm::vec2(1.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, -0.5f, 0.5f);  // Bottom left
  vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, 0.5f, -0.5f);  // Top right
  vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, -0.5f, 0.5f);  // Bottom left
  vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, 0.5f, 0.5f);  // Top left
  vData.textureCoordinate = glm::vec2(0.0f, 1.0f);
  mesh->AddVertexData(vData);

  // Top face (y = 0.5)
  vData.position = glm::vec3(-0.5f, 0.5f, -0.5f);  // Top right
  vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, 0.5f, -0.5f);  // Bottom right
  vData.textureCoordinate = glm::vec2(1.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, 0.5f, 0.5f);  // Bottom left
  vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(-0.5f, 0.5f, -0.5f);  // Top right
  vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, 0.5f, 0.5f);  // Bottom left
  vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(-0.5f, 0.5f, 0.5f);  // Top left
  vData.textureCoordinate = glm::vec2(0.0f, 1.0f);
  mesh->AddVertexData(vData);

  // Bottom face (y = -0.5)
  vData.position = glm::vec3(-0.5f, -0.5f, 0.5f);  // Top right
  vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, -0.5f, 0.5f);  // Bottom right
  vData.textureCoordinate = glm::vec2(1.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, -0.5f, -0.5f);  // Bottom left
  vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(-0.5f, -0.5f, 0.5f);  // Top right
  vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(0.5f, -0.5f, -0.5f);  // Bottom left
  vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
  mesh->AddVertexData(vData);
  vData.position = glm::vec3(-0.5f, -0.5f, -0.5f);  // Top left
  vData.textureCoordinate = glm::vec2(0.0f, 1.0f);
  mesh->AddVertexData(vData);
}

void ProceduralMesh::GeneratePlaneMesh(std::shared_ptr<Mesh> &mesh) {
  VertexData vData;
  {
    vData.position = glm::vec3(0.5f, 0.5f, 0.0f);
    vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(0);
  }
  {
    vData.position = glm::vec3(0.5f, -0.5f, 0.0f);
    vData.textureCoordinate = glm::vec2(1.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(1);
  }
  {
    vData.position = glm::vec3(-0.5f, -0.5f, 0.0f);
    vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(2);
  }
  {
    vData.position = glm::vec3(-0.5f, 0.5f, 0.0f);
    vData.textureCoordinate = glm::vec2(0.0f, 1.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(3);
  }
  {
    vData.position = glm::vec3(-0.5f, -0.5f, 0.0f);
    vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(2);
  }
  {
    mesh->AddIndex(0);
  }
}
