#include "voxelengine/components/mesh.hpp"
#include <memory>
#include "glm/ext/vector_float3.hpp"
#include "voxelengine/material/material.hpp"
#include "voxelengine/vertex_data.hpp"

using namespace VoxelEngine;

Mesh::Mesh() {}
Mesh::Mesh(std::shared_ptr<Material> material) : material(material) {}

void Mesh::setupMesh() {
  // TODO: Move this to its own utility function
  VertexData v = VertexData();
  v.position = glm::vec3(0.0f, 0.5f, 0.0f);
  vertices.push_back(v);
  v.position = glm::vec3(0.5f, -0.5f, 0.0f);
  vertices.push_back(v);
  v.position = glm::vec3(-0.5f, -0.5f, 0.0f);
  vertices.push_back(v);

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(VertexData) * vertices.size(),
               vertices.data(), GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData),
                        (void *)0);
  glEnableVertexAttribArray(0);
}

GLuint Mesh::getVAO() { return VAO; }

int Mesh::getVerticeSize() { return sizeof(VertexData) * vertices.size(); }
