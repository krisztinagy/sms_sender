#include "nevjegy.h"
#include "ui_nevjegy.h"

nevjegy::nevjegy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nevjegy)
{
    ui->setupUi(this);
}

nevjegy::~nevjegy()
{
    delete ui;
}
