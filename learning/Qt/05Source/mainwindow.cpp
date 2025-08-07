#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->actionNew->setIcon(QIcon("D:\\Kawhing\\Pictures\\头像.png"));

    //使用添加Qt资源 ": + 前缀名 + 文件名"
    ui->actionNew->setIcon(QIcon(":/Image/1.png"));
    ui->actionOpen->setIcon(QIcon(":/Image/wechat.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

