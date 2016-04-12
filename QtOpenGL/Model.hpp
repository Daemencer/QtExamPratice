#ifndef __MODEL_HPP__
#define __MODEL_HPP__

#include "glew.h"
#include <vector>

class Model
{
public:
	Model() = default;
	virtual ~Model();

	virtual	auto	Initialize(GLuint program) -> void; // do the actual things here and set the _vao to the proper value
	auto	Shutdown() -> void;

	auto	GetModelVAO() const->GLuint; // just return a value, computing is in Initialize so that it's done only once

	auto	GetModelIndexCount() const -> unsigned int { return _indexCount; }

protected:
	GLuint	_vao			= -1;

	GLuint	_VBOpos			= -1;
	GLuint	_VBOcolors	= -1;
	GLuint	_IBO			= -1;

	unsigned int				_posisitionCount	= 0u;
	std::vector<float>			_positions;

	unsigned int				_colorCount			= 0u;
	std::vector<float>			_colors;

	unsigned int				_indexCount			= 0u;
	std::vector<unsigned short>	_indices;

};

#endif /* __MODEL_HPP__ */