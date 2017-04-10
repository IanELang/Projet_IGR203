#include "notebook.h"

Notebook::Notebook()
{
}

QDataStream &operator<<(QDataStream & stream, const Notebook &notebook)
{
    return stream << notebook.pages << notebook.name;
}


QDataStream &operator>>(QDataStream & stream, Notebook &notebook)
{
    return stream >> notebook.pages >> notebook.name;
}
