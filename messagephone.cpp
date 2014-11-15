#include "messagephone.h"
#include <QString>

messagephone messagephone::SelectedMessagePhone;

messagephone::messagephone()
{
    this->Message="";
    this->Phone="";
}

messagephone::messagephone(QString Message, QString Phone)
{
    this->Message=Message;
    this->Phone=Phone;
}
