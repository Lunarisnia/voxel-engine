#include "voxelengine/utilities/procedural_mesh.hpp"
#include "glm/ext/vector_float2.hpp"
#include "glm/ext/vector_float3.hpp"
#include "voxelengine/vertex_data.hpp"
using namespace VoxelEngine;

void ProceduralMesh::GenerateChunk(std::shared_ptr<Mesh> &mesh,
                                   std::shared_ptr<Chunk> &chunk) {
  float blockSize = 0.5f;
  VertexData vData;
  for (int i = 0; i < chunk->size; i++) {
    for (int j = 0; j < chunk->size; j++) {
      for (int k = 0; k < chunk->size; k++) {
        float x = (float)i;
        float y = (float)j;
        float z = (float)k;
        {  // Front face
          vData.position = glm::vec3(x + blockSize, y + blockSize,
                                     z + blockSize);  // Top right
          vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
          mesh->AddVertexData(vData);

          vData.position = glm::vec3(x + blockSize, y - blockSize,
                                     z + blockSize);  // Bottom right
          vData.textureCoordinate = glm::vec2(1.0f, 0.0f);
          mesh->AddVertexData(vData);

          vData.position = glm::vec3(x - blockSize, y - blockSize,
                                     z + blockSize);  // Bottom left
          vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
          mesh->AddVertexData(vData);

          vData.position = glm::vec3(x + blockSize, y + blockSize,
                                     z + blockSize);  // Top right
          vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
          mesh->AddVertexData(vData);

          vData.position = glm::vec3(x - blockSize, y - blockSize,
                                     z + blockSize);  // Bottom right
          vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
          mesh->AddVertexData(vData);

          vData.position = glm::vec3(x - blockSize, y + blockSize,
                                     z + blockSize);  // Top left
          vData.textureCoordinate = glm::vec2(0.0f, 1.0f);
          mesh->AddVertexData(vData);
        }
        {  // Up Face (y = 0.5)
          vData.position = glm::vec3(x + blockSize, y + blockSize,
                                     z + blockSize);  // Top right
          vData.textureCoordinate = glm::vec2(1.0f, 0.0f);
          mesh->AddVertexData(vData);

          vData.position = glm::vec3(x + blockSize, y + blockSize,
                                     z - blockSize);  // Bottom right
          vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
          mesh->AddVertexData(vData);

          vData.position = glm::vec3(x - blockSize, y + blockSize,
                                     z + blockSize);  // Bottom left
          vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
          mesh->AddVertexData(vData);

          vData.position = glm::vec3(x + blockSize, y + blockSize,
                                     z - blockSize);  // Top right
          vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
          mesh->AddVertexData(vData);

          vData.position = glm::vec3(x - blockSize, y + blockSize,
                                     z + blockSize);  // Bottom right
          vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
          mesh->AddVertexData(vData);

          vData.position = glm::vec3(x - blockSize, y + blockSize,
                                     z - blockSize);  // Top left
          vData.textureCoordinate = glm::vec2(0.0f, 1.0f);
          mesh->AddVertexData(vData);
        }
      }
    }
  }
}

void ProceduralMesh::GenerateCubeMesh(std::shared_ptr<Mesh> &mesh) {
  VertexData vData;
  // Front face (z = 0.5)
  {
    vData.position = glm::vec3(0.5f, 0.5f, 0.5f);  // Top right
    vData.textureCoordinate = glm::vec2(1.0f, 1.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(0);

    vData.position = glm::vec3(0.5f, -0.5f, 0.5f);  // Bottom right
    vData.textureCoordinate = glm::vec2(1.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(1);

    vData.position = glm::vec3(-0.5f, -0.5f, 0.5f);  // Bottom left
    vData.textureCoordinate = glm::vec2(0.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(2);

    mesh->AddIndex(0);
    mesh->AddIndex(2);

    vData.position = glm::vec3(-0.5f, 0.5f, 0.5f);  // Top left
    vData.textureCoordinate = glm::vec2(0.0f, 1.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(3);
  }

  // Right face (x = 0.5)
  {
    vData.position = Vec3(0.5f, -0.5f, 0.5f);
    vData.textureCoordinate = Vec2(0.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(4);

    vData.position = Vec3(0.5f, 0.5f, 0.5f);
    vData.textureCoordinate = Vec2(0.0f, 1.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(5);

    vData.position = Vec3(0.5f, -0.5f, -0.5f);
    vData.textureCoordinate = Vec2(1.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(6);

    vData.position = Vec3(0.5f, 0.5f, -0.5f);
    vData.textureCoordinate = Vec2(1.0f, 1.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(7);

    mesh->AddIndex(6);
    mesh->AddIndex(5);
  }

  // Left face (x = -0.5)
  {
    vData.position = Vec3(-0.5f, -0.5f, 0.5f);
    vData.textureCoordinate = Vec2(1.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(8);

    vData.position = Vec3(-0.5f, 0.5f, 0.5f);
    vData.textureCoordinate = Vec2(1.0f, 1.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(9);

    vData.position = Vec3(-0.5f, -0.5f, -0.5f);
    vData.textureCoordinate = Vec2(0.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(10);

    vData.position = Vec3(-0.5f, 0.5f, -0.5f);
    vData.textureCoordinate = Vec2(0.0f, 1.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(11);

    mesh->AddIndex(10);
    mesh->AddIndex(9);
  }

  // Back face (z = -0.5)
  {
    vData.position = Vec3(0.5f, -0.5f, -0.5f);
    vData.textureCoordinate = Vec2(0.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(12);

    vData.position = Vec3(0.5f, 0.5f, -0.5f);
    vData.textureCoordinate = Vec2(0.0f, 1.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(13);

    vData.position = Vec3(-0.5f, -0.5f, -0.5f);
    vData.textureCoordinate = Vec2(1.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(14);

    vData.position = Vec3(-0.5f, 0.5f, -0.5f);
    vData.textureCoordinate = Vec2(1.0f, 1.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(15);

    mesh->AddIndex(14);
    mesh->AddIndex(13);
  }

  // Up face (y = 0.5)
  {
    vData.position = Vec3(0.5f, 0.5f, 0.5f);
    vData.textureCoordinate = Vec2(1.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(16);

    vData.position = Vec3(0.5f, 0.5f, -0.5f);
    vData.textureCoordinate = Vec2(1.0f, 1.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(17);

    vData.position = Vec3(-0.5f, 0.5f, 0.5f);
    vData.textureCoordinate = Vec2(0.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(18);

    vData.position = Vec3(-0.5f, 0.5f, -0.5f);
    vData.textureCoordinate = Vec2(0.0f, 1.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(19);

    mesh->AddIndex(18);
    mesh->AddIndex(17);
  }

  // Down face (y = -0.5)
  {
    vData.position = Vec3(0.5f, -0.5f, 0.5f);
    vData.textureCoordinate = Vec2(1.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(20);

    vData.position = Vec3(0.5f, -0.5f, -0.5f);
    vData.textureCoordinate = Vec2(1.0f, 1.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(21);

    vData.position = Vec3(-0.5f, -0.5f, 0.5f);
    vData.textureCoordinate = Vec2(0.0f, 0.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(22);

    vData.position = Vec3(-0.5f, -0.5f, -0.5f);
    vData.textureCoordinate = Vec2(0.0f, 1.0f);
    mesh->AddVertexData(vData);
    mesh->AddIndex(23);

    mesh->AddIndex(22);
    mesh->AddIndex(21);
  }
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
