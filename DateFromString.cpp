#include "DateFromString.h"

QDate DateFromString::bySplit(const QString &str)
{
    QStringList lst = str.split(".");
    return QDate(lst.at(0).toInt(), lst.at(1).toInt(), lst.at(2).toInt());
}

QDate DateFromString::byQChar(const QString &str)
{
    QString year;
    year += str[0];
    year += str[1];
    year += str[2];
    year += str[3];
    QString month;
    month += str[5];
    month += str[6];
    QString day;
    day += str[8];
    day += str[9];

    return QDate(year.toInt(), month.toInt(), day.toInt());
}

QDate DateFromString::byStdString(const QString &str)
{
    const char *s = str.toStdString().c_str();

    const std::string year(s,4);

    s = s + 5;
    const std::string month(s,2);

    s = s + 3;
    const std::string day(s,2);
    return QDate(atoi(year.c_str()), atoi(month.c_str()), atoi(day.c_str()));
}
