#ifndef __SHADER_MANAGER_HPP__
#define __SHADER_MANAGER_HPP__

#include <map>
#include <string>
#include "glew.h"

#include "GLShader.hpp"


class ShaderManager final
{
public:
	ShaderManager()
	{
		_shaderPath = "shaders/";
	}
	~ShaderManager() = default;

	auto	AddNewProgram(const std::string& name, const std::string& vertexShaderPath, const std::string& fragmentShaderPath) -> void;

	auto	GetProgram(const std::string& progName) const->GLuint;

private:
	std::map<std::string, GLShader>		_programs;

	std::string		_shaderPath;

};


#endif /* __SHADER_MANAGER_HPP__ */