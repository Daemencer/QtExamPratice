#include "MainWindow.h"

#include "RenderWindow.h"

MainWindow::MainWindow(QWidget* parent, Qt::WindowFlags flag)
	: QMainWindow(parent, flag)
{
	setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose, true);
}


MainWindow::~MainWindow()
{
}

void	MainWindow::CreateRenderWindow()
{
	RenderWindow* renderWindow = new RenderWindow();
	renderWindow->show();
}
