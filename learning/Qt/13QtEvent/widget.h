#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //重写定时器事件
    void timerEvent(QTimerEvent *ev);
    int id1, id2, i3;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
