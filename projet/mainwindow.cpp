#include <QFile>
#include <QDataStream>
#include <iostream>

#include "mainwindow.h"
#include "pagewidget.h"

#include "notebookchooser.h"
#include "keywordwidget.h"
#include "calendar.h"
#include "createdata.h"

#include <QTabWidget>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //createData();
    QFile file("notebooks/file.ntb");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> notebooks;
    int a;
    in >> a;
    updateCalendar();
    curNotebook = 0;
    curPage = 0;

}
void MainWindow::loadTab(){
    closePage();
    updateCalendar();
}

void MainWindow::updateCalendar(){
    QTabWidget*tab = new QTabWidget();

    tab->addTab(new NotebookChooser(notebooks, this), "Notebooks");
    tab->addTab(new Calendar(notebooks, this), "Calendar");

    this->setCentralWidget(tab);
}

MainWindow::~MainWindow()
{
}

void MainWindow::openPage(int ntbk, int pg)
{
    curPage = pg;
    curNotebook = ntbk;
    content = new PageWidget(notebooks[ntbk].pages[pg], this, pg < notebooks[ntbk].pages.size()-1, pg != 0, notebooks[curNotebook].name);
    this->setCentralWidget(content);
}

void MainWindow::closePage()
{
    notebooks[curNotebook].pages[curPage] = ((PageWidget *)content)->toPage();
}

void MainWindow::newPage()
{
    closePage();
    notebooks[curNotebook].pages.append(Page("new page", QDate::currentDate()));
    openPage(curNotebook, notebooks[curNotebook].pages.size() - 1);
}

void MainWindow::newPage(int numNotebook)
{
    notebooks[numNotebook].pages.append(Page("new page", QDate::currentDate()));
    openPage(numNotebook, notebooks[numNotebook].pages.size() - 1);
}

void MainWindow::browseKeywords(int numNotebook)
{
    curNotebook = numNotebook;
    this->setCentralWidget(new KeywordWidget(notebooks[curNotebook], curNotebook, this));
}

void MainWindow::nextPage()
{
    closePage();
    curPage++;
    openPage(curNotebook,curPage);
}

void MainWindow::prevPage()
{
    closePage();
    curPage--;
    openPage(curNotebook,curPage);
}

void MainWindow::openFromCalendar(int page, int notebook)
{
    curNotebook = notebook;
    curPage = page;
    openPage(notebook, page);
}

void MainWindow::browseKeywords()
{
    closePage();
    this->setCentralWidget(new KeywordWidget(notebooks[curNotebook], curNotebook, this));
}
