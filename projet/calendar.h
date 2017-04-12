#ifndef CALENDAR_H
#define CALENDAR_H

#include <vector>
#include "day.h"
#include <iostream>

#include <QDate>

#include "notebook.h"

class Calendar : public QWidget
{
    Q_OBJECT

private:
     QDate *data;
     QVBoxLayout * layout;
     QHBoxLayout * jours;
     QGridLayout * grid;

public:
    Calendar(QVector<Notebook> const & notebooks, QWidget *widget=0);
    std::vector<Day*> days;

    void addDay(int day, int line, int colonne);
    void addDay(Day *d);
    void addNote(int day, QLabel *nota, int nnb);


};

#endif // CALENDAR_H
