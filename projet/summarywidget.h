#ifndef SUMMARYWIDGET_H
#define SUMMARYWIDGET_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "notebook.h"
#include "mainwindow.h"

class SummaryWidget : public QWidget
{
    Q_OBJECT
public:

    SummaryWidget(Notebook ntbks, MainWindow *_controller);

private:
    MainWindow *controller;

};

#endif // SUMMARYWIDGET_H
