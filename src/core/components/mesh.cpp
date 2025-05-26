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

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData) * vertices.size(),
               vertices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData),
                        (void *)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData),
                        (void *)sizeof(Vec3));
  glEnableVertexAttribArray(1);
}

GLuint Mesh::GetVAO() { return VAO; }

int Mesh::GetVerticeSize() { return vertices.size(); }

void Mesh::AddVertexData(VertexData vertexData) {
  vertices.push_back(vertexData);
}
