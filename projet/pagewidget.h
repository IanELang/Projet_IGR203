#ifndef PAGEWINDOW_H
#define PAGEWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>

class PageWidget : public QWidget
{
    Q_OBJECT

public:
    PageWidget();

public slots:
    void addText();

private:

    QHBoxLayout* hLayout = new QHBoxLayout();
    QWidget * container = new QWidget();
    QVBoxLayout* vLayout = new QVBoxLayout(this);
};

#endif //MAINWINDOW_H
