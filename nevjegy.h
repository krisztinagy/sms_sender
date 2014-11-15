#ifndef NEVJEGY_H
#define NEVJEGY_H

#include <QDialog>

namespace Ui {
class nevjegy;
}

class nevjegy : public QDialog
{
    Q_OBJECT
    
public:
    explicit nevjegy(QWidget *parent = 0);
    ~nevjegy();
    
private:
    Ui::nevjegy *ui;
};

#endif // NEVJEGY_H
