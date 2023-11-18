#ifndef APPLICATION_H
#define APPLICATION_H

#include "Widgets/TitleBar.h"
#include <QtWidgets/QtWidgets>

class Application : public QWidget {
	Q_OBJECT;
private:
	int mx,my,mw,mh;
	TitleBar* titlebar;
	void paintEvent(QPaintEvent* event);
	void setupUI();
public:
	Application();
	~Application();
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
};

#endif