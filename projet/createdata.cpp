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
    Page b1("Synthese d'images: c'est le processus", QDate(2017, 4, 1));
    b1.notes.push_back(Note("C'est la simulation du transport de la lumiere, de la source au capteur dans une scene virtuel", "Rendu base physique"));
    b1.notes.push_back(Note("Dans les systemes interactifs, on calcule une approximation geometrique et radiometrique de la scene avec la GPU", "Rendu temps-reel"));
    b1.notes.push_back(Note("La scene 3d est une collection de modeles: de capteur, de geometrie, de apparence, de lumieres...", "Modeles de scenes 3d"));
    b1.notes.push_back(Note("La maillage est le modele geometrique dominant en rendu, et est definie par un ensemble de faces polygonales F indexant des sommets V", "Surface maillee"));
    b.pages.push_back(b1);
    Page b2("Visibilite: ce cours a discute plusiers techniques utilisees dans la determination du ensemble de primitives visibles/cachees depuis un point donne", QDate(2017, 8, 3));
    b2.notes.push_back(Note("C'est la discratisation d'un polygone dans une grille. L'elimination ", "Rasterisation"));
    b2.notes.push_back(Note("Elimine les polygones hors du champ de vision", "Frustrum culling"));
    b2.notes.push_back(Note("Ordonnancement général des polygones le long de l’axe de vue, dessin de loin en proche de la liste ordonnée", "Algorithme du peintre"));
    b2.notes.push_back(Note("Mantenir un tampon de la meme taille que le tampon coleur de l'ecran, mas stockant pour chaque pixel la porfondeur de la geometrie recouvrant", "Z-Buffer"));
    b.pages.push_back(b2);
    ntbks.push_back(b);

    QFile file("file.xxx");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    //out << "abcdef";
    out << ntbks;
    return;
}
