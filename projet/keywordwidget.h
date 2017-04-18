#ifndef KEYWORDWIDGET_H
#define KEYWORDWIDGET_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>

#include "notebook.h"
#include "mainwindow.h"


class KeywordWidget : public QScrollArea
{

    Q_OBJECT
public:
    KeywordWidget(Notebook ntbks, int noteNum, MainWindow *_controller);

private:
    MainWindow *controller;


};

#endif // KEYWORDWIDGET_H

