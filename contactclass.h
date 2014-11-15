#ifndef CONTACTCLASS_H
#define CONTACTCLASS_H

#include <QString>

class ContactClass
{
 public:
    //ContactClass(QString Name, QString Address, QString Phone, QString Mail);
    ContactClass(QString Phone, QString Name="", QString Address="", QString Mail="");
    ContactClass();

    ~ContactClass();

    static QString SelectedPhoneNumber;
    static QString SelectedToSend;
    QString Name;
    QString Address;
    QString Phone;
    QString Mail;
};

#endif // CONTACTCLASS_H
