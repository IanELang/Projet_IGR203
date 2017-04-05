#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QScrollArea>

#include <QTextEdit>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
   // ui(new Ui::MainWindow)
{
   // ui->setupUi(this);


       this->setCentralWidget(container);





       container->setLayout(vLayout);

       hLayout = new QHBoxLayout(); //part de dalt


       QTextEdit* cours = new QTextEdit();
       QTextEdit* summary = new QTextEdit();
       summary->setText("Summary...");
       cours->setText("Cours...");
       vLayout->addWidget(cours);
       vLayout->addWidget(summary);
       QPushButton* button = new QPushButton("+");

       vLayout->addWidget(button);

       QWidget * gallerie = new QWidget();
       vLayout->addWidget(gallerie);
       gallerie->setLayout(hLayout);



       QTextEdit* keyword = new QTextEdit();
       QTextEdit* notes = new QTextEdit();
       keyword->setText("Keyword...");
       notes->setText("Notes...");
       hLayout->addWidget(keyword);
       hLayout->addWidget(notes);


       connect(button, SIGNAL(clicked()), this, SLOT(addText()));



}


void MainWindow::addText(){
    QWidget * gallerie = new QWidget();
    vLayout->addWidget(gallerie);

    QHBoxLayout* hLayout = new QHBoxLayout();
    std::cout << "Quit App" << std::endl;
    QTextEdit* keyword = new QTextEdit();
    QTextEdit* notes = new QTextEdit();
    hLayout->addWidget(keyword);
    hLayout->addWidget(notes);
    gallerie->setLayout(hLayout);

}

MainWindow::~MainWindow()
{
    delete ui;
}
