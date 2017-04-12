#include "keywordwidget.h"

#include "page.h"

#include <QDebug>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QScrollArea>
#include <QTableWidget>

#include <QTextEdit>
#include <iostream>
#include <QPainter>
#include <QLayoutItem>

#include "clicklabel.h"
#include "rectangle.h"



KeywordWidget::KeywordWidget(Notebook notebook,  MainWindow *_controller):
    controller{_controller}
{

    QPalette pal = palette();

    pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->show();

    QGridLayout *layout = new QGridLayout();
    this->setLayout(layout);
    QLabel* notebookName = new QLabel();
    QWidget *rectangle1 = new QWidget();
    QHBoxLayout *layout2 = new QHBoxLayout(rectangle1);
    notebookName->setText(  "<html><b>" + notebook.name + "</b></html>");
    notebookName->setStyleSheet("color:white;");
    notebookName->setFont( QFont( "sans-serif", 24 ) );
    //Helvetica
    rectangle1->setStyleSheet("background-color: #5d5b59");

    layout->addWidget( rectangle1, 0, 0, 1, 0 );
    layout->addWidget( notebookName, 0, 0, 1, 0, Qt::AlignHCenter );


    for(int i=0; i<notebook.pages.size(); i++){
        QLabel* date = new QLabel();
        date->setText(  "<html><b>" + notebook.pages[i].creationDate.toString() + "</b></html>");
        date->setStyleSheet("color:white;");

        QWidget *rectangle2 = new QWidget();
        QHBoxLayout *layout2 = new QHBoxLayout(rectangle2);
        rectangle2->setStyleSheet("background-color: #aeadac");

        layout->addWidget( rectangle2, 3, i);
        layout->addWidget(date , 3, i, Qt::AlignCenter);
         date->setFont( QFont( "sans-serif", 12) );

        for(int j=0; j<notebook.pages[i].notes.size(); j++){
           layout->setHorizontalSpacing(4);
           layout->setVerticalSpacing(4);
           clickLabel* buttonKeyword = new clickLabel(i, 1);

           QWidget* rectangle3 = new QWidget();
           QHBoxLayout *layout3 = new QHBoxLayout(rectangle3);
           rectangle3->setStyleSheet("border: 1px solid #868482 ");
           layout->addWidget( rectangle3, j+4,i);

           buttonKeyword->setText(notebook.pages[i].notes[j].keyword);
           buttonKeyword->setFont( QFont( "sans-serif", 10) );

           layout->addWidget(buttonKeyword,j+4,i, Qt::AlignCenter);


           connect(buttonKeyword, SIGNAL(clicked(int, int)), controller, SLOT(text(int, int)));
        }




}











}
