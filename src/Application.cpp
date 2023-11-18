#include "Application.h"
#include <QtCore/QtCore>

const int MIN_WIDTH = 800;
const int MAX_WIDTH = 1600;
const int MIN_HEIGHT = 600;
const int MAX_HEIGHT = 1200;
const int MOUSE_LISTEN_PRAG= 10;
const QString TITLE = QString("Cat Minecraft Lanucher");

Application::Application() : QWidget() {
	mx = my = mw = mh = -1;
	this->setObjectName("Application");
	this->setupUI();
}

Application::~Application() {

}

void Application::setupUI() {
	this->setWindowTitle(TITLE);
	this->setMinimumSize(QSize(MIN_WIDTH,MIN_HEIGHT));
	this->setMaximumSize(QSize(MAX_WIDTH,MAX_HEIGHT));
	this->setWindowFlag(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->setStyleSheet("background-color: rgba(20,20,20, 255);border-radius: 5px;");

	// 标题栏
	this->titlebar = new TitleBar(this,TITLE);
}

void Application::paintEvent(QPaintEvent* event){
	QStyleOption* opt = new QStyleOption();
	opt->init(this);
	QPainter* painter = new QPainter(this);
	this->style()->drawPrimitive(QStyle::PE_Widget, opt, painter, this);
}

void Application::mousePressEvent(QMouseEvent* event){
	if (event->button() == Qt::LeftButton){
		this->mx = event->pos().x();
		this->my = event->pos().y();
		this->mw = this->width();
		this->mh = this->height();
	}
}
void Application::mouseMoveEvent(QMouseEvent* event){
	if (event->pos().x() < MOUSE_LISTEN_PRAG || event->pos().y() < MOUSE_LISTEN_PRAG || event->pos().x() > this->width()-MOUSE_LISTEN_PRAG || event->pos().y() > this->height()-MOUSE_LISTEN_PRAG) {
		if (event->pos().x() < MOUSE_LISTEN_PRAG){
			this->setCursor(QCursor(Qt::SizeHorCursor));
			if (this->mx != -1) this->setGeometry(this->x()+event->pos().x()-this->mx,this->y(),this->width()-event->pos().x()+this->mx,this->height());
		}
		if (event->pos().y() < MOUSE_LISTEN_PRAG){
			if (event->pos().x() < MOUSE_LISTEN_PRAG) this->setCursor(QCursor(Qt::SizeFDiagCursor));
			else if (event->pos().x() > this->width()-MOUSE_LISTEN_PRAG) this->setCursor(QCursor(Qt::SizeBDiagCursor));
			else this->setCursor(QCursor(Qt::SizeVerCursor));
			if (this->mx != -1) this->setGeometry(this->x(),this->y()+event->pos().y()-this->my,this->width(),this->height()-event->pos().y()+this->my);
		}
		if (event->pos().x() > this->width()-MOUSE_LISTEN_PRAG){
			if(event->pos().y() >= MOUSE_LISTEN_PRAG) this->setCursor(QCursor(Qt::SizeHorCursor));
			if (this->mx != -1) this->setGeometry(this->x(),this->y(),this->mw+event->pos().x()-this->mx,this->height());
		}
		if (event->pos().y() > this->height()-MOUSE_LISTEN_PRAG){
			if (event->pos().x() > this->width()-MOUSE_LISTEN_PRAG) this->setCursor(QCursor(Qt::SizeFDiagCursor));
			else if (event->pos().x() < MOUSE_LISTEN_PRAG) this->setCursor(QCursor(Qt::SizeBDiagCursor));
			else this->setCursor(QCursor(Qt::SizeVerCursor));
			if (this->mx != -1) this->setGeometry(this->x(),this->y(),this->width(),this->mh+event->pos().y()-this->my);
		}
	}
	else if (this->mx != -1 && event->pos().y() < this->titlebar->height()-10) {
		this->setCursor(QCursor(Qt::ArrowCursor));
		this->setGeometry(this->x()+event->pos().x()-this->mx,this->y()+event->pos().y()-this->my,this->width(),this->height());
	}
	else this->setCursor(QCursor(Qt::ArrowCursor));
}
	
void Application::mouseReleaseEvent(QMouseEvent* event){
	if (event->button() == Qt::LeftButton){
		this->mx = -1;
		this->my = -1;
	}
}