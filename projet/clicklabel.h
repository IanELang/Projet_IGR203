#ifndef CLICKLABEL_H
#define CLICKLABEL_H

#include <QLabel>
#include <QGraphicsOpacityEffect>


class clickLabel : public QLabel
{
    Q_OBJECT
public:
    explicit clickLabel( const QString& text, QWidget* parent);
    clickLabel( const QString& text="", int n_Page=0, int n_Notebook=0);
    clickLabel( int n_Page, int n_Notebook);

    void enterEvent(QEvent *ev) override;

    void leaveEvent(QEvent *ev) override;

    ~clickLabel();
signals:
    void clicked(int i, int j);
    void hover();
protected:
    void mousePressEvent(QMouseEvent* event) override;

private:
    QGraphicsOpacityEffect * dse;
    int pageNumber;
    int notebookNumber;

};

#endif // CLICKLABEL_H
