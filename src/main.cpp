#include "Application.h"
#include <QtWidgets/QApplication>

int main(int argc,char* argv[]) {
	QApplication app(argc,argv);
	Application mainwindow;
	mainwindow.show();
	return app.exec();
}
