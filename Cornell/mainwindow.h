#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVector>
#include <QSignalMapper>
#include <iostream>
#include <QInputDialog>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QSpacerItem>
#include <QScrollArea>
#include <QDir>
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

private slots:
    void newNote(int ntbNum);
    void reviewNotes(int ntbNum);
    void addNotebook();
    void importNotebooks();
    void exportNotebooks();
    void addNotebooksToGrid();
    void openCalendar();

private:
    Ui::MainWindow *ui;
    QVector<Notebook> notebooks;
    QSignalMapper *newNoteMapper;
    QSignalMapper *reviewNoteMapper;
    QGridLayout* notebookGrid;

    int ncols;

    void remove(QGridLayout *layout, bool deleteWidgets);
    void deleteChildWidgets(QLayoutItem *item);

};

#endif // MAINWINDOW_H
