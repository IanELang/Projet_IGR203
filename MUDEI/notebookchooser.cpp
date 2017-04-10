#include "notebookchooser.h"

NotebookChooser::NotebookChooser(QVector<Notebook> notebooks, QWidget *parent) :
    QWidget(parent)
{
    //this->setStyleSheet("background-color:lightblue;");

    this->setMinimumWidth(870);
    this->setMinimumHeight(600);


    this->notebooks = notebooks;

    QSpacerItem* hspacer = new QSpacerItem( 0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed );
    QSpacerItem* vspacer = new QSpacerItem( 0, 0, QSizePolicy::Fixed, QSizePolicy::Expanding );

    ncols = 4;

    QHBoxLayout* global = new QHBoxLayout(this);

    QVBoxLayout* sideBar = new QVBoxLayout();
    QVBoxLayout* mainBar = new QVBoxLayout();
    notebookGrid = new QGridLayout();

    global->addLayout(sideBar);
    global->addLayout(mainBar);


// nao sei se a tab vai funcionar bem
//    QPushButton *calendarButton = new QPushButton(this);
//    calendarButton->setText(tr("see calendar"));
//    connect(calendarButton, SIGNAL(clicked( )), this->parent(), SLOT(openCalendar( )));
//    mainBar->addWidget(calendarButton, Qt::AlignVCenter);

    notebookGrid->setHorizontalSpacing(20);
    notebookGrid->setVerticalSpacing(20);

    QWidget* client = new QWidget();
    client->setLayout(notebookGrid);
    QScrollArea* scroll = new QScrollArea();
    scroll->setWidgetResizable(true);
    scroll->setWidget(client);
    mainBar->addWidget(scroll);

    QLabel* userLabel = new QLabel;
    QPixmap userLogo(":/Resources/user.png");
    QPixmap userLogoScaled = userLogo.scaled(QSize(100,100),  Qt::KeepAspectRatio);
    userLabel->setPixmap(userLogoScaled);
    userLabel->setAlignment(Qt::AlignCenter);
    userLabel->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

    sideBar->addWidget(userLabel, Qt::AlignVCenter);

    QPushButton *importButton = new QPushButton(this);
    importButton->setText(tr("Import notes"));
    connect(importButton, SIGNAL(clicked( )), this, SLOT(importNotebooks( )));
    importButton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    sideBar->addWidget(importButton, Qt::AlignVCenter);

    QPushButton *exportButton = new QPushButton(this);
    exportButton->setText(tr("Export notes"));
    connect(exportButton, SIGNAL(clicked( )), this, SLOT(exportNotebooks( )));
    exportButton->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    sideBar->addWidget(exportButton, Qt::AlignVCenter);

    sideBar->addItem(vspacer);

    addNotebooksToGrid();
}

void NotebookChooser::addNotebooksToGrid()
{

    remove(notebookGrid, true);

    newNoteMapper = new QSignalMapper(this);
    connect(newNoteMapper, SIGNAL(mapped(int)), this, SLOT(newNote(int)));

    reviewNoteMapper = new QSignalMapper(this);
    connect(reviewNoteMapper, SIGNAL(mapped(int)), this, SLOT(reviewNotes(int)));

    for(int i = 0; i < notebooks.size(); i++)
    {
        //notebookGrid->addWidget(new QPushButton(notebooks.at(i).name),i%2,i/2);

        QLabel* noteRepr = new QLabel;
        QPixmap noteBack(":/Resources/note_alpha.png");
        QPixmap noteBackScaled = noteBack.scaled(QSize(500,500),  Qt::KeepAspectRatio);
        noteRepr->setPixmap(noteBackScaled);
        noteRepr->setScaledContents( true );
        noteRepr->setAlignment(Qt::AlignCenter);
        QSizePolicy sizePol = QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        noteRepr->setMinimumWidth(100);
        noteRepr->setMinimumHeight(120);
        noteRepr->setMaximumWidth(200);
        noteRepr->setMaximumHeight(240);
        noteRepr->setSizePolicy(sizePol);
        QVBoxLayout* notebookLayout = new QVBoxLayout();

        QLabel* title = new QLabel(notebooks.at(i).name);
        title->setAlignment(Qt::AlignCenter);

        QPushButton* newButton = new QPushButton("new");
        connect(newButton, SIGNAL(clicked()), newNoteMapper, SLOT(map()));
        newNoteMapper->setMapping(newButton, i);

        QPushButton* reviewButton = new QPushButton("review");
        connect(reviewButton, SIGNAL(clicked()), reviewNoteMapper, SLOT(map()));
        reviewNoteMapper->setMapping(reviewButton, i);

        notebookLayout->addWidget(title);
        notebookLayout->addWidget(newButton);
        notebookLayout->addWidget(reviewButton);

        noteRepr->setLayout(notebookLayout);
        notebookGrid->addWidget(noteRepr,i/ncols,i%ncols);
    }

    QPushButton* addNotebook = new QPushButton("Add notebook");
    addNotebook->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    notebookGrid->addWidget(addNotebook,notebooks.size()/ncols,notebooks.size()%ncols);
    connect(addNotebook, SIGNAL(clicked( )), this, SLOT(addNotebook( )));
}

