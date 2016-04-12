#include "ShaderManager.hpp"

#include "GLShader.hpp"

auto	ShaderManager::AddNewProgram(const std::string& name, const std::string& vertexShaderPath, const std::string& fragmentShaderPath) -> void
{
	GLShader shader;

	std::string vertex = _shaderPath + vertexShaderPath;
	std::string fragment = _shaderPath + fragmentShaderPath;

	shader.LoadVertexShader(vertex.c_str());
	shader.LoadFragmentShader(fragment.c_str());
	shader.Create();

	_programs.emplace(name, shader);
}


auto	ShaderManager::GetProgram(const std::string& progName) const -> GLuint
{
	return _programs.at(progName).GetProgram();
}