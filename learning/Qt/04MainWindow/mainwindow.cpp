#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    //设置标题
    setWindowTitle("学习Window01");
    //重置窗口大小
    setFixedSize(900, 600);
    //创建菜单栏
    QMenuBar *bar = menuBar();
    //放入到窗口中
    setMenuBar(bar);

    //创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");
    //QMenu *fileMenu = bar->addMenu("文件");
    //QMenu *editMenu = bar->addMenu("文件");

    //创建菜单项
    QAction *newAction = fileMenu->addAction("新建");
    //创建分隔线
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("打开");

    //qDebug() << "aaa";
    //工具栏可以有多个
    QToolBar *toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolBar);
    //后期设置 只允许 左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //设置浮动
    toolBar->setFloatable(false);
    //设置移动（总开关）
    toolBar->setMovable(false);
    //在工具栏中设置内容
    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    //工具栏中添加一些小控件
    QPushButton *btn = new QPushButton("aa", this);
    toolBar->addWidget(btn);


    //状态栏 最多只有一个
    QStatusBar *stBar = statusBar();
    //设置到窗口
    setStatusBar(stBar);
    //放标签控件
    QLabel *label1 = new QLabel("右侧提示信息", this);
    //放到状态栏
    stBar->addWidget(label1);
    QLabel *label2 = new QLabel("右侧提示信息", this);
    stBar->addPermanentWidget(label2);

    //铆接部件（浮动窗口）
    QDockWidget *dockWidget = new QDockWidget("浮动", this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
    //设置后期停靠区域 只允许上下
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    //设置中心部件 只能有一个
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{
}

