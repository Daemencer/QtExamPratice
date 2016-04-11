#include "RenderWindow.h"



RenderWindow::RenderWindow(QWidget* parent, Qt::WindowFlags flag)
	: QMainWindow(parent, flag)
{
	setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose, true);
}


RenderWindow::~RenderWindow()
{
}

