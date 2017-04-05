#include "page.h"

Page::Page()
{
}

QDataStream &operator<<(QDataStream & stream, const Page &page)
{
    return stream << page.notes << page.creationDate << page.summary;
}


QDataStream &operator>>(QDataStream & stream, Page &page)
{
    return stream >> page.notes >> page.creationDate >> page.summary;
}
