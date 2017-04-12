#include "pagewidget.h"
#include "page.h"

#include <QDebug>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QScrollArea>
#include <QGroupBox>

#include <QTextEdit>
#include <iostream>

#include "pagewidget.h"

PageWidget::PageWidget()
{

       this->setLayout(vLayout);

   hLayout = new QHBoxLayout(); //part de dalt


       QTextEdit* cours = new QTextEdit();
       QTextEdit* summary = new QTextEdit();
       summary->setText("Summary...");
       cours->setText("Cours...");
       vLayout->addWidget(cours);
       vLayout->addWidget(summary);
       QGroupBox *groupBox = new QGroupBox(tr("Exclusive Radio Buttons"));
       QPushButton* button1 = new QPushButton();
       button1->setIcon(QIcon(":/images/images/browse.png"));
       button1->setIconSize(QSize(50,50));
       QString browse = "Browse Keywords";
       button1->setToolTip(browse);
       QPushButton* button2 = new QPushButton();
       button2->setIcon(QIcon(":/images/images/next2.png"));
       QString previous = "Previous Page";
       button2->setToolTip(previous);
       button2->setIconSize(QSize(50,50));
       QPushButton* button3 = new QPushButton();
       button3->setIcon(QIcon(":/images/images/next.png"));
       QString next = "Next Page";
       button3->setToolTip(next);
       button3->setIconSize(QSize(50,50));
       QPushButton* button4 = new QPushButton();
        button4->setToolTip(  tr("Supprimer"));
       button4->setIcon(QIcon(":/images/images/newPage.png"));
       QString newP = "New Page";
       button4->setToolTip(newP);
       button4->setIconSize(QSize(50,50));
       QPushButton* button5 = new QPushButton();
       QString newN = "New Note";
       button5->setToolTip(newN);
       button5->setIcon(QIcon(":/images/images/newNote.png"));
       button5->setIconSize(QSize(50,50));


       QHBoxLayout *hbox = new QHBoxLayout;
           hbox->addWidget(button1);
           hbox->addWidget(button2);
           hbox->addWidget(button3);
           hbox->addWidget(button4);
           hbox->addWidget(button5);
           hbox->addStretch(1);
           groupBox->setLayout(hbox);


       vLayout->addWidget(groupBox);

       QWidget * gallerie = new QWidget();
       vLayout->addWidget(gallerie);
       gallerie->setLayout(hLayout);



       QTextEdit* keyword = new QTextEdit();
       QTextEdit* notes = new QTextEdit();
       keyword->setText("Keyword...");
       notes->setText("Notes...");
       hLayout->addWidget(keyword);
       hLayout->addWidget(notes);


       connect(button1, SIGNAL(clicked()), this, SLOT(addText()));
}

void PageWidget::addText(){
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
