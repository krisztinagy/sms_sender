#include "portset.h"
#include "ui_portset.h"

portset::portset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::portset)
{
    ui->setupUi(this);
}

portset::~portset()
{
    delete ui;
}

QString portset::getPort()
{
    return ui->Port->text();
}
