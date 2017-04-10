#ifndef CALENDAR_H
#define CALENDAR_H

#include <vector>
#include "day.h"
#include <iostream>

class Calendar : public QWidget
{
    Q_OBJECT

private:
     QDate *data;
     QVBoxLayout * layout;
     QHBoxLayout * jours;
     QGridLayout * grid;

public:
    Calendar(QWidget *widget=0);
    std::vector<Day*> days;

    void addDay(int day, int line, int colonne);
    void addDay(Day *d);
    void addNote(int day, QLabel *nota);

public slots:
    void teste(){ std::cout << "sadhsdas " << std::endl;}
    //void mostrar();


};

#endif // CALENDAR_H
