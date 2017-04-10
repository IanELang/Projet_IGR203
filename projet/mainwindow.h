#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QWidget>

#include "notebook.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Ui::MainWindow *ui;
    QVector<Notebook> notebooks;

    int curNotebook;
    int curPage;

    QWidget *content;

    void openPage(int ntbk, int pg);
    void closePage();


    //For development
    void createData();
    void terminal();

    public slots:
    void newPage();
    void nextPage();
    void prevPage();
    void openFromCalendar(int page, int notebook);
};

#endif // MAINWINDOW_H
