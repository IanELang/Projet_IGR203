#include "day.h"
#include <QPainter>

Day::Day(QWidget *parent) :
    QWidget(parent)
{
    vLayout = new QVBoxLayout();
    this->setLayout(vLayout);

   // this->setGeometry(0, 0, 80, 60);
    QPalette pal = palette();

    // set white background
    pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->show();
}
