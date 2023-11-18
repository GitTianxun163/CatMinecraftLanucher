#include "DailogButton.h"

const int normal_button=30;

DailogButton::DailogButton(QWidget* parent,QString text) : QLabel(text,parent) {
	this->setFixedSize(normal_button,normal_button);
	this->setStyleSheet(
		"QLabel {color:rgb(255,255,255);background:rgba(200,200,200,0);border-radius: 15px;}"
		"QLabel:hover {background:rgba(200,200,200,100);border-radius: 15px;}"
	);
	this->setAlignment(Qt::AlignCenter);
	// QFont font;
	// font.setFamily("Microsoft YaHei");
	// font.setBold(true);
	// font.setPixelSize(this->height());
	// this->setFont(font);
}

DailogButton::~DailogButton() {

}

void DailogButton::mouseReleaseEvent(QMouseEvent* event) {
	emit clicked();
}