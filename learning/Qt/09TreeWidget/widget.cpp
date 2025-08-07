#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //treeWidget树控件
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄介绍");

    QTreeWidgetItem *powerItem = new QTreeWidgetItem(QStringList() << "力量");
    QTreeWidgetItem *agileItem = new QTreeWidgetItem(QStringList() << "敏捷");
    QTreeWidgetItem *IQItem = new QTreeWidgetItem(QStringList() << "智力");
    //加载顶层的节点
    ui->treeWidget->addTopLevelItem(powerItem);
    ui->treeWidget->addTopLevelItem(agileItem);
    ui->treeWidget->addTopLevelItem(IQItem);
    //追加子节点
    QStringList heroPower1, heroPower2, agileItem1, agileItem2, IQItem1, IQItem2;
    heroPower1 << "刚被猪" << "前排坦克，能在吸收伤害的同时造成可观的范围输出";
    heroPower2 << "船长" << "前排坦克，能肉能输能控场的全能英雄";
    QTreeWidgetItem *h1 = new QTreeWidgetItem(heroPower1);
    QTreeWidgetItem *h2 = new QTreeWidgetItem(heroPower2);
    powerItem->addChild(h1);
    powerItem->addChild(h2);

    agileItem1 << "月骑”" << "中排物理输出，可以使用分裂和利刃攻击多个目标";
    agileItem2<< "小鱼人" << "前排战士，擅长偷取敌人的属性来增强自身战力";
    QTreeWidgetItem *a1 = new QTreeWidgetItem(agileItem1);
    QTreeWidgetItem *a2 = new QTreeWidgetItem(agileItem2);
    agileItem->addChild(a1);
    agileItem->addChild(a2);

    IQItem1 << "死灵法师" << "前排法师坦克，魔法抗性较高，拥有治疗技能";
    IQItem2 << "巫医" << "后排辅助法师，可以使用奇特的巫术诅咒敌人与治疗队友";
    QTreeWidgetItem *IQ1 = new QTreeWidgetItem(IQItem1);
    QTreeWidgetItem *IQ2 = new QTreeWidgetItem(IQItem2);
    IQItem->addChild(IQ1);
    IQItem->addChild(IQ2);

    //QTreeWidgetItem *power1Item = new QTreeWidgetItem(QStringList() << "力量");
}

Widget::~Widget()
{
    delete ui;
}

