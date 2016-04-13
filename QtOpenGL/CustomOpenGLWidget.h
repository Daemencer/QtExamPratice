#pragma once

#include "glew.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/quaternion.hpp>
#include <gtc/type_ptr.hpp>

#include <QOpenGLWidget>
#include <QTimer>

class ShaderManager;
class CubeModel;

class CustomOpenGLWidget
	: public QOpenGLWidget
{
	Q_OBJECT
public:
	explicit CustomOpenGLWidget(QWidget* parent = nullptr, Qt::WindowFlags flag = 0);
	~CustomOpenGLWidget();

	struct Color
	{
		Color() = delete;
		Color(GLclampf _red, GLclampf _green, GLclampf _blue, GLclampf _alpha)
		{
			red = _red;
			green = _green;
			blue = _blue;
			alpha = _alpha;
		}

		GLclampf red;
		GLclampf green;
		GLclampf blue;
		GLclampf alpha;
	};

	inline auto	SetClearColor(Color color) -> void { m_color = color; }

protected:
	auto	initializeGL() -> void override;
	auto	paintGL() -> void override;
	auto	resizeGL(int w, int h) -> void override;

private:
	auto	_InitMatrices() -> void;

	Color m_color = { 0.25f, 0.25f, 0.25f, 1.f };
	QTimer m_timer;

	glm::mat4		m_objectTranslate;
	glm::mat4		m_objectRotate;
	glm::mat4		m_objectScale;

	glm::mat4		m_worldMatrix; // might be useless
	glm::mat4		m_viewMatrix;
	glm::mat4		m_projectMatrix;

	ShaderManager*		m_shaderMgr = nullptr;
	CubeModel*			m_cube		= nullptr;

public slots:
	void	TranslateXPos();

};

