#version 330 core
in vec3 aPos;
in vec3 aColor;
out vec3 vertexColor;
uniform vec3 vertexOffset;
void main()
{
	gl_Position = vec4(aPos + vertexOffset,1.0);
	vertexColor = aColor;
};