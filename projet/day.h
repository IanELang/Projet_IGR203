#ifndef DAY_H
#define DAY_H

#include <QLabel>
#include <vector>
#include <QWidget>
#include <QRectF>
#include <QVBoxLayout>


class Day : public QWidget
{
    //   Q_OBJECT
public:

    explicit Day(QWidget *parent = 0);
    // Day();
    Day(int jour, int line, int dayOfWeek){
        number = jour;
        // month = mois;
        calendarColumn = dayOfWeek;
        calendarLine = line;
    }
    //   void paintEvent(QPaintEvent *);


    int getDayOfWeek(){
        return calendarColumn;
    }

    int getCalendarLine(){
        return calendarLine;
    }


    void setDay(int jour, int line, int dayOfWeek){
        number = jour;
        // month = mois;
        calendarColumn = dayOfWeek;
        calendarLine = line;

        QString s = QString::number(jour);
        n = new QLabel(s);
        n->setAlignment(Qt::AlignLeft);
        lala->addWidget(n);
    }

    void today(){
        QPalette pal = palette();

        // set yellow background
        pal.setColor(QPalette::Background, Qt::yellow);
        n->setAutoFillBackground(true);
        n->setPalette(pal);

    }

    void addNoteWidget(QLabel *nota){
        // pode mudar a cor dependendo do caderno
        // pode ja criar a label na nota
        // uma cor por caderno, tentar pegar a cor automaticamente - talvez se usar palettes fica mais facil

        nota->setStyleSheet("QLabel { background-color : #DDA0DD; color : #000; }");

     //   lala->setAlignment(Qt::AlignJustify);
        lala->addWidget(nota);
    }

    //public:
    QLabel * n;
    int number;
    int month;
    int calendarLine;
    int calendarColumn; // day of week
    QVBoxLayout *lala;
    // vector des cours
};

#endif // DAY_H
