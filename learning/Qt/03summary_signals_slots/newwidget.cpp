#include "newwidget.h"

NewWidget::NewWidget(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("新窗口");
    resize(300, 200);
}
