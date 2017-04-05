#include <QFile>
#include <QDataStream>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pagewidget.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    this->setCentralWidget(new PageWidget());
    createData();
    QFile file("file.xxx");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> notebooks;
    int a;
    in >> a;
    terminal();
}

MainWindow::~MainWindow()
{
    delete ui;
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
    Page a1;
    a1.notes.push_back(Note("Largest country in South America", "Brazil"));
    a1.notes.push_back(Note("Largest country in North America", "USA"));
    a1.notes.push_back(Note("Largest country in Asia", "Russia"));
    a1.notes.push_back(Note("Largest country in Europe", "Also russia"));
    a.pages.push_back(a1);
    Page a2;
    a2.notes.push_back(Note("Most thunder strikes per year", "Brazil"));
    a2.notes.push_back(Note("Best (?) cheese", "France"));
    a.pages.push_back(a1);
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
