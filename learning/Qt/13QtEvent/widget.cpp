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
    //定时器的第二个方式
    QTimer *timer = new QTimer(this);
    timer->start(500);
    connect(timer, &QTimer::timeout, [=](){
        //label_4每隔一秒+1
        static int number1 = 1;
        ui->label_4->setText(QString::number(number1++));
    });
    //点击暂停,停止计时
    connect(ui->btnPause, &QPushButton::clicked, [=](){
        timer->stop();
    });
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

