#include<QVector>
#include<QFile>
#include<QDataStream>
#include "notebook.h"

void createData()
{
    QVector<Notebook> ntbks;
    Notebook a("IGR 201");
    Page a1("Asian Countries", QDate(2017, 4, 6));
    a1.notes.push_back(Note("Afghanistan, officially the Islamic Republic of Afghanistan, is a landlocked country located within South Asia and Central Asia.[9][10] It has a population of approximately 32 million, making it the 42nd most populous country in the world.", "Afghanistan"));
    a1.notes.push_back(Note("Jordan, is an Arab kingdom in Western Asia, on the East Bank of the Jordan River. Jordan is bordered by Saudi Arabia to the east and south; Iraq to the north-east; Syria to the north; Israel, Palestine and the Dead Sea to the west; and the Red Sea in its extreme south-west.", "Jordan"));
    a1.notes.push_back(Note("Lebanon, is a sovereign state in Western Asia. It is bordered by Syria to the north and east and Israel to the south, while Cyprus is west across the Mediterranean Sea. ", "Lebanon"));
    a1.notes.push_back(Note("Largest country in the world", "Russia"));
    a.pages.push_back(a1);
    Page a2("America", QDate(2017, 4, 26));
    a2.notes.push_back(Note("Most thunder strikes per year", "Brazil"));
    a2.notes.push_back(Note("Country that crosses the most meridians", "Chile"));
    a2.notes.push_back(Note("Has the andes", "Peru"));
    a.pages.push_back(a2);
    ntbks.push_back(a);

    Notebook b("IGR 202");
    Page b1("Marajo", QDate(2017, 4, 1));
    b1.notes.push_back(Note("Brazil", "Location"));
    b1.notes.push_back(Note("Norte", "Region"));
    b.pages.push_back(b1);
    Page b2("Australia", QDate(2017, 8, 3));
    b2.notes.push_back(Note("Oceania", "Location"));
    b2.notes.push_back(Note("Norte", "Region"));
    b.pages.push_back(b2);
    ntbks.push_back(b);

    QFile file("file.xxx");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    //out << "abcdef";
    out << ntbks;
    return;
}
