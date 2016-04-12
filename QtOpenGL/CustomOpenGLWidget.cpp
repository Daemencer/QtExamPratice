#include "CustomOpenGLWidget.h"

#include <iostream>

#include <QWidget>

#include "ShaderManager.hpp"
#include "CubeModel.hpp"

CustomOpenGLWidget::CustomOpenGLWidget(QWidget* parent, Qt::WindowFlags flag)
	: QOpenGLWidget(parent, flag)
{
	m_shaderMgr = new ShaderManager();
	m_cube = new CubeModel();
}


CustomOpenGLWidget::~CustomOpenGLWidget()
{
}

auto CustomOpenGLWidget::initializeGL() -> void
{
	glewInit();

	// shaders //
	m_shaderMgr->AddNewProgram("basic", "basic.vs", "basic.fs");
	GLuint program = m_shaderMgr->GetProgram("basic");
	/////////////

	// VAO //
	// generate the VAO used to draw a quad in the current context
	m_cube->Initialize(program);
	/////////

	//glClearColor(m_color.red, m_color.green, m_color.blue, m_color.alpha);

	connect(&m_timer, SIGNAL(timeout()), this, SLOT(update()));
	m_timer.start(16);
}

auto CustomOpenGLWidget::paintGL() -> void
{
	GLuint program = m_shaderMgr->GetProgram("basic");
	glUseProgram(program);

	glClearColor(m_color.red, m_color.green, m_color.blue, m_color.alpha);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// matrix //
	float matrix[16] = {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	GLuint matrixPos = glGetUniformLocation(program, "matrix");
	glUniformMatrix4fv(matrixPos, 1, GL_FALSE, matrix);
	////////////

	GLuint vao = m_cube->GetModelVAO();

	glBindVertexArray(m_cube->GetModelVAO());
	glDrawElements(GL_TRIANGLES, m_cube->GetModelIndexCount(), GL_UNSIGNED_SHORT, 0);
	glBindVertexArray(0);
}

auto CustomOpenGLWidget::resizeGL(int w, int h) -> void
{
	glViewport(0, 0, w, h);
}

void CustomOpenGLWidget::ApplyRandomRed()
{
	m_color.red = static_cast <float> (qrand()) / static_cast <float> (RAND_MAX);
}

void CustomOpenGLWidget::ApplyRandomGreen()
{
	m_color.green = static_cast <float> (qrand()) / static_cast <float> (RAND_MAX);
}

void CustomOpenGLWidget::ApplyRandomBlue()
{
	m_color.blue = static_cast <float> (qrand()) / static_cast <float> (RAND_MAX);
}

void CustomOpenGLWidget::ApplyDefaultColor()
{
	m_color = { 0.25f, 0.25f, 0.25f, 1.f };
}
