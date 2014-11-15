#include "egyeniuzenet.h"
#include "ui_egyeniuzenet.h"

egyeniuzenet::egyeniuzenet(const QVector<MessageClass>& mess, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::egyeniuzenet)
{
    ui->setupUi(this);

    //ki kell tölteni a combobox-ot
    for(int i=0; i<mess.size(); ++i)
    {
        ui->uzenet->addItem(mess.at(i).Id);
    }

}

egyeniuzenet::~egyeniuzenet()
{
    delete ui;
}

QString egyeniuzenet::getMess()
{
    return ui->uzenet->currentText();
}
