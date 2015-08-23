#ifndef DATEFROMSTRING_H
#define DATEFROMSTRING_H

#include <QDate>
#include <QDebug>

class DateFromString
{
public:
    static QDate bySplit(const QString &str);
    static QDate byQChar(const QString &str);
    static QDate byStdString(const QString &str);
};

#endif // DATEFROMSTRING_H
