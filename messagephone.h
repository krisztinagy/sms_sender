#ifndef MESSAGEPHONE_H
#define MESSAGEPHONE_H

#include <QString>
class messagephone
{
public:
    messagephone();
    messagephone(QString Message, QString Phone);

    static messagephone SelectedMessagePhone;
    QString Phone;
    QString Message;
};

#endif // MESSAGEPHONE_H
