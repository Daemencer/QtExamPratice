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

	_InitMatrices();

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
	GLuint worldMatrixPos = glGetUniformLocation(program, "worldMatrix");
	GLuint viewMatrixPos = glGetUniformLocation(program, "viewMatrix");
	GLuint projectMatrixPos = glGetUniformLocation(program, "projectMatrix");

	glUniformMatrix4fv(worldMatrixPos, 1, GL_FALSE, &m_worldMatrix[0][0]);
	glUniformMatrix4fv(viewMatrixPos, 1, GL_FALSE, &m_viewMatrix[0][0]);
	glUniformMatrix4fv(projectMatrixPos, 1, GL_FALSE, &m_projectMatrix[0][0]);

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


auto	CustomOpenGLWidget::TranslateXPos() -> void
{
	double value = 2.f;

	m_worldMatrix = glm::translate(m_worldMatrix, glm::vec3(value, 0.f, 0.f));
}


auto	CustomOpenGLWidget::_InitMatrices() -> void
{
	m_objectTranslate	= glm::mat4(1.f);
	m_objectRotate		= glm::mat4(1.f);
	m_objectScale		= glm::mat4(1.f);

	m_worldMatrix	= glm::mat4(1.f);
	m_viewMatrix	= glm::lookAt(glm::vec3(0.f, 1.f, 0.f), glm::vec3(0.f, -1.f, 0.f), glm::vec3(0.f, 0.f, 1.f));
	m_projectMatrix	= glm::perspective(60.f, (float)4/3, 1.f, 1000.f);
}