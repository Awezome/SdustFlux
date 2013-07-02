#ifndef DAO_H
#define DAO_H
#include "bean.h"
#include "qtsoap.h"
class dao :public QObject {
    Q_OBJECT
public:
    explicit dao(QObject *parent = 0);
    void setAccount(QString account, QString password);

    UserBean getUser();
    QList<DayBean> getDay();
    QList<BillBean> getBill();
    MonthBean getMonth();
    FlagBean getFlag();
signals:
    void signalUser();
    void signalDay();
    void signalBill();
    void signalMonth();
    void signalFlag();
private:
    QString iaccount;
    QString ipassport;
    QString ipassword;

    UserBean iUserBean;
    QList<DayBean> iDayBean;
    QList<BillBean> iBillBean;
    MonthBean iMonthBean;
    FlagBean iFlagBean;

    QtSoapHttpTransport *soap;

    void setFluxSlot(QString type);
    void setMethod(QString method, QString authCodee);
    void setMethod(QString method);
    void setBean();
private slots:
    void slotPassport();
    void slotFluxUser();
    void slotFluxMonth();
    void slotFluxDay();
    void slotFluxBill();
};

#endif // DAO_H
