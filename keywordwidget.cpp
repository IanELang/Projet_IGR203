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

#include "clicklabel.h"



KeywordWidget::KeywordWidget(Notebook notebook,  MainWindow *_controller):
    controller{_controller}
{

    QGridLayout *layout = new QGridLayout();
    this->setLayout(layout);
    QLabel* notebookName = new QLabel();
    notebookName->setText(  "<html><b>" + notebook.name + "</b></html>");
    layout->addWidget( notebookName, 0, 0, 2, 0, Qt::AlignHCenter );

    for(int i=0; i<notebook.pages.size(); i++){
        QLabel* date = new QLabel();
        date->setText(  "<html><b>" + notebook.pages[i].creationDate.toString() + "</b></html>");
        layout->addWidget(date , 3, i, Qt::AlignCenter);
        for(int j=0; j<notebook.pages[i].notes.size(); j++){
           clickLabel* buttonKeyword = new clickLabel(i, 1);
           buttonKeyword->setText(notebook.pages[i].notes[j].keyword);
           layout->addWidget(buttonKeyword,j+4,i, Qt::AlignCenter);
           connect(buttonKeyword, SIGNAL(clicked(int, int)), controller, SLOT(text(int, int)));
        }
}













}
