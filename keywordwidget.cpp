#include "keywordwidget.h"

#include "page.h"

#include <QDebug>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QScrollArea>

#include <QTextEdit>
#include <iostream>



KeywordWidget::KeywordWidget(Notebook notebook)
{

    this->setLayout(vLayout);

    hLayout = new QHBoxLayout(); //part de dalt




    QWidget * gallerie = new QWidget();
    vLayout->addWidget(gallerie);
    gallerie->setLayout(hLayout);



   // for(int i=0; i<notebook.size(); i++){
       //QTextEdit* keyword = new QTextEdit();
      // keyword->setText(notebook.note[i].keyword)
      // hLayout->addWidget(keyword);
   // }






}
