#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

// Teacher类 老师类
// Student类 学生类
// 下课后，老师会触发一个信号，饿了，学生相应信号，请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 创建一个老师对象
    this->zt = new Teacher;
    // 创建一个学生对象
    this->st = new Student;

//    //老师饿了，学生请客
//     connect(zt, &Teacher::hungry, st, &Student::treat);
//     classIsOver();



    void(Teacher:: *teacherSignal) (QString) = &Teacher::hungry;
    void(Student:: *studentSlots) (QString) = &Student::treat;
    connect(zt, teacherSignal, st, studentSlots);

    // 信号连接信号
//    void(Teacher:: *teacherSignal) (void) = &Teacher::hungry;
//    void(Student:: *studentSlots) (void) = &Student::treat;
//    connect(zt, teacherSignal, st, studentSlots);

    QPushButton *btn = new QPushButton("下课", this);
    connect(btn, &QPushButton::clicked, this, &Widget::classIsOver);
    //connect(btn, &QPushButton::clicked, zt, teacherSignal);

    //拓展
    //信号可以连接信号
    //一个信号可以连接多个槽函数
    //多个信号可以连接同一个槽函数
    //信号和槽函数的参数 必须以一对应
    //信号和槽函数的参数个数 是不是要一致？ 信号参数个数 可以多于槽函数的参数个数

    //Qt版本以前信号和槽连接方式
    //connct(zt, SIGNAL(hungry), st, SLOTS(treat(QString)))
    //Qt4 版本优点：参数直观，缺点：类型不做检测
    //Qt5以上支持Qt4版本的写法，反之不支持
    //Qt4要想使用Lambda表达式需要额外加上C++11
    //[=](){
    //  btn->setText("aaa");
    //}();

//    QPushButton *myBtn = new QPushButton(this);
//    QPushButton *myBtn2 = new QPushButton(this);
//    myBtn2->move(100, 100);
//    int m = 10;
//    // mutable关键字 用于修改值传递的变量 修改的是拷贝 而不是本体
//    connect(myBtn, &QPushButton::clicked, this, [m] ()mutable {m = 100 + 10; qDebug() << m; });
//    connect(myBtn2, &QPushButton::clicked, this, [=] () {qDebug() << m;});
//    int ret = []()->int {return 1000;}();
//    qDebug() << "ret = " << ret;

    // 利用lambda表达式实现点击按钮 关闭窗口
    QPushButton *btn1 = new QPushButton("关闭窗口", this);
    btn1->move(100, 0);
    connect(btn1, &QPushButton::clicked, this, [=](){
        //this->close();
        //emit zt->hungry("宫保鸡丁");
        btn1->setText("aaa");
    });
}

void Widget::classIsOver(){
    // 下课函数，调用后，触发老师饿了的信号
    // emit zt->hungry();
    emit zt->hungry("宫保鸡丁");
}

Widget::~Widget()
{
    delete ui;
}


