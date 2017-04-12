#include "pagewidget.h"

#include <QDebug>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QGroupBox>


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


    QGroupBox *groupBox = new QGroupBox();

           //Browse
           QPushButton* bk = new QPushButton();
           bk->setIcon(QIcon(":/images/browse.png.png"));
           bk->setIconSize(QSize(50,50));
           QString browse = "Browse Keywords";
           bk->setToolTip(browse);

           //Previous Page
           QPushButton* prev = new QPushButton();
           prev->setIcon(QIcon(":/images/next2.png"));
           QString previous = "Previous Page";
           prev->setToolTip(previous);
           prev->setIconSize(QSize(50,50));

            //Next Page
           QPushButton* nextP = new QPushButton();
           nextP->setIcon(QIcon(":/images/next.png"));
           QString next = "Next Page";
           nextP->setToolTip(next);
           nextP->setIconSize(QSize(50,50));


           //New Page
           QPushButton* newPage = new QPushButton();
           newPage->setIcon(QIcon(":/images/newPage.png"));
           QString newP = "New Page";
           newPage->setToolTip(newP);
           newPage->setIconSize(QSize(50,50));

           //New note
           QPushButton* button = new QPushButton();
           QString newN = "New Note";
           button->setToolTip(newN);
           button->setIcon(QIcon(":/images/newNote.png"));
           button->setIconSize(QSize(50,50));


           QHBoxLayout *hbox = new QHBoxLayout;
               hbox->addWidget(bk);
               hbox->addWidget(prev);
               hbox->addWidget(nextP);
               hbox->addWidget(newPage);
               hbox->addWidget(button);
               hbox->addStretch(1);
               groupBox->setLayout(hbox);


           vLayout->addWidget(groupBox);



    vLayout->addWidget(summary);







    if (hasSuc) {
       // QPushButton* next = new QPushButton("Next Page");
       // vLayout->addWidget(next);
        connect(nextP, SIGNAL(clicked()), controller, SLOT(nextPage()));
    }
    if (hasPred) {
       // QPushButton* prev = new QPushButton("Previous Page");
        //vLayout->addWidget(prev);
        connect(prev, SIGNAL(clicked()), controller, SLOT(prevPage()));
    }
    //QPushButton* button = new QPushButton("New Note");
    //vLayout->addWidget(button);

    connect(button, SIGNAL(clicked()), this, SLOT(addText()));

   // QPushButton* newP = new QPushButton("New Page");
   // vLayout->addWidget(newP);
    connect(newPage, SIGNAL(clicked()), controller, SLOT(newPage()));


   // QPushButton* bk = new QPushButton("Browse Keywords");
   // vLayout->addWidget(bk);
    connect(bk, SIGNAL(clicked()), controller, SLOT(browseKeywords()));

    QPushButton* bs = new QPushButton("Browse Summaries");
    vLayout->addWidget(bs);
    //connect(bs, SIGNAL(clicked()), controller, SLOT(browseKeywords()));
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
