#include <QFile>
#include <QDataStream>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pagewidget.h"

#include "notebookchooser.h"
#include "keywordwidget.h"
#include "calendar.h"

#include "summarywidget.h"

#include "createdata.h"

#include <QTabWidget>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    createData();
    QFile file("file.xxx");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> notebooks;
    int a;
    in >> a;
    //this->setCentralWidget(new PageWidget(notebooks[0].pages[0], this, true, true));
    //cal = new Calendar(notebooks, this);

    QTabWidget*tab = new QTabWidget();

    tab->addTab(new NotebookChooser(notebooks, this), "Notebooks");
    tab->addTab(new Calendar(notebooks, this), "Calendar");

    this->setCentralWidget(tab);
   // this->setCentralWidget(new Calendar(notebooks, this));
    //openPage(0, 0);
    curNotebook = 0;
    curPage = 0;

    //this->setCentralWidget( new NotebookChooser(notebooks, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openPage(int ntbk, int pg)
{
    content = new PageWidget(notebooks[ntbk].pages[pg], this, pg < notebooks[ntbk].pages.size()-1, pg != 0);
    this->setCentralWidget(content);
}

void MainWindow::closePage()
{
    notebooks[curNotebook].pages[curPage] = ((PageWidget *)content)->toPage();
}

void MainWindow::newPage()
{
    notebooks[curNotebook].pages.append(Page());
    nextPage();
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
