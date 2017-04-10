#include "note.h"

QDataStream &operator<<(QDataStream & stream, const Note &note)
{
    return stream << note.content << note.keyword;
}


QDataStream &operator>>(QDataStream & stream, Note &note)
{
    return stream >> note.content >> note.keyword;
}
