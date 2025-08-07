#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //点击新建按钮 弹出一个对话框
    connect(ui->actionNew, &QAction::triggered, [=](){
        //对话框 分类
        //模态对话框（可以对其他窗口进行操作）非模态对话框 （可以对其他窗口进行操作）

        //模态创建
        //QDialog dlg(this);
        //dlg.resize(200, 100);
        //dlg.exec();
        //qDebug() << "模态对话框弹出了";
        //非模态
        //QDialog *dlg = new QDialog(this);
        //dlg->show();
        //dlg->resize(200, 100);
        //dlg->setAttribute(Qt::WA_DeleteOnClose);//55号属性
        //qDebug() << "非模态对话框弹出了";

        //消息对话框


        //错误对话框
        //QMessageBox::critical(this, "critical", "错误");

        //信息对话框
        //QMessageBox::information(this, "info", "信息");

        //问题对话框
        //参数值 父亲 标题 内容 按键类型 默认关联回车按键
        //if(QMessageBox::Save == QMessageBox::question(this, "ques", "提问", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel)){
        //   qDebug() << "点击了Save";
        //}else{
        //    qDebug() << "点击了Cancel";
        //}

        //警告对话框
        //QMessageBox::warning(this, "warning", "警告");

        //其他标准对话框
        //颜色对话框
        //QColor color = QColorDialog::getColor(QColor(255, 0, 0));
        //qDebug() << "r:" << color.red() <<  " g:" << color.green() << " b:" << color.blue();

        //文件对话框
        //参数 父亲 标题 默认打开的路径 过滤文件格式
        //返回值是选择的路径
        //QString str = QFileDialog::getOpenFileName(this, "打开文件", "D:\\Software\\IDE\\Qt\\Docs\\Qt-6.4.0\\activeqt", "(*.txt)");
        //qDebug() << str;

        //
        bool flag;
        QFont font = QFontDialog::getFont(&flag, QFont("仿宋", 36));
        qDebug() << "字体:" << font.family().toUtf8().data() << "大小:" << font.pointSize() << "加粗:" << font.bold() << "倾斜:" << font.italic();

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

