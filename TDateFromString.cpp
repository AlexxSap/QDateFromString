#include "TDateFromString.h"

TDateFromString::TDateFromString(QObject *parent) : QObject(parent)
{

}

void TDateFromString::TestFromString()
{
    QFETCH(QString, str);
    QFETCH(QDate, expRes);

    QDate actResSplit = DateFromString::bySplit(str);
    QCOMPARE(actResSplit, expRes);

    QDate actResQChar = DateFromString::byQChar(str);
    QCOMPARE(actResQChar, expRes);

    QDate actResStdString = DateFromString::byStdString(str);
    QCOMPARE(actResStdString, expRes);

}
void TDateFromString::TestFromString_data()
{
    QTest::addColumn<QString>("str");
    QTest::addColumn<QDate>("expRes");

    QTest::newRow("") << QString("2015.11.02")
                      << QDate(2015, 11, 2);

    QTest::newRow("") << QString("2012.01.02")
                      << QDate(2012, 01, 2);
}
