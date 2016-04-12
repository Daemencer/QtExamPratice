#include "Model.hpp"

#include "glew.h"

#include "ShaderManager.hpp"

Model::~Model()
{
	Shutdown();
}


auto	Model::Initialize(GLuint program) -> void
{
	glUseProgram(program);

	auto positionLoc = glGetAttribLocation(program, "posAttr");
	auto colorLoc = glGetAttribLocation(program, "colAttr");

	glGenBuffers(1, &_VBOpos);
	glGenBuffers(1, &_VBOcolors);
	glGenBuffers(1, &_IBO);

	// data
	glBindBuffer(GL_ARRAY_BUFFER, _VBOpos);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _posisitionCount, _positions.data(), GL_STREAM_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, _VBOcolors);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * _colorCount, _colors.data(), GL_STATIC_DRAW);

	// indices
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort) * _indexCount, _indices.data(), GL_STATIC_DRAW);

	// reset binding
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// check if not already a vao from previous frames (precaution)
	if (glIsVertexArray(_vao) == GL_TRUE)
		glDeleteVertexArrays(1, &_vao);

	// generate and bind the VAO that is going to execute the commands
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	// bind all the buffers to explain opengl how to use their data

	// explain openGL how to use the data
	glBindBuffer(GL_ARRAY_BUFFER, _VBOpos);
	glVertexAttribPointer(positionLoc, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, _VBOcolors);
	glVertexAttribPointer(colorLoc, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);

	glEnableVertexAttribArray(positionLoc);
	glEnableVertexAttribArray(colorLoc);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _IBO);

	// reset the VAO binding
	glBindVertexArray(0);

	// unbind to be safe
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


auto	Model::Shutdown() -> void
{
	_positions.clear();
	_colors.clear();
	_indices.clear();

	glDeleteBuffers(1, &_VBOpos);
	glDeleteBuffers(1, &_VBOcolors);
	glDeleteBuffers(1, &_IBO);

	glDeleteVertexArrays(1, &_vao);
}


auto	Model::GetModelVAO() const -> GLuint
{
	return _vao;
}
