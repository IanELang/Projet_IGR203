#ifndef NOTEBOOKCHOOSER_H
#define NOTEBOOKCHOOSER_H

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

class NotebookChooser : public QWidget
{

Q_OBJECT

public:
    explicit NotebookChooser(QWidget *parent = 0);
    ~NotebookChooser();

private slots:
    void newNote(int ntbNum);
    void reviewNotes(int ntbNum);
    void addNotebook();
    void importNotebooks();
    void exportNotebooks();
    void addNotebooksToGrid();
    void openCalendar();

private:
    QVector<Notebook> notebooks;
    QSignalMapper* newNoteMapper;
    QSignalMapper* reviewNoteMapper;
    QGridLayout* notebookGrid;

    int ncols;

    void remove(QGridLayout *layout, bool deleteWidgets);
    void deleteChildWidgets(QLayoutItem *item);

};

#endif // NOTEBOOKCHOOSER_H
