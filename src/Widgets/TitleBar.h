#ifndef TITLE_BAR_H
#define TITLE_BAR_H

#include "DailogButton.h"
#include <QtWidgets/QtWidgets>

class TitleBar : public QFrame {
	Q_OBJECT;
private:
	QLabel* titlelabel;
	DailogButton* minsizeButton;
	DailogButton* closeButton;
	QTimer* updateTimer;
public:
	TitleBar(QWidget* parent,QString title);
	~TitleBar();
private slots:
	void onPressMinsizeButton();
	void onPressCloseButton();
	void myUpdate();
};

#endif