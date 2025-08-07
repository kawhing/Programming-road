#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置默认stackedArea
    ui->stackedWidget->setCurrentIndex(2);
    //栈控件的使用
    connect(ui->btnPage1, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btnPage2, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->btnPage3, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
//    ui->comboBox->addItem("奔驰");
//    ui->comboBox->addItem("宝马");
//    ui->comboBox->addItem("拖拉机");
//    connect(ui->btnBenz, &QPushButton::clicked, [=](){
//        ui->comboBox->setCurrentIndex(0);
//    });
//    connect(ui->btnHourse, &QPushButton::clicked, [=](){
//        ui->comboBox->setCurrentIndex(1);
//    });
//    connect(ui->btnTutor, &QPushButton::clicked, [=](){
//        //ui->comboBox->setCurrentIndex(2);
//        ui->comboBox->setCurrentText("拖拉机");
//    });
    //利用Lable显示图片
    ui->imageLabel->setPixmap(QPixmap(":/Image/1.gif"));
    //利用Lable显示gif
    QMovie *movie = new QMovie(":/Image/1.gif");
    ui->movieLabel->setMovie(movie);
    //播放
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}

