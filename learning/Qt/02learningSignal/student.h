#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:


public slots:
    void treat();

    void treat(QString foodName);
};
// 早期版本 必须写到 publc slot, 高级版本可以写到public或者全局下
// 返回值是void，需要声明，也需要实现
// 可以有参数，也可以重载
#endif // STUDENT_H
