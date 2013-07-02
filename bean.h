#ifndef BEAN_H
#define BEAN_H

#include <QtCore>

class UserBean{
public:
    QString account;
    QString realName;
    QString groupName;
    float baseFee;
    float baseFlux;
    float pricePerMB;
    QString onLineIP;
    QString deviceMAC;
    float credit;
    bool status;
    QDateTime firstLogonDate;
    QDateTime periodStartDate;
};

class MonthBean{
public:
    int total;
    int used;
    int download;
};

class DayBean{
public:
    QString logDate;
    float totalFlux;
    float downloadFlux;
};

class BillBean{
public:
    QDateTime billDate;
    QDateTime termFrom;
    QDateTime termTo;
    int totalMinutes;
    float totalFlux;
    float outFlux;
    QString groupName;
    float bill;
    float baseFee;
};

class FlagBean{
public:
    bool flag;
    QString message;
    QString url;
    bool link;
};
#endif // BEAN_H
