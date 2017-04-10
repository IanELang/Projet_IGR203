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

clickLabel::~clickLabel()
{
}

void clickLabel::mousePressEvent(QMouseEvent* event)
{
    //emit kaka(pageNumber, notebookNumber);
    emit clicked();

}
