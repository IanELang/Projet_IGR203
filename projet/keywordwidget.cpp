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




KeywordWidget::KeywordWidget(Notebook notebook,  int noteNum, MainWindow *_controller):
    controller{_controller}
{

    this->setMinimumWidth(870);
    this->setMinimumHeight(600);

    QGridLayout *layout = new QGridLayout();
    QScrollArea *scrollarea = new QScrollArea(this);

    QWidget * gallery = new QWidget();

    scrollarea->setMinimumWidth(_controller->size().width()-10);
    scrollarea->setMinimumHeight(_controller->size().height()-10);

    QPalette pal = palette();

    pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    // this->show();

    gallery->setLayout(layout);
    scrollarea->setWidget(gallery);

    scrollarea->setWidgetResizable(true);

    scrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);


    clickLabel* notebookName = new clickLabel(0, noteNum);
    QWidget *rectangle1 = new QWidget();
    //QHBoxLayout *layout2 = new QHBoxLayout(rectangle1);
    notebookName->setText(  "<html><b>" + notebook.name + "</b></html>");
    notebookName->setStyleSheet("color:#5d5b59;");
    notebookName->setFont( QFont( "sans-serif", 24 ) );
    //Helvetica
    rectangle1->setStyleSheet("border: 5px solid #5d5b59");

    layout->addWidget(rectangle1, 0, 0, 1, 0 );
    layout->addWidget(notebookName, 0, 0, 1, 0, Qt::AlignHCenter );

    layout->setRowMinimumHeight(0,30);
    layout->setRowMinimumHeight(1,20);
    layout->setRowMinimumHeight(2,40);
    layout->setRowMinimumHeight(3,40);


    for(int i=0; i<notebook.pages.size(); i++){

        layout->setColumnMinimumWidth(i, qMax(200, this->size().width()/notebook.pages.size()));

        clickLabel* date = new clickLabel(i, noteNum);
        date->setText(  "<html><b>" + notebook.pages[i].creationDate.toString() + "</b></html>");
        date->setStyleSheet("color:white;");
        QWidget *rectangle2 = new QWidget();
        QWidget *rectangle4 = new QWidget();

        rectangle2->setStyleSheet("background-color: #5d5b59");
        date->setFont( QFont( "sans-serif", 12) );

        layout->addWidget(rectangle2, 2, i);
        layout->addWidget(date, 2, i, Qt::AlignCenter);

        clickLabel* summary = new clickLabel(i, noteNum);
        summary->setText( notebook.pages[i].summary.left(30) + "...");

        summary->setStyleSheet("color:white;");
        rectangle4->setStyleSheet("background-color: #aeadac");
        summary->setFont( QFont( "sans-serif", 12) );

        layout->addWidget(rectangle4, 3, i);
        layout->addWidget(summary, 3, i, Qt::AlignCenter);


        for(int j=0; j<notebook.pages[i].notes.size(); j++){

            layout->setRowMinimumHeight(j+4, 30);

            layout->setHorizontalSpacing(4);
            layout->setVerticalSpacing(4);
            clickLabel* buttonKeyword = new clickLabel(i, noteNum);
            buttonKeyword->setText(notebook.pages[i].notes[j].keyword);
            buttonKeyword->setFont( QFont( "sans-serif", 10) );


            QWidget* rectangle3 = new QWidget();
            //QHBoxLayout *layout3 = new QHBoxLayout(rectangle3);
            rectangle3->setStyleSheet("border: 1px solid #868482 ");
            layout->addWidget( rectangle3, j+4,i);



            layout->addWidget(buttonKeyword,j+4,i, Qt::AlignCenter);


            connect(buttonKeyword, SIGNAL(clicked(int, int)), controller, SLOT(openFromCalendar(int, int)));
            connect(date, SIGNAL(clicked(int, int)), controller, SLOT(openFromCalendar(int, int)));
            connect(notebookName, SIGNAL(clicked(int, int)), controller, SLOT(openFromCalendar(int, int)));
            connect(summary, SIGNAL(clicked(int, int)), controller, SLOT(openFromCalendar(int, int)));
        }




    }











}
