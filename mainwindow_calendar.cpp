#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "day.h"
#include "calendar.h"

#include "page.h"


#include "clicklabel.h"
#include <QGridLayout>
#include <QDate>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <iostream>
#include <map>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //    ui->setupUi(this);

    // declarar na mainwindow.h
    Calendar * cal = new Calendar();
    //cal->tudo();



    clickLabel *nota = new clickLabel("hm", 10, 1);

    QPushButton  *b = new QPushButton("test");

    // connect(nota, SIGNAL(clicked()), this, SLOT (testinho()));

    QLabel *nota3 = new QLabel("aula imageem");

    QLabel *nota2 = new QLabel("aula dsadadsdasdasda");
    QLabel *nota4 = new QLabel("aula ");

    clickLabel *nota5 = new clickLabel("teste page ", 12, 3);

    cal->addNote(9, nota);
    cal->addNote(9, nota2);
    cal->addNote(9, nota4);

    cal->addNote(14, nota3);

    // quando cria uma pagina, precisa do nome do caderno, tem-se um label

    Page *pag= new Page("IGR 203");

    //pag->label = nota5;


    cal->addNote(10, pag);
   // cal->addNote(13, pag->label);

    cal->addNote(11, nota5);

    this->setCentralWidget(cal);

    connect(nota5, SIGNAL(kaka(int a, int b)), cal, SLOT (teste()));

  //  connect(pag->label, SIGNAL(clicked()), cal, SLOT (teste()));
}


MainWindow::~MainWindow()
{
    delete ui;
}
