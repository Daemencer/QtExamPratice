attribute vec4 posAttr;
attribute vec4 colAttr;

varying vec4 col;

uniform mat4 worldMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectMatrix;

void main()
{
    gl_Position = projectMatrix * viewMatrix * worldMatrix * posAttr;
	col = colAttr;
}