#include "voxelengine/utilities/procedural_mesh.hpp"
#include "glm/ext/vector_float2.hpp"
#include "glm/ext/vector_float3.hpp"
#include "voxelengine/vertex_data.hpp"
using namespace VoxelEngine;

void ProceduralMesh::GenerateCubeMesh(std::shared_ptr<Mesh> &mesh) {
  // Cube Vertex Data
  VertexData vData;
  // Front face (Z+)
  {
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
  }

  // Back face (Z-)
  {
    vData.position = glm::vec3(-0.5f, 0.5f, -0.5f);  // Top left
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, -0.5f);  // Bottom left
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, -0.5f);  // Bottom right
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(-0.5f, 0.5f, -0.5f);  // Top left
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, -0.5f);  // Bottom right
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(0.5f, 0.5f, -0.5f);  // Top right
    mesh->AddVertexData(vData);
  }

  // Left face (X-)
  {
    vData.position = glm::vec3(-0.5f, 0.5f, 0.5f);  // Top front
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, 0.5f);  // Bottom front
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, -0.5f);  // Bottom back
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(-0.5f, 0.5f, 0.5f);  // Top front
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, -0.5f);  // Bottom back
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(-0.5f, 0.5f, -0.5f);  // Top back
    mesh->AddVertexData(vData);
  }

  // Right face (X+)
  {
    vData.position = glm::vec3(0.5f, 0.5f, -0.5f);  // Top back
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, -0.5f);  // Bottom back
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, 0.5f);  // Bottom front
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(0.5f, 0.5f, -0.5f);  // Top back
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, 0.5f);  // Bottom front
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(0.5f, 0.5f, 0.5f);  // Top front
    mesh->AddVertexData(vData);
  }

  // Top face (Y+)
  {
    vData.position = glm::vec3(0.5f, 0.5f, -0.5f);  // Back right
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(0.5f, 0.5f, 0.5f);  // Front right
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(-0.5f, 0.5f, 0.5f);  // Front left
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(0.5f, 0.5f, -0.5f);  // Back right
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(-0.5f, 0.5f, 0.5f);  // Front left
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(-0.5f, 0.5f, -0.5f);  // Back left
    mesh->AddVertexData(vData);
  }

  // Bottom face (Y-)
  {
    vData.position = glm::vec3(-0.5f, -0.5f, -0.5f);  // Back left
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, 0.5f);  // Front left
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, 0.5f);  // Front right
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(-0.5f, -0.5f, -0.5f);  // Back left
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, 0.5f);  // Front right
    mesh->AddVertexData(vData);
    vData.position = glm::vec3(0.5f, -0.5f, -0.5f);  // Back right
    mesh->AddVertexData(vData);
  }
}

void ProceduralMesh::GeneratePlaneMesh(std::shared_ptr<Mesh> &mesh) {
  VertexData vData;
  {
    vData.position = glm::vec3(0.5f, 0.5f, 0.0f);
    vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
    mesh->AddVertexData(vData);
  }
  {
    vData.position = glm::vec3(0.5f, -0.5f, 0.0f);
    vData.textureCoordinate = glm::vec2(1.0f, 0.0f);
    mesh->AddVertexData(vData);
  }
  {
    vData.position = glm::vec3(-0.5f, -0.5f, 0.0f);
    vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
    mesh->AddVertexData(vData);
  }

  {
    vData.position = glm::vec3(0.5f, 0.5f, 0.0f);
    vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
    mesh->AddVertexData(vData);
  }
  {
    vData.position = glm::vec3(-0.5f, 0.5f, 0.0f);
    vData.textureCoordinate = glm::vec2(0.0f, 1.0f);
    mesh->AddVertexData(vData);
  }
  {
    vData.position = glm::vec3(-0.5f, -0.5f, 0.0f);
    vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
    mesh->AddVertexData(vData);
  }
}
