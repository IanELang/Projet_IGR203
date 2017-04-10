#include "page.h"

QDataStream &operator<<(QDataStream & stream, const Page &page)
{
    return stream << page.notes << page.creationDate << page.summary << page.title;
}


QDataStream &operator>>(QDataStream & stream, Page &page)
{
    return stream >> page.notes >> page.creationDate >> page.summary >> page.title;
}
