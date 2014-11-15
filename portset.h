#ifndef PORTSET_H
#define PORTSET_H

#include <QDialog>

namespace Ui {
class portset;
}

class portset : public QDialog
{
    Q_OBJECT
    
public:
    explicit portset(QWidget *parent = 0);
    ~portset();
    
    QString getPort();
private:
    Ui::portset *ui;
};

#endif // PORTSET_H