// http://stackoverflow.com/questions/5395266/removing-widgets-from-qgridlayout
void NotebookChooser::remove(QGridLayout *layout, bool deleteWidgets) {
    // We avoid usage of QGridLayout::itemAtPosition() here to improve performance.
    for (int i = layout->count() - 1; i >= 0; i--) {
        QLayoutItem *item = layout->takeAt(i);
        if (deleteWidgets) {
            deleteChildWidgets(item);
        }
        delete item;
    }
}

// http://stackoverflow.com/questions/5395266/removing-widgets-from-qgridlayout
void NotebookChooser::deleteChildWidgets(QLayoutItem *item) {
    if (item->layout()) {
        // Process all child items recursively.
        for (int i = 0; i < item->layout()->count(); i++) {
            deleteChildWidgets(item->layout()->itemAt(i));
        }
    }
    delete item->widget();
}

void NotebookChooser::importNotebooks()
{
    QString notesPath = QDir::currentPath() + QString("/notebooks/");

    if (!QDir(notesPath).exists()) {
        QDir(notesPath).mkpath(".");
    }

    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Import file:"), notesPath, tr("Notebook Files (*.ntb)"));

    // http://doc.qt.io/qt-5/qtwidgets-tutorials-addressbook-part6-example.html
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }

    QDataStream in(&file);
    notebooks.clear();   // clear existing contacts
    in >> notebooks;

    addNotebooksToGrid();
}

void NotebookChooser::exportNotebooks()
{

    if(notebooks.size() == 0)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","You have no notebooks to export !");
        messageBox.setFixedSize(500,200);
        return;
    }

    QString notesPath = QDir::currentPath() + QString("/notebooks/");

    if (!QDir(notesPath).exists()) {
        QDir(notesPath).mkpath(".");
    }

    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Export to:"), notesPath, tr("Notebook Files (*.ntb)"));

    if(!fileName.endsWith(".ntb"))
    {
        fileName.append(".ntb");
    }

    QFile file( fileName );

    if ( file.open(QIODevice::ReadWrite) )
    {
        QDataStream out( &file );
        out << notebooks;
    }

}

void NotebookChooser::newNote(int ntbNum)
{
    // abre interface de editar nota do notebook especifico
    std::cout << "add note to: " << notebooks.at(ntbNum).name.toStdString() << std::endl;
}


void NotebookChooser::reviewNotes(int ntbNum)
{
    // abre interface de revisar os cadernos
    std::cout << "review: " << notebooks.at(ntbNum).name.toStdString() << std::endl;
}

void NotebookChooser::addNotebook()
{
    bool ok;
    QString name = QInputDialog::getText(this, tr("QInputDialog::getText()"),
                                           tr("New notebook name:"), QLineEdit::Normal,
                                           QDir::home().dirName(), &ok);

    if (ok && !name.isEmpty())
    {
        Notebook* newNote = new Notebook();
        newNote->name = name;

        notebooks.append(*newNote);
    }

    addNotebooksToGrid();

}

void NotebookChooser::resizeEvent(QResizeEvent *event){

    QSize actualSize = event->size();

    ncols = actualSize.width()/200;

    addNotebooksToGrid();
}

NotebookChooser::~NotebookChooser()
{
}
