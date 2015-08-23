#ifndef TQDATEFROMSTRING_H
#define TQDATEFROMSTRING_H

#include <QObject>
#include <QString>
#include <QTEst>

#include "DateFromString.h"

class TDateFromString : public QObject
{
    Q_OBJECT
public:
    explicit TDateFromString(QObject *parent = 0);

private slots:
    void TestFromString();
    void TestFromString_data();
};

#endif // TQDATEFROMSTRING_H
