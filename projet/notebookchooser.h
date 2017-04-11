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
#include <QResizeEvent>
#include <QDir>
#include "notebook.h"

class NotebookChooser : public QWidget
{

Q_OBJECT

public:
    explicit NotebookChooser(QVector<Notebook> notebooks, QWidget *parent = 0);
    ~NotebookChooser();

private slots:
    void newNote(int ntbNum);
    void reviewNotes(int ntbNum);
    void reviewSummaries(int ntbNum);
    void addNotebook();
    void importNotebooks();
    void exportNotebooks();
    void addNotebooksToGrid();

private:
    QVector<Notebook> notebooks;
    QSignalMapper* newNoteMapper;
    QSignalMapper* reviewNotesMapper;
    QSignalMapper* reviewSummariesMapper;
    QGridLayout* notebookGrid;

    int ncols;

    void remove(QGridLayout *layout, bool deleteWidgets);
    void deleteChildWidgets(QLayoutItem *item);
    void resizeEvent(QResizeEvent *event);


};

#endif // NOTEBOOKCHOOSER_H
