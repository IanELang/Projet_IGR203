#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QWidget>

#include "notebook.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QVector<Notebook> notebooks;

    int curNotebook;
    int curPage;

    QWidget *content;

    void openPage(int ntbk, int pg);
    void closePage();
    void updateCalendar();

public slots:
    void newPage();
    void newPage(int numNotebook);
    void nextPage();
    void prevPage();
    void openFromCalendar(int page, int notebook);
    void browseKeywords();
    void browseKeywords(int numNotebook);

    void loadTab();

};

#endif // MAINWINDOW_H
