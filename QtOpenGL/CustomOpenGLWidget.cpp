#include "CustomOpenGLWidget.h"

#include <iostream>
#include <QWidget>

CustomOpenGLWidget::CustomOpenGLWidget(QWidget* parent, Qt::WindowFlags flag)
	: QOpenGLWidget(parent, flag)
{
}


CustomOpenGLWidget::~CustomOpenGLWidget()
{
}

auto CustomOpenGLWidget::initializeGL() -> void
{
	glClearColor(m_color.red, m_color.green, m_color.blue, m_color.alpha);

	connect(&m_timer, SIGNAL(timeout()), this, SLOT(update()));
	m_timer.start(16);
}

auto CustomOpenGLWidget::paintGL() -> void
{
	glClearColor(m_color.red, m_color.green, m_color.blue, m_color.alpha);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
