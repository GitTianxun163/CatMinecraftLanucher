#include "TitleBar.h"
#define ParentWidget ((QWidget*)this->parent())

const int barheight=40;
const int title_margin=5;

TitleBar::TitleBar(QWidget* parent,QString title) : QFrame(parent) {
	this->setGeometry(0,0,800,barheight);
	this->setStyleSheet("background:rgba(40, 40, 40,100)");

	// 标题
	this->titlelabel = new QLabel(title,this);
	this->titlelabel->setGeometry(title_margin,title_margin,800,barheight);
	this->titlelabel->setStyleSheet("color:rgb(120,120,120);background:rgba(0,0,0,0)");
	this->titlelabel->setAlignment(Qt::AlignTop);
	QFont font;
	font.setFamily("Microsoft YaHei");
	font.setBold(true);
	font.setPixelSize(barheight-title_margin*4);
	this->titlelabel->setFont(font);
	this->setFont(font);

	// 最小化按钮
	this->minsizeButton = new DailogButton(this,"-");
	this->minsizeButton->setGeometry(this->width()-80,title_margin,barheight-title_margin*2,barheight-title_margin*2);
	connect(this->minsizeButton,SIGNAL(clicked()),this,SLOT(onPressMinsizeButton()));

	// 关闭按钮
	this->closeButton = new DailogButton(this,QString::fromUtf8("×"));
	this->closeButton->setGeometry(this->width()-40,title_margin,barheight-title_margin*2,barheight-title_margin*2);
	this->closeButton->setStyleSheet(
		"QLabel {color:rgb(255,255,255);background:rgba(200,200,200,0);border-radius: 15px;transition: background 0.5s;}"
		"QLabel:hover {background:rgba(255,0,0,255);border-radius: 15px;}"
	);
	connect(this->closeButton,SIGNAL(clicked()),this,SLOT(onPressCloseButton()));

	//  计时器
	this->updateTimer = new QTimer(this);
	connect(this->updateTimer,SIGNAL(timeout()),this,SLOT(myUpdate()));
	this->updateTimer->start(10);
}

TitleBar::~TitleBar() {

}

void TitleBar::onPressMinsizeButton() {
	ParentWidget->showMinimized();
}

void TitleBar::onPressCloseButton() {
	ParentWidget->close();
}

void TitleBar::myUpdate() {
	this->setGeometry(0,0,ParentWidget->width(),barheight);
	this->minsizeButton->setGeometry(this->width()-80,title_margin,barheight-title_margin*2,barheight-title_margin*2);
	this->closeButton->setGeometry(this->width()-40,title_margin,barheight-title_margin*2,barheight-title_margin*2);
}