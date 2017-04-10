#ifndef PAGE_H
#define PAGE_H

#include "note.h"

#include <QString>
#include <QDate>
#include <QVector>
#include <QDataStream>

class Page
{
public:
    Page() {}
    Page(QString _summary) : summary(_summary) {}

    friend class MainWindow;
    friend QDataStream &operator<<(QDataStream & stream, const Page &page);
    friend QDataStream &operator>>(QDataStream & stream, Page &page);

    QVector<Note> notes;
    QDate creationDate;
    QString summary;
    QString title;
};

QDataStream &operator<<(QDataStream & stream, const Page &page);
QDataStream &operator>>(QDataStream & stream, Page &page);

#endif // PAGE_H
