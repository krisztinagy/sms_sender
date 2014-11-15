#include "contactclass.h"

QString ContactClass::SelectedPhoneNumber="";
QString ContactClass::SelectedToSend="";

ContactClass::ContactClass(QString Phone, QString Name, QString Address, QString Mail)
{
    this->Name=Name;
    this->Address=Address;
    this->Phone=Phone;
    this->Mail=Mail;
}

ContactClass::ContactClass()
{
    this->Name="";
    this->Address="";
    this->Mail="";
    this->Phone="";
}

ContactClass::~ContactClass()
{

}
