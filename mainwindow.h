#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addText();

private:
    Ui::MainWindow *ui;

    QHBoxLayout* hLayout = new QHBoxLayout();
    QWidget * container = new QWidget();
    QVBoxLayout* vLayout = new QVBoxLayout(container);
};

#endif // MAINWINDOW_H
