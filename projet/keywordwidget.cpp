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

    QScrollArea *scrollarea = new QScrollArea(this);
    scrollarea->setWidgetResizable(true);

    QWidget * gallery = new QWidget();
    scrollarea->setWidget(gallery);

    gallery->setMinimumWidth(870);
    gallery->setMinimumHeight(600);
    scrollarea->setMinimumWidth(870);
    scrollarea->setMinimumHeight(600);


    QPalette pal = palette();

    pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
   // this->show();

    QGridLayout *layout = new QGridLayout();
    gallery->setLayout(layout);
    clickLabel* notebookName = new clickLabel();
    QWidget *rectangle1 = new QWidget();
    QHBoxLayout *layout2 = new QHBoxLayout(rectangle1);
    notebookName->setText(  "<html><b>" + notebook.name + "</b></html>");
    notebookName->setStyleSheet("color:#5d5b59;");
    notebookName->setFont( QFont( "sans-serif", 24 ) );
    //Helvetica
    rectangle1->setStyleSheet("border: 5px solid #5d5b59");

    layout->addWidget( rectangle1, 0, 0, 1, 0 );
    layout->addWidget( notebookName, 0, 0, 1, 0, Qt::AlignHCenter );


    for(int i=0; i<notebook.pages.size(); i++){
        clickLabel* date = new clickLabel(i, noteNum);
        date->setText(  "<html><b>" + notebook.pages[i].creationDate.toString() + "</b></html>");
        date->setStyleSheet("color:white;");
        QWidget *rectangle2 = new QWidget();
        QHBoxLayout *layout2 = new QHBoxLayout(rectangle2);
        rectangle2->setStyleSheet("background-color: #5d5b59");

        layout->addWidget( rectangle2, 3, i);
        layout->addWidget(date , 3, i, Qt::AlignCenter);
         date->setFont( QFont( "sans-serif", 12) );

         clickLabel* summary = new clickLabel(i, noteNum);
         summary->setText( notebook.pages[i].summary);
         summary->setStyleSheet("color:white;");
         QWidget *rectangle4 = new QWidget();
         QHBoxLayout *layout4 = new QHBoxLayout(rectangle4);
         rectangle4->setStyleSheet("background-color: #aeadac");

         layout->addWidget( rectangle4, 4, i);
         layout->addWidget(summary , 4, i, Qt::AlignCenter);
          summary->setFont( QFont( "sans-serif", 12) );

        for(int j=0; j<notebook.pages[i].notes.size(); j++){
           layout->setHorizontalSpacing(4);
           layout->setVerticalSpacing(4);
           clickLabel* buttonKeyword = new clickLabel(i, noteNum);

           QWidget* rectangle3 = new QWidget();
           QHBoxLayout *layout3 = new QHBoxLayout(rectangle3);
           rectangle3->setStyleSheet("border: 1px solid #868482 ");
           layout->addWidget( rectangle3, j+5,i);

           buttonKeyword->setText(notebook.pages[i].notes[j].keyword);
           buttonKeyword->setFont( QFont( "sans-serif", 10) );

           layout->addWidget(buttonKeyword,j+5,i, Qt::AlignCenter);


           connect(buttonKeyword, SIGNAL(clicked(int, int)), controller, SLOT(openFromCalendar(int, int)));
           connect(date, SIGNAL(clicked(int, int)), controller, SLOT(openFromCalendar(int, int)));
           connect(notebookName, SIGNAL(clicked(int, int)), controller, SLOT(openFromCalendar(int, int)));
           connect(summary, SIGNAL(clicked(int, int)), controller, SLOT(openFromCalendar(int, int)));
        }




}











}
