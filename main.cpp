#include <QCoreApplication>
#include <QDate>
#include <QString>
#include <QElapsedTimer>
#include <QDebug>
#include <QTest>

#include "TDateFromString.h"
#include "DateFromString.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    int test = 0;
    TDateFromString tester;
    test = QTest::qExec(&tester);
    if(test != 0)
    {
        return test;
    }

    QElapsedTimer timer;

    QStringList lst;
    QString format("yyyy.MM.dd");
    for(QDate d = QDate(2010, 1, 1); d <= QDate(2015, 12, 31); d = d.addDays(1))
    {
        lst.append(d.toString(format));
    }

    timer.start();
    foreach (const QString str, lst)
    {
        QDate d = QDate::fromString(str, format);
        Q_UNUSED(d)

    }
    qInfo() << "QDate::fromString ---- " << timer.elapsed();

    timer.start();
    foreach (const QString str, lst)
    {
        QDate d = DateFromString::bySplit(str);
        Q_UNUSED(d)
    }
    qInfo() << "bySplit ---- " << timer.elapsed();

    timer.start();
    foreach (const QString str, lst)
    {
        QDate d = DateFromString::byQChar(str);
        Q_UNUSED(d)
    }
    qInfo() << "byChar ---- " << timer.elapsed();

    timer.start();
    foreach (const QString str, lst)
    {
        QDate d = DateFromString::byStdString(str);
        Q_UNUSED(d)
    }
    qInfo() << "byStdString ---- " << timer.elapsed();

    return 0;
}
