#ifndef DAILOG_BUTTON_H
#define DAILOG_BUTTON_H

#include <QtWidgets/QtWidgets>

class DailogButton : public QLabel {
	Q_OBJECT;
private:
	int a;
signals:
	void clicked();
public:
	DailogButton(QWidget* parent,QString text);
	~DailogButton();
	void mouseReleaseEvent(QMouseEvent* event);
};

#endif