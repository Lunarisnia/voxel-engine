#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;
layout(location = 2) in vec3 aTestColor;

out vec2 texCoord;
out vec3 testColor;

uniform mat4 view;
uniform mat4 transform;
uniform mat4 projection;

void main() {
    texCoord = aTexCoord;
    testColor = aTestColor;
    gl_Position = projection * view * transform * vec4(aPos, 1.0f);
}
