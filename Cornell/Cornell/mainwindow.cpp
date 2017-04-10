#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QWidget * container = new QWidget();
    container->setStyleSheet("background-color:white;");
    this->setCentralWidget(container);

    QHBoxLayout* global = new QHBoxLayout(container);

    QVBoxLayout* sideBar = new QVBoxLayout();
    QVBoxLayout* mainBar = new QVBoxLayout();
    notebookGrid = new QGridLayout();

    global->addLayout(sideBar);
    global->addLayout(mainBar);


    QPushButton *calendarButton = new QPushButton(this);
    calendarButton->setText(tr("See calendar"));
    connect(calendarButton, SIGNAL(clicked( )), this, SLOT(openCalendar( )));
    mainBar->addWidget(calendarButton, Qt::AlignVCenter);

    mainBar->addLayout(notebookGrid);

    QLabel* userLabel = new QLabel;
    QPixmap userLogo(":/Resources/user.png");
    QPixmap userLogoScaled = userLogo.scaled(QSize(100,100),  Qt::KeepAspectRatio);
    userLabel->setPixmap(userLogoScaled);
    //userLabel->setScaledContents( true );
    userLabel->setAlignment(Qt::AlignCenter);
    sideBar->addWidget(userLabel);

    QPushButton *importButton = new QPushButton(this);
    importButton->setText(tr("Import notes"));
    connect(importButton, SIGNAL(clicked( )), this, SLOT(importNotebooks( )));
    sideBar->addWidget(importButton, Qt::AlignVCenter);

    QPushButton *exportButton = new QPushButton(this);
    exportButton->setText(tr("Export notes"));
    connect(exportButton, SIGNAL(clicked( )), this, SLOT(exportNotebooks( )));
    sideBar->addWidget(exportButton, Qt::AlignVCenter);

    addNotebooksToGrid();
}

void MainWindow::addNotebooksToGrid()
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
        QPixmap noteBack(":/Resources/note.png");
        QPixmap noteBackScaled = noteBack.scaled(QSize(100,200),  Qt::KeepAspectRatio);
        noteRepr->setPixmap(noteBackScaled);
        noteRepr->setScaledContents( true );
        noteRepr->setAlignment(Qt::AlignCenter);
        noteRepr->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Preferred );

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
        notebookGrid->addWidget(noteRepr,i/2,i%2);
    }

    QPushButton* addNotebook = new QPushButton("Add notebook");
    notebookGrid->addWidget(addNotebook,notebooks.size()/2,notebooks.size()%2);
    connect(addNotebook, SIGNAL(clicked( )), this, SLOT(addNotebook( )));
}

// http://stackoverflow.com/questions/5395266/removing-widgets-from-qgridlayout
void MainWindow::remove(QGridLayout *layout, bool deleteWidgets) {
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
void MainWindow::deleteChildWidgets(QLayoutItem *item) {
    if (item->layout()) {
        // Process all child items recursively.
        for (int i = 0; i < item->layout()->count(); i++) {
            deleteChildWidgets(item->layout()->itemAt(i));
        }
    }
    delete item->widget();
}

void MainWindow::importNotebooks()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Import file:"), "/home", tr("Notebook Files (*.ntb)"));

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

void MainWindow::exportNotebooks()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Export to:"), "/home", tr("Notebook Files (*.ntb)"));

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

void MainWindow::openCalendar()
{
    // abre interface de revisar os cadernos
    std::cout << "opening calendar..." << std::endl;
}

void MainWindow::newNote(int ntbNum)
{
    // abre interface de editar nota do notebook especifico
    std::cout << "add note to: " << notebooks.at(ntbNum).name.toStdString() << std::endl;
}


void MainWindow::reviewNotes(int ntbNum)
{
    // abre interface de revisar os cadernos
    std::cout << "review: " << notebooks.at(ntbNum).name.toStdString() << std::endl;
}

void MainWindow::addNotebook()
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

MainWindow::~MainWindow()
{
    delete ui;
}