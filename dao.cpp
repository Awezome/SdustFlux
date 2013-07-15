#include "dao.h"
#include <QObject>
#include <QXmlStreamReader>
dao::dao(QObject *parent) : QObject(parent){
    iFlagBean.link=false;
}

void dao::setAccount(QString account, QString password){
    iaccount=account;
    ipassword=password;
    soap = new QtSoapHttpTransport();
    connect(soap, SIGNAL(responseReady()), this, SLOT(slotPassport()));
    setMethod("GetPassport",ipassword);
}

void dao::slotPassport() {
    setBean();
    emit signalFlag();
    if(iFlagBean.link && iFlagBean.flag){
        setFluxSlot("user");
    }
}

void dao::setFluxSlot(QString type) {
    soap = new QtSoapHttpTransport();
    if(type=="user"){
        connect(soap, SIGNAL(responseReady()), this, SLOT(slotFluxUser()));
        setMethod("GetUserInfo");
    }else if(type=="bill"){
        connect(soap, SIGNAL(responseReady()), this, SLOT(slotFluxBill()));
        setMethod("GetBillInfo");
    }else if(type=="month"){
        connect(soap, SIGNAL(responseReady()), this, SLOT(slotFluxMonth()));
        setMethod("CurrentMonthFlux");
    }else if(type=="day"){
        connect(soap, SIGNAL(responseReady()), this, SLOT(slotFluxDay()));
        setMethod("GetDayFlux");
    }else{}
}

void dao::slotFluxUser() {
    setBean();
    emit signalUser();
    setFluxSlot("month");
}

void dao::slotFluxMonth() {
    setBean();
    emit signalMonth();
    setFluxSlot("day");
}

void dao::slotFluxDay() {
    setBean();
    emit signalDay();
    //setFluxSlot("bill");
}

void dao::slotFluxBill() {
    setBean();
    emit signalBill();
}

void dao::setBean(){
    const QtSoapMessage &message = soap->getResponse();

    if(!message.isFault()){
        iFlagBean.link=true;
        QXmlStreamReader *xml = new QXmlStreamReader(message.toXmlString());

        while (!xml->atEnd()){
            xml->readNextStartElement();
            if(xml->name() == "GetUserInfoResult"){
                while (!xml->atEnd()){
                    xml->readNextStartElement();
                    if( xml->name() == "UserInfo") {
                        UserBean userBean;
                        while(!xml->atEnd()) {
                            xml->readNextStartElement();
                            if(xml->name() == "Account")       userBean.account=xml->readElementText();
                            else if(xml->name() == "RealName") userBean.realName=xml->readElementText();
                            else if(xml->name() == "GroupName")  userBean.groupName=xml->readElementText();
                            else if(xml->name() == "BaseFee")  userBean.baseFee=xml->readElementText().toFloat();
                            else if(xml->name() == "BaseFlux")  userBean.baseFlux=xml->readElementText().toFloat();
                            else if(xml->name() == "PricePerMB")  userBean.pricePerMB=xml->readElementText().toFloat();
                            else if(xml->name() == "OnLineIP")  userBean.onLineIP=xml->readElementText();
                            else if(xml->name() == "DeviceMAC")  userBean.deviceMAC=xml->readElementText();
                            else if(xml->name() == "Credit")  userBean.credit=xml->readElementText().toFloat();
                            else if(xml->name() == "Status")  userBean.status=xml->readElementText().toUpper() == "TRUE"? true : false;
                            else if(xml->name() == "FirstLogonDate")  userBean.firstLogonDate=QDateTime::fromString(xml->readElementText(), Qt::ISODate);
                            else if(xml->name() == "PeriodStartDate")  userBean.periodStartDate=QDateTime::fromString(xml->readElementText(), Qt::ISODate);
                        }
                       iUserBean = userBean;
                    }
                }
            }else if(xml->name() == "CurrentMonthFluxResult"){
                int i = 0;
                int temp[3];
                while(!xml->atEnd()){
                    xml->readNextStartElement();
                    if(xml->name()=="int") temp[i++] = xml->readElementText().toInt();
                }
                iMonthBean.total=temp[0];
                iMonthBean.used=temp[1];
                iMonthBean.download=temp[2];
               // qDebug()<<iMonthBean.download;
            }else if(xml->name() == "GetDayFluxResult"){
                iDayBean.clear();
                while(!xml->atEnd()){
                    xml->readNextStartElement();
                    if(xml->name() == "BillInfo") {
                        DayBean dayBean;
                        while(!xml->atEnd()) {
                            xml->readNextStartElement();
                            if(xml->name() == "LogDate") dayBean.logDate = xml->readElementText();
                            else if(xml->name() == "TotalFlux") dayBean.totalFlux = xml->readElementText().toFloat();
                            else if(xml->name() == "DownloadFlux") dayBean.downloadFlux = xml->readElementText().toFloat();
                            if(dayBean.downloadFlux!=0){
                                iDayBean.append(dayBean);
                                dayBean.downloadFlux=0;
                            }
                        }
                    }
                }
            }else if(xml->name() == "GetBillInfoResult"){
                while(!xml->atEnd()) {
                    xml->readNextStartElement();
                    if( xml->name() == "BillInfo"){
                        DayBean dayBean;
                        while(!xml->atEnd()) {
                            xml->readNextStartElement();
                            if(xml->name() == "LogDate") dayBean.logDate = xml->readElementText();
                            else if(xml->name() == "TotalFlux") dayBean.totalFlux = xml->readElementText().toFloat();
                            else if(xml->name() == "DownloadFlux") dayBean.downloadFlux = xml->readElementText().toFloat();
                        }
                        iDayBean.append(dayBean);
                    }
                }
            }else if(xml->name() == "GetChargeInfoResult"){

            }else if(xml->name() == "GetPassportResult"){
                ipassport=xml->readElementText();
                while(!xml->atEnd()) {
                    xml->readNextStartElement();
                    if(xml->name() == "Flag") iFlagBean.flag=xml->readElementText().toUpper()== "TRUE"? true : false;
                    else if(xml->name() == "Errmessage") iFlagBean.message = xml->readElementText();
                    else if(xml->name() == "URL") iFlagBean.url = xml->readElementText();
                }
            }else{}
        }
    }else{
        iFlagBean.link=false;
    }
}

void dao::setMethod(QString method) {
    this->setMethod(method,ipassport);
}

void dao::setMethod(QString method, QString authCodee) {
    QtSoapMessage request;
    request.setMethod(method, "http://public.qdkt.net.cn/public");
    request.addMethodArgument("Account", "", iaccount);
    if(method=="GetPassport")
        request.addMethodArgument("Password", "",authCodee);
    else
        request.addMethodArgument("AuthCode", "", authCodee);
    request.addMethodArgument("Flag", "true", true);
    request.addMethodArgument("Errmessage", "", "1");
    soap->setHost("10.200.255.0", 8080);
    soap->setAction("http://public.qdkt.net.cn/public/" + method);
    soap->submitRequest(request, "/public/pub.asmx");
}

UserBean dao::getUser(){
    return iUserBean;
}

QList<DayBean> dao::getDay(){
    return iDayBean;
}

QList<BillBean> dao::getBill(){
    return iBillBean;
}

MonthBean dao::getMonth(){
    return iMonthBean;
}
FlagBean dao::getFlag(){
    return iFlagBean;
}
