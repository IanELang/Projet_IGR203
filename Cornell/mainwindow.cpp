#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QWidget * container = new QWidget();
    this->setCentralWidget(container);

    QHBoxLayout* global = new QHBoxLayout(container);

    QVBoxLayout* sideBar = new QVBoxLayout();
    QGridLayout* notebookGrid = new QGridLayout();

    global->addLayout(sideBar);
    global->addLayout(notebookGrid);
/*
    QImage userImg;
    userImg.load("Resources/user.png");
    QLabel userLabel;
    userLabel.setPixmap(QPixmap::fromImage(userImg));
    sideBar->addWidget(userLabel);*/

    QPushButton *importButton = new QPushButton(this);
    importButton->setText(tr("Import notes"));
    sideBar->addWidget(importButton, Qt::AlignVCenter);

    QPushButton *exportButton = new QPushButton(this);
    exportButton->setText(tr("Export notes"));
    sideBar->addWidget(exportButton, Qt::AlignVCenter);


    notebookGrid->addWidget(new QPushButton("Button 1"),0,5);
    notebookGrid->addWidget(new QPushButton("Button 1"),1,0);
    /*
    for(int i = 0; i < notebooks.size(); i++)
    {
        notebookGrid->addItem(new QPushButton("Button 1"),0,1);
    }*/


}

MainWindow::~MainWindow()
{
    delete ui;
}
