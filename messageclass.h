#ifndef MESSAGECLASS_H
#define MESSAGECLASS_H

#include <QString>

class MessageClass
{
public:
    MessageClass(QString Id, QString MessageText);
    MessageClass();
    ~MessageClass();

    static QString SelectedMess;
    QString Id;
    QString MessageText;
};

#endif // MESSAGECLASS_H
