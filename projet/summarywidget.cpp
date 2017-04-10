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

    QGridLayout *layout = new QGridLayout();
    this->setLayout(layout);
    QLabel* notebookName = new QLabel();
    notebookName->setText(  "<html><b>" + notebook.name + "</b></html>");
    layout->addWidget( notebookName, 0, 0, 2, 0, Qt::AlignHCenter );

    for(int i=0; i<notebook.pages.size(); i++){
        QLabel* date = new QLabel();
        clickLabel* buttonKeyword = new clickLabel(i, 1);
        buttonKeyword->setText(notebook.pages[i].creationDate.toString() + ": " + notebook.pages[i].summary);
        layout->addWidget(buttonKeyword,i+4,0, Qt::AlignLeft);
        connect(buttonKeyword, SIGNAL(clicked(int, int)), controller, SLOT(text(int, int)));
    }

}




