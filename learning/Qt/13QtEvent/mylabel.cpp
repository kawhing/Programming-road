#include "mylabel.h"

myLabel::myLabel(QWidget *parent): QLabel{parent}
{
    //设置鼠标追踪状态
    setMouseTracking(true);
}
//鼠标进入事件
void myLabel::enterEvent(QEnterEvent *event){
    qDebug() << "鼠标进入了";
    QLabel::enterEvent(event);
}
//鼠标离开事件
void myLabel::leaveEvent(QEvent *event){
    qDebug() << "鼠标离开了";
    QLabel::leaveEvent(event);
}
//鼠标移动事件
void myLabel::mouseMoveEvent(QMouseEvent *ev){
    QString str = QString("鼠标移动了x = %1 y = %2 globalX = %3 globalY = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    qDebug() << str;
}
//鼠标按下事件
void myLabel::mousePressEvent(QMouseEvent *ev){
    //qDebug() << "鼠标按下了";
    if(ev->button() == Qt::LeftButton){
        QString str = QString("鼠标按下了x = %1 y = %2 globalX = %3 globalY = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}
//鼠标释放事件
void myLabel::mouseReleaseEvent(QMouseEvent *ev){
    if(ev->button() == Qt::LeftButton){
        QString str = QString("释放了x = %1 y = %2 globalX = %3 globalY = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}
bool myLabel::event(QEvent *e){
    if(e->type() == QEvent::MouseButtonPress){
        QMouseEvent *ev = static_cast<QMouseEvent *>(e);
        QString str = QString("Event函数中::鼠标按下了x = %1 y = %2 globalX = %3 globalY = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;

        return true;//true 代表用户自己处理这个事件， 不向下分发
    }
    return QLabel::event(e);
}
