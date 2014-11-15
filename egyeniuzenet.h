#ifndef egyeniuzenet_H
#define egyeniuzenet_H

#include <QDialog>
#include "messageclass.h"

namespace Ui {
class egyeniuzenet;
}

class egyeniuzenet : public QDialog
{
    Q_OBJECT
    
public:
    explicit egyeniuzenet(const QVector<MessageClass>& mess, QWidget *parent = 0);
    ~egyeniuzenet();

    //fuggveny, ami visszaadja az erteket
    QString getMess();
    
private:
    Ui::egyeniuzenet *ui;
};

#endif
