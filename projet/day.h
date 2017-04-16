#ifndef DAY_H
#define DAY_H

#include <QLabel>
#include <vector>
#include <QWidget>
#include <QRectF>
#include <QVBoxLayout>
#include <QColor>


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
        vLayout->addWidget(n);
    }

    void today(){
        QPalette pal = palette();

        // set yellow background
        pal.setColor(QPalette::Background, Qt::yellow);
        n->setAutoFillBackground(true);
        n->setPalette(pal);

    }

    void addNoteWidget(QLabel *nota, int nnb){

        QPalette pal = palette();
        QColor* color;
        switch (nnb % 5){
        case 0:
            color = new QColor(200, 50, 150, 150);
            break;
        case 1:
            color = new QColor(130, 80, 250, 150);
            break;
        case 2:
            color = new QColor(20, 200, 150, 150);
            break;
        case 3:
            color = new QColor(200, 10, 50, 150);
            break;
        case 4:
            color = new QColor(20, 200, 250, 150);
            break;
        default:
            color = new QColor(20, 200, 250, 150);
            break;
        }

        // set white background
        pal.setColor(QPalette::Background, *color);
        nota->setAutoFillBackground(true);
        nota->setPalette(pal);

        vLayout->addWidget(nota);
        vLayout->setSpacing(2);
    }

    //public:
    QLabel * n;
    int number;
    int month;
    int calendarLine;
    int calendarColumn; // day of week
    QVBoxLayout *vLayout;
    // vector des cours
};

#endif // DAY_H
