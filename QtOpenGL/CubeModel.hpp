#ifndef __CUBE_MODEL_HPP__
#define __CUBE_MODEL_HPP__

#include "Model.hpp"

class CubeModel :
	public Model
{
public:
	CubeModel() = default;
	virtual ~CubeModel() = default;

	auto	Initialize(GLuint program) -> void;

};

#endif /* __CUBE_MODEL_HPP__ */