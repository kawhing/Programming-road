#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "newwidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    NewWidget *newWidget = new NewWidget;
    ~Widget();

private:

};
#endif // WIDGET_H
