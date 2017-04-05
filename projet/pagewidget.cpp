#include "pagewidget.h"

#include <QDebug>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QScrollArea>

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

PageWidget::PageWidget(Page &page)
{
    this->setLayout(vLayout);
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
    for (int i = 0; i < page.notes.size(); i++) {
        //std::cout << page.notes[i].keyword.toStdString() << std::endl;
        addText(page.notes[i].keyword, page.notes[i].content);
    }
}

void PageWidget::addText(){
    QWidget * gallerie = new QWidget();
    vLayout->addWidget(gallerie);
    QHBoxLayout* hLayout = new QHBoxLayout();
    QTextEdit* keyword = new QTextEdit();
    QTextEdit* notes = new QTextEdit();
    hLayout->addWidget(keyword);
    hLayout->addWidget(notes);
    gallerie->setLayout(hLayout);

}

void PageWidget::addText(QString sKeyword, QString sContent){
    QWidget * gallerie = new QWidget();
    vLayout->addWidget(gallerie);
    QHBoxLayout* hLayout = new QHBoxLayout();
    QTextEdit* keyword = new QTextEdit();
    keyword->setText(sKeyword);
    QTextEdit* notes = new QTextEdit();
    notes->setText(sContent);
    hLayout->addWidget(keyword);
    hLayout->addWidget(notes);
    gallerie->setLayout(hLayout);

}
