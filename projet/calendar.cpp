#include "calendar.h"

#include "page.h"


#include "clicklabel.h"
#include <QGridLayout>
#include <QDate>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <iostream>
#include <map>
#include <QWidget>


Calendar::Calendar(QVector<Notebook> &notebooks, MainWindow *mw, QWidget *widget)
{

    data = new QDate();
    *data = QDate::currentDate();


    this->setMinimumWidth(870);
    this->setMinimumHeight(600);

    this->setMaximumWidth(870);
    this->setMaximumHeight(600);

    layout = new QVBoxLayout();
    jours = new QHBoxLayout();

    grid = new QGridLayout();
    this->setLayout(layout);

    layout->addLayout(jours);
    layout->addLayout(grid);

    QLabel * lundi = new QLabel( ("Monday"));
    QLabel * mardi = new QLabel( ("Tuesday"));
    QLabel * mercredi = new QLabel( ("Wednesday"));
    QLabel * jeudi = new QLabel( ("Thursday"));
    QLabel * vendredi = new QLabel( ("Friday"));
    QLabel * samedi = new QLabel( ("Saturday"));
    QLabel * dimanche = new QLabel( ("Sunday"));

    lundi->setAlignment(Qt::AlignCenter);
    mardi->setAlignment(Qt::AlignCenter);
    mercredi->setAlignment(Qt::AlignCenter);
    jeudi->setAlignment(Qt::AlignCenter);
    vendredi->setAlignment(Qt::AlignCenter);
    samedi->setAlignment(Qt::AlignCenter);
    dimanche->setAlignment(Qt::AlignCenter);

    jours->addWidget(lundi,1);
    jours->addWidget(mardi,1);
    jours->addWidget(mercredi,1);
    jours->addWidget(jeudi,1);
    jours->addWidget(vendredi,1);
    jours->addWidget(samedi,1);
    jours->addWidget(dimanche,1);

    int minHeight = 120;
    int minmWidth = 120;

    grid->setHorizontalSpacing(4);
    grid->setVerticalSpacing(4);

    grid->setRowMinimumHeight(0, minHeight);
    grid->setRowMinimumHeight(1, minHeight);
    grid->setRowMinimumHeight(2, minHeight);
    grid->setRowMinimumHeight(3, minHeight);
    grid->setRowMinimumHeight(4, minHeight);

    grid->setColumnMinimumWidth(1, minmWidth);
    grid->setColumnMinimumWidth(2, minmWidth);
    grid->setColumnMinimumWidth(3, minmWidth);
    grid->setColumnMinimumWidth(4, minmWidth);
    grid->setColumnMinimumWidth(5, minmWidth);
    grid->setColumnMinimumWidth(6, minmWidth);
    grid->setColumnMinimumWidth(7, minmWidth);


    int a = data->currentDate().day();

    int colonne = data->currentDate().dayOfWeek(); // 7
    int aux = colonne;
    int ligne = a/7+1;


    for (int i = a; i >= 1; i--){

        Day * d = new Day();
        d->setDay(i, ligne, aux);
        this->addDay(d);
        grid->addWidget(d, ligne, aux);

        aux--;

        if (aux == 0){
            aux = 7;
            ligne--;
        }
    }

    aux = colonne;
    ligne = a/7+1;

    for (int i=a; i<= data->currentDate().daysInMonth(); i++){

        Day * d = new Day();
        d->setDay(i, ligne, aux);
        this->addDay(d);

        if (i == a) d->today();

        grid->addWidget(d, ligne, aux);

        aux++;

        if (aux == 8){
            aux = 1;
            ligne++;
        }

    }

    std::cout << data->month() << std::endl;
    for (int i = 0; i < notebooks.size(); i++) {
        for (int j = 0; j < notebooks[i].pages.size(); j++) {
            std::cout << notebooks[i].pages[j].creationDate.month() << std::endl;
            if (notebooks[i].pages[j].creationDate.month() == data->month()) {
                clickLabel *newLabel = new clickLabel(notebooks[i].name, j, i);
                addNote(notebooks[i].pages[j].creationDate.day(), newLabel);
                connect(newLabel, SIGNAL(clicked(int,int)), mw, SLOT(openFromCalendar(int,int)));
            }
        }
    }
}


void Calendar::addNote(int day, QLabel *nota){
    if(days.size() != 0){
        for(unsigned int i = 0; i < days.size(); i++){
            if(days[i]->number == day){
                days[i]->addNoteWidget(nota);

            }
        }
    }

}

void Calendar::addDay(int day, int line, int colonne){
    Day * d = new Day();
    d->number = day;
    d->calendarLine = line;
    d->calendarColumn = colonne;
    days.push_back(d);
    //days.push_back(new Day(day, line, colonne));
}

void Calendar::addDay(Day *d){
    days.push_back(d);
}

//void Calendar::teste(){
//    std::cout << "sadhsdas " << std::endl;
//}
