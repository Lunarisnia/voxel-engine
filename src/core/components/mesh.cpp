#include "voxelengine/components/mesh.hpp"
#include <memory>
#include "voxelengine/material/material.hpp"
#include "voxelengine/math/vec3.hpp"
#include "voxelengine/vertex_data.hpp"

using namespace VoxelEngine;

Mesh::Mesh() {};
Mesh::Mesh(std::shared_ptr<Material> material) : material(material) {}

void Mesh::SetupMesh() {
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData) * vertices.size(),
               vertices.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indices.size(),
               indices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData),
                        (void *)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData),
                        (void *)sizeof(Vec3));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData),
                        (void *)(sizeof(Vec3) + sizeof(Vec2)));
  glEnableVertexAttribArray(2);
}

void Mesh::ClearVertice() { vertices.clear(); }

GLuint Mesh::GetVAO() { return VAO; }

int Mesh::GetVerticeSize() { return vertices.size(); }
int Mesh::GetIndiceSize() { return indices.size(); }

void Mesh::AddVertexData(VertexData vertexData) {
  vertices.emplace_back(vertexData);
}

void Mesh::AddIndex(int index) { indices.emplace_back(index); }
