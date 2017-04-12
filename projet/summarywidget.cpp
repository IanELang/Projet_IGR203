#include "summarywidget.h"

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


SummaryWidget::SummaryWidget(Notebook notebook, MainWindow *_controller) :
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
        rectangle1->setStyleSheet("background-color: #5d5b59");
        layout->addWidget( rectangle1, 0, 0, 1, 0 );
        layout->addWidget( notebookName, 0, 0, 1, 0, Qt::AlignHCenter );



        for(int i=0; i<notebook.pages.size(); i++){
            QLabel* date = new QLabel();
            clickLabel* buttonKeyword = new clickLabel(i, 1);
            clickLabel* buttonKeywordDate = new clickLabel(i, 1);


            QWidget* rectangle2 = new QWidget();
            rectangle2->setStyleSheet("border: 1px solid #868482 ");

            QHBoxLayout *layout2 = new QHBoxLayout(rectangle2);


            buttonKeyword->setStyleSheet("padding: 0px 5px 10px 15px ");

            layout->addWidget( rectangle2, i+4,0);
            buttonKeyword->setFont( QFont( "sans-serif", 10) );
            buttonKeyword->setText("<html><b>" + notebook.pages[i].creationDate.toString() +  ": </b></html>" + notebook.pages[i].summary);
            buttonKeyword->setWordWrap(true);

            layout->addWidget(buttonKeyword,i+4,0);
            connect(buttonKeyword, SIGNAL(clicked(int, int)), controller, SLOT(text(int, int)));
    }

}




