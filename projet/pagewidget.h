#ifndef PAGEWINDOW_H
#define PAGEWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QVector>
#include <QScrollArea>
#include <QDate>

#include "page.h"
#include "mainwindow.h"

class PageWidget : public QScrollArea
{
    Q_OBJECT

public:
    PageWidget();
    PageWidget(Page page, MainWindow *_controller, bool hasSuc, bool hasPred);
    Page toPage();

public slots:
    void addText();
    void addText(QString keyword, QString content);

private:

    QWidget * container = new QWidget();
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    QTextEdit* summary;
    QDate date;
    
    QVector<QTextEdit *> keywords;
    QVector<QTextEdit *> notes;

    MainWindow *controller;
    
};

#endif //MAINWINDOW_H
