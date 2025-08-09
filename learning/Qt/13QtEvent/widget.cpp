#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //启动定时器
    id1 = startTimer(1000);//参数 间隔 单位 毫秒
    id2 = startTimer(2000);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::timerEvent(QTimerEvent *ev){
    if(ev->timerId() == id1){//label_2每隔一秒+1
        static int number1 = 1;
        ui->label_2->setText(QString::number(number1++));
    }else if(ev->timerId() == id2){//label_3每隔两秒+1
        static int number2 = 1;
        ui->label_3->setText(QString::number(number2++));
    }
}

