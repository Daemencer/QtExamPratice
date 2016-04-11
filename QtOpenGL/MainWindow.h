#pragma once

#include "ui_MainWindow.h"

class MainWindow :
	public QMainWindow, public Ui_MainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = nullptr, Qt::WindowFlags flag = 0);
	~MainWindow();

public slots:
	void CreateRenderWindow();

private:
};

