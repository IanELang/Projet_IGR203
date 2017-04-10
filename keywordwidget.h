#ifndef KEYWORDWIDGET_H
#define KEYWORDWIDGET_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "notebook.h"

class KeywordWidget : public QWidget
{

    Q_OBJECT
public:
    KeywordWidget(Notebook ntbks);




private:

    QHBoxLayout* hLayout = new QHBoxLayout();
    QWidget * container = new QWidget();
    QVBoxLayout* vLayout = new QVBoxLayout(this);
};

#endif // KEYWORDWIDGET_H

