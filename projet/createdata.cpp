#include<QVector>
#include<QFile>
#include<QDataStream>
#include "notebook.h"

void createData()
{
    QVector<Notebook> ntbks;
    Notebook a("IGR 201");
    Page a1("Qt", QDate(2017, 4, 6));
    a1.notes.push_back(Note("", "Signals and slots"));
    a1.notes.push_back(Note("", "Layouts"));
    a.pages.push_back(a1);
    Page a2("Web", QDate(2017, 4, 11));
    a2.notes.push_back(Note("", "HTML"));
    a2.notes.push_back(Note("", "Javascript"));
    a2.notes.push_back(Note("", "CSS"));
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
    c3.notes.push_back(Note("Examples: AR glasses, projection mapping", "Realite augmente"));
    c3.notes.push_back(Note("Examples: ARToolkit, MagicCube", "Interfaces tangibles"));
    c3.notes.push_back(Note("Examples: Morphees, Haptic Edge", "Shape-changing interfaces"));
    c3.notes.push_back(Note("Examples: Occultation et precision insufissante dans la interaction avec le doigt. Shift, TapTap... pour resoudre", "Fat finger problem"));
    c3.notes.push_back(Note("Examples: BezelSwipe, BezelTap", "Bezels"));
    c3.notes.push_back(Note("Examples: Wavelet menus, MicroRolls", "Menus gestuels"));
    c3.notes.push_back(Note("Examples: Frustrated Total Internal Reflection", "Grands ecrans"));
    c.pages.push_back(c3);
    Page c4("Conception centree utilisateur IHM", QDate(2017, 4, 18));
    c4.notes.push_back(Note("Une IHM est sujete a des contraintes Humains, technologiques et de tache", "Contraintes d'une IHM"));
    c4.notes.push_back(Note("Pour comprendre l'utilisateur if faut collecter, organiser et representer des donnes", "Comprendre l'utilisateur"));
    c4.notes.push_back(Note("Technique utile pour la analyse qualitative des donnees. On ecrit les observations dans un papier et le met dans un mur. On met ensemble de itens qui ont une affinite", "Affinity Diagram"));
    c4.notes.push_back(Note("Pour comprendre l'utilisateur if faut collecter, organiser et representer des donnes", "Comprendre l'utilisateur"));
    c4.notes.push_back(Note("Attributes: attitude, motivation, niveau de lecture, education...", "Profils d'utilisateur"));
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
