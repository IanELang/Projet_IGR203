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
    Page a2("America", QDate(2017, 4, 11));
    a2.notes.push_back(Note("Most thunder strikes per year", "Brazil"));
    a2.notes.push_back(Note("Country that crosses the most meridians", "Chile"));
    a2.notes.push_back(Note("Has the andes", "Peru"));
    a.pages.push_back(a2);
    ntbks.push_back(a);


    Notebook c("IGR 203");
    Page c1("Perception/Action: Ce cours a presente des formules et techniques pour evaluer comment l'utilisateur peut percevoir et agir dans une IHM", QDate(2017, 4, 4));
    c1.notes.push_back(Note("C'est une loi empirique selon lequelle le temps de pointage est proportionel a a + b * log(D/W + 1)", "Loi de Fitts"));
    c1.notes.push_back(Note("G. A. Miller a identifie que le nombre de valeurs que une personne peut distinguer de maniere absolute est aprox. egal a 2 a 3 bits", "Le nombre magique"));
    c1.notes.push_back(Note("Un modele additif dans lequel une coleur est codee comme la somme d'un valeur rouge, un vert et un bleu", "Modeles RGB"));
    c1.notes.push_back(Note("C'est un modele descriptif du comportement, considere diverses niveaux d'abstraction (de la tache a l'action physique). Ses deux axes sont l'analyse de la tache et la prediction du comportement du utilisateur.", "GOMS"));
    c1.notes.push_back(Note("La retinne a 7 millions de cones (R,G,B) et 75 a 150 millons de batonnets (niveaux de gris). Il faut tenir compte de que l'oeil est 10 fois plus sensible a de variations de luminance que de Teinte", "Sensibilite de la retinne"));
    c.pages.push_back(c1);
    Page c2("Qt graphique avance", QDate(2017, 4, 6));
    c2.notes.push_back(Note("Sont une facon natural de modeliser le comportement d'une application ,evitant le spaghetti de callbacks et de variables d'etat", "Machines a etats"));
    c2.notes.push_back(Note("La machine a etat ne doit pas bloquer la operation du boucle de gestion, c'est preferable d'employer outils comme les statecharts de qt pour les compatibiliser' ", "Compatibilisation avec GUI"));
    c2.notes.push_back(Note("Peuvent etre utilisees pour declencher transitions programatiquement", "User Events"));
    c2.notes.push_back(Note("Qt a un repertoire de gestes predefinis (panGesture, pinchGesture, grabGesture). En sous-classant QGesture et QGestureRecognizer, on peut creer des nouveaux gestes et les reconnaitre.", "Interaction gestuelle"));
    c.pages.push_back(c2);
    Page c3("Techniques emergentes", QDate(2017, 4, 14));
    c3.notes.push_back(Note("AR glasses, projection mapping", "Realite augmente"));
    c3.notes.push_back(Note("ARToolkit, MagicCube", "Interfaces tangibles"));
    c3.notes.push_back(Note("Morphees, Haptic Edge", "Shape-changing interfaces"));
    c3.notes.push_back(Note("Occultation et precision insufissante dans la interaction avec le doigt. Shift, TapTap... pour resoudre", "Fat finger problem"));
    c3.notes.push_back(Note("", "Bezels"));
    c3.notes.push_back(Note("", "Menus gestuels"));
    c3.notes.push_back(Note("", "Grands ecrans"));
    c.pages.push_back(c3);
    Page c4("Conception centree utilisateur IHM", QDate(2017, 4, 18));
    c4.notes.push_back(Note("Une IHM est sujete a des contraintes Humains, technologiques et de tache", "Contraintes d'une IHM"));
    c4.notes.push_back(Note("Collecte, organization et representation de donnes", "Comprendre l'utilisateur"));
    c.pages.push_back(c4);
    ntbks.push_back(c);

    QFile file("file.ntb");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << ntbks;

    ntbks.clear();

    Notebook b("IGR 202");
    Page b1("Synthese d'images: c'est le processus", QDate(2017, 4, 3));
    b1.notes.push_back(Note("C'est la simulation du transport de la lumiere, de la source au capteur dans une scene virtuel", "Rendu base physique"));
    b1.notes.push_back(Note("Dans les systemes interactifs, on calcule une approximation geometrique et radiometrique de la scene avec la GPU", "Rendu temps-reel"));
    b1.notes.push_back(Note("La scene 3d est une collection de modeles: de capteur, de geometrie, de apparence, de lumieres...", "Modeles de scenes 3d"));
    b1.notes.push_back(Note("La maillage est le modele geometrique dominant en rendu, et est definie par un ensemble de faces polygonales F indexant des sommets V", "Surface maillee"));
    b.pages.push_back(b1);
    Page b2("Visibilite: ce cours a discute plusiers techniques utilisees dans la determination du ensemble de primitives visibles/cachees depuis un point donne", QDate(2017, 4, 17));
    b2.notes.push_back(Note("C'est la discratisation d'un polygone dans une grille. L'elimination ", "Rasterisation"));
    b2.notes.push_back(Note("Elimine les polygones hors du champ de vision", "Frustrum culling"));
    b2.notes.push_back(Note("Ordonnancement général des polygones le long de l’axe de vue, dessin de loin en proche de la liste ordonnée", "Algorithme du peintre"));
    b2.notes.push_back(Note("Mantenir un tampon de la meme taille que le tampon coleur de l'ecran, mas stockant pour chaque pixel la porfondeur de la geometrie recouvrant", "Z-Buffer"));
    b.pages.push_back(b2);
    ntbks.push_back(b);

    QFile fileB("import.ntb");
    fileB.open(QIODevice::WriteOnly);
    QDataStream outB(&fileB);
    outB << ntbks;

    return;
}
