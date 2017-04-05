#ifndef PAGEWINDOW_H
#define PAGEWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "page.h"

class PageWidget : public QWidget
{
    Q_OBJECT

public:
    PageWidget();
    PageWidget(Page &page);

public slots:
    void addText();
    void addText(QString keyword, QString content);

private:

    QHBoxLayout* hLayout = new QHBoxLayout();
    QWidget * container = new QWidget();
    QVBoxLayout* vLayout = new QVBoxLayout(this);
};

#endif //MAINWINDOW_H
