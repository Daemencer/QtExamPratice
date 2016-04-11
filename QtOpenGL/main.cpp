#include <QApplication>

#include "MainWindow.h"
auto	main(int argc, char* argv[]) -> int
{
	qsrand(qrand());

	QApplication app(argc, argv);
	MainWindow* window = new MainWindow();
	window->show();

	return app.exec();
}