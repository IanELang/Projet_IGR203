#ifndef NOTE_H
#define NOTE_H

#include <QVector>
#include <QString>
#include <QDataStream>

class Note
{
public:
    Note(QString _content = "", QString _keyword = "") : content(_content),
        keyword(_keyword) {}

    friend class MainWindow;
    friend QDataStream &operator<<(QDataStream & stream, const Note &note);
    friend QDataStream &operator>>(QDataStream & stream, Note &note);

    QString content;
    QString keyword;
};

QDataStream &operator<<(QDataStream & stream, const Note &note);
QDataStream &operator>>(QDataStream & stream, Note &note);

#endif // NOTE_H
