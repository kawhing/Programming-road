#include "widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent): QWidget(parent)
{
    setWindowTitle("测试练习");
    setFixedSize(600, 400);
    QPushButton *openNewWidget = new QPushButton("Open", this);
    openNewWidget->move(250, 150);
    connect(openNewWidget, &QPushButton::clicked, this, [=](){
        newWidget->show();
    });
    QPushButton *closeNewWidget = new QPushButton("Close", this);
    connect(closeNewWidget, &QPushButton::clicked, this, [=](){
        newWidget->close();
    });
    closeNewWidget->move(250, 250);
}

Widget::~Widget()
{

}

