#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    int a = 0;
    int b = 0;
    int p = 0;

private:
    Ui::Widget *ui;
    QTimer timer;
protected slots:
    void decriment();
protected:
    void mousePressEvent(QMouseEvent * e);
    void paintEvent(QPaintEvent * e);
};

#endif // WIDGET_H
