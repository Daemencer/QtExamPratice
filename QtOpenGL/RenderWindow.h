#pragma once

#include "ui_RenderWindow.h"

class RenderWindow :
	public QMainWindow, public Ui_RenderWindow
{
	Q_OBJECT

public:
	explicit RenderWindow(QWidget* parent = nullptr, Qt::WindowFlags = 0);
	~RenderWindow();
};

