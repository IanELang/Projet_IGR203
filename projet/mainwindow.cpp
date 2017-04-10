#include <QFile>
#include <QDataStream>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pagewidget.h"

#include "calendar.h"

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
    this->setCentralWidget(new Calendar(notebooks, this));
    //openPage(0, 0);
    curNotebook = 0;
    curPage = 0;
    terminal();
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
    openPage(notebook, page);
}

void MainWindow::terminal()
{
    int cmd;
    for (int i = 0; i < notebooks.size(); i++) {
        cout << i << " " << notebooks[i].name.toStdString() << endl;
    }
}

void MainWindow::createData()
{
    QVector<Notebook> ntbks;
    Notebook a("Countries");
    Page a1("Asia", QDate(2017, 4, 16));
    a1.notes.push_back(Note("Afghanistan, officially the Islamic Republic of Afghanistan, is a landlocked country located within South Asia and Central Asia.[9][10] It has a population of approximately 32 million, making it the 42nd most populous country in the world.", "Afghanistan"));
    a1.notes.push_back(Note("Jordan, is an Arab kingdom in Western Asia, on the East Bank of the Jordan River. Jordan is bordered by Saudi Arabia to the east and south; Iraq to the north-east; Syria to the north; Israel, Palestine and the Dead Sea to the west; and the Red Sea in its extreme south-west.", "Jordan"));
    a1.notes.push_back(Note("Lebanon, is a sovereign state in Western Asia. It is bordered by Syria to the north and east and Israel to the south, while Cyprus is west across the Mediterranean Sea. ", "Lebanon"));
    a1.notes.push_back(Note("Largest country in Europe", "Also russia"));
    a.pages.push_back(a1);
    Page a2("America", QDate(2017, 4, 6));
    a2.notes.push_back(Note("Most thunder strikes per year", "Brazil"));
    a2.notes.push_back(Note("Best (?) cheese", "France"));
    a.pages.push_back(a2);
    ntbks.push_back(a);

    Notebook b("Islands");
    ntbks.push_back(b);

    QFile file("file.xxx");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    //out << "abcdef";
    out << ntbks;
    return;
}
