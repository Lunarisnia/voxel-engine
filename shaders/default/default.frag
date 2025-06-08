#version 330 core
out vec4 FragColor;

in vec2 texCoord;
in vec3 testColor;
in vec3 faceNormal;

uniform sampler2D tex;

void main() {
    vec4 image = texture(tex, texCoord);
    FragColor = vec4(faceNormal, 1.0f);
}
