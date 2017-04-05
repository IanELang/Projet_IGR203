#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QDataStream>
#include <QVector>
#include "page.h"

class Notebook
{
public:
    Notebook();
    Notebook(QString _name) : name(_name) {}

    friend class MainWindow;
    friend QDataStream &operator<<(QDataStream & stream, const Notebook &notebook);
    friend QDataStream &operator>>(QDataStream & stream, Notebook &notebook);

    QString name;
    QVector<Page> pages;
};

#endif // NOTEBOOK_H

QDataStream &operator<<(QDataStream & stream, const Notebook &notebook);
QDataStream &operator>>(QDataStream & stream, Notebook &notebook);
