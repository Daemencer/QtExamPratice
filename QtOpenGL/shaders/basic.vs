attribute vec4 posAttr;
attribute vec4 colAttr;

varying vec4 col;

uniform mat4 matrix;

void main()
{
	col = colAttr;
    gl_Position = matrix * posAttr;
}