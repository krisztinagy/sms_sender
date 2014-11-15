#include "messageclass.h"

QString MessageClass::SelectedMess="";

MessageClass::MessageClass(QString Id, QString MessageText)
{
    this->Id=Id;
    this->MessageText=MessageText;

}
MessageClass::MessageClass()
{
    this->Id="";
    this->MessageText="";
}

MessageClass::~MessageClass()
{
}
