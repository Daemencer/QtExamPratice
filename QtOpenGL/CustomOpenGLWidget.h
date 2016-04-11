#pragma once

#include <QOpenGLWidget>
#include <QTimer>

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
	Color m_color = { 0.25f, 0.25f, 0.25f, 1.f };
	QTimer m_timer;

public slots:
	void ApplyRandomRed();
	void ApplyRandomGreen();
	void ApplyRandomBlue();
	void ApplyDefaultColor();

};

