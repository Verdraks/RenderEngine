#version 330 core
in vec3 vertexColor;
in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D baseColorTex;

void main()
{
   FragColor = texture(baseColorTex, texCoord) * vec4(vertexColor,1.0);
};