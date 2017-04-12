#include "clicklabel.h"

clickLabel::clickLabel(const QString& text, QWidget* parent)
    : QLabel(parent)
{
    setText(text);
}

clickLabel::clickLabel(const QString& text, int n_Page, int n_Notebook){
    setText(text);
    pageNumber = n_Page;
    notebookNumber = n_Notebook;

}

clickLabel::clickLabel(int n_Page, int n_Notebook){
    pageNumber = n_Page;
    notebookNumber = n_Notebook;
}

void clickLabel::enterEvent(QEvent *ev){
    dse = new QGraphicsOpacityEffect();
    dse->setOpacity(0.5);
    this->setGraphicsEffect(dse);

    emit hover();
}

void clickLabel::leaveEvent(QEvent *ev){
    dse->setOpacity(1.0);
}

clickLabel::~clickLabel(){
}

void clickLabel::mousePressEvent(QMouseEvent* event){
    emit clicked(pageNumber, notebookNumber);
}
