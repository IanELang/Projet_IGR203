#include "pagewidget.h"

#include <QDebug>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>


#include <iostream>

#include "pagewidget.h"

PageWidget::PageWidget(Page page, MainWindow *_controller, bool hasSuc, bool hasPred) :
    controller(_controller), date(page.creationDate)
{
    QScrollArea* gallery = this;
    //this->addWidget(gallery);
    gallery->setWidgetResizable(true);
    QWidget* galleryWidget = new QWidget();
    gallery->setWidget(galleryWidget);
    galleryWidget->setLayout(vLayout);
    summary = new QTextEdit();
    summary->setText(page.summary);
    vLayout->addWidget(summary);
    if (hasSuc) {
        QPushButton* next = new QPushButton("Next Page");
        vLayout->addWidget(next);
        connect(next, SIGNAL(clicked()), controller, SLOT(nextPage()));
    }
    if (hasPred) {
        QPushButton* prev = new QPushButton("Previous Page");
        vLayout->addWidget(prev);
        connect(prev, SIGNAL(clicked()), controller, SLOT(prevPage()));
    }
    QPushButton* button = new QPushButton("New Note");
    vLayout->addWidget(button);
    connect(button, SIGNAL(clicked()), this, SLOT(addText()));
    QPushButton* next = new QPushButton("New Page");
    vLayout->addWidget(next);
    connect(next, SIGNAL(clicked()), controller, SLOT(newPage()));
    QPushButton* bk = new QPushButton("Browse Keywords");
    vLayout->addWidget(bk);
    connect(bk, SIGNAL(clicked()), controller, SLOT(browseKeywords()));
    QWidget * gallerie = new QWidget();
    vLayout->addWidget(gallerie);
    for (int i = 0; i < page.notes.size(); i++) {
        addText(page.notes[i].keyword, page.notes[i].content);
    }
}

void PageWidget::addText() {
    addText("new keyword", "new note");
}

void PageWidget::addText(QString sKeyword, QString sContent){
    QWidget * gallerie = new QWidget();
    vLayout->addWidget(gallerie);
    QHBoxLayout* hLayout = new QHBoxLayout();
    QTextEdit* keyword = new QTextEdit();
    keywords.push_back(keyword);
    keyword->setText(sKeyword);
    QTextEdit* note = new QTextEdit();
    note->setText(sContent);
    notes.push_back(note);
    hLayout->addWidget(keyword);
    hLayout->addWidget(note);
    gallerie->setLayout(hLayout);
}

Page PageWidget::toPage(){
    Page ret;
    for (int i = 0; i < keywords.size(); i++) {
        Note newNote(notes[i]->toPlainText(), keywords[i]->toPlainText());
        ret.notes.append(newNote);
    }
    ret.summary = summary->toPlainText();
    ret.creationDate = date;
    return ret;
}
