#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(decriment()));
    timer.start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::decriment()
{
    a = rand() % (this->width() - 50);
    b = rand() % (this->height() - 50);
    repaint();
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    int x = e->x();
    int y = e->y();
    int k1 = a + 25 - x;
    int k2 = b + 25 - y;
    if (25 * 25 >= k1 * k1 + k2 * k2)
    {
        p++;
    } else {
        p--;
    }

    ui->lcdNumber->display(p);
}
void Widget::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);
    painter.drawEllipse(a, b, 50, 50);
}
