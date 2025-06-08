#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;
layout(location = 2) in vec3 aNormal;

out vec2 texCoord;
out vec3 faceNormal;

uniform mat4 view;
uniform mat4 transform;
uniform mat4 projection;

void main() {
    texCoord = aTexCoord;
    faceNormal = aNormal;
    gl_Position = projection * view * transform * vec4(aPos, 1.0f);
}
