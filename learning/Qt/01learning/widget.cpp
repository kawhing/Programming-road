#include "widget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)

{
    setWindowTitle("你好世界!");
    setFixedSize(600, 400);
    QPushButton *btn1 = new QPushButton;

    btn1->setParent(this);


    btn1->setText("第一个按钮");
    QPushButton *btn2 = new QPushButton("第二个按钮", this);
    btn2->move(100, 100);
    btn2->resize(80, 20);

    //创建一个自己的按钮对象
    MyPushButton *btn3 = new MyPushButton;
    btn3->setText("我自己的按钮");
    btn3->move(200, 0);
    btn3->setParent(this);//添加到对象树




    // 需求：点击我的按钮 关闭窗口
    connect(btn3, &MyPushButton::clicked, this, &Widget::close);
}

Widget::~Widget()
{
    qDebug() << "Widget析构";
}

