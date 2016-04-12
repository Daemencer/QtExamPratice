#include <QApplication>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32.lib")

#include "RenderWindow.h"

auto	main(int argc, char* argv[]) -> int
{
	qsrand(qrand());

	QApplication app(argc, argv);
	RenderWindow* window = new RenderWindow();
	window->show();

	return app.exec();
}