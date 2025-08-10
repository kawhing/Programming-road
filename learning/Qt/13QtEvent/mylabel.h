#ifndef MYLABEL_H
#define MYLABEL_H

#include <QDebug>
#include <QLabel>
#include <QEnterEvent>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *ev);
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    //通过event事件分发器 拦截鼠标按下事件
    bool event(QEvent *e);

signals:

};

#endif // MYLABEL_H
