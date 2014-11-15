#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serial.h"
#include "nevjegy.h"

#include <QFileDialog>
#include <QTextStream>
#include <QString>
#include <QToolTip>
#include <QObject>
#include <QEvent>

//Open/save
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QVector>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

/*SMS_KULDO*/


//CONSTRUCTOR
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Tooltip letiltasa
    //ui->MainWindow.eventFilter(QObject::findChildren, QEvent::ToolTip);
    //ui->ListAllCont->hi

    //elso tab legyen minden indulaskor
    ui->Tabs->setCurrentIndex(0);


    //Start
    ui->DeleteCont->setDisabled(true);
    ui->UpdateCont->setDisabled(true);
    ui->SaveCont->setEnabled(true);

    ui->DeleteMess->setDisabled(true);
    ui->UpdateMess->setDisabled(true);
    ui->SaveMess->setEnabled(true);

    ui->DeleteFromSend->setDisabled(true);
    ui->DeleteFromSend2->setDisabled(true);


 //connect

    //Menubar
    connect(ui->actionImportContacts,
            SIGNAL(triggered()), this, SLOT(actionImportContacts()));
    connect(ui->actionImportMessages,
            SIGNAL(triggered()), this, SLOT(actionImportMessages()));
    connect(ui->actionSave,
            SIGNAL(triggered()), this, SLOT(actionSave()));
    connect(ui->actionExit,
            SIGNAL(triggered()), this, SLOT(actionExit()));
    connect(ui->actionPort,
            SIGNAL(triggered()), this, SLOT(actionPort()));
    connect(ui->actionContent,
            SIGNAL(triggered()), this, SLOT(actionContent()));
    connect(ui->actionContact,
            SIGNAL(triggered()), this, SLOT(actionContact()));

    //Kontaktok felvétele
    connect(ui->ListAllCont,
            SIGNAL (itemClicked(QListWidgetItem*) ), this, SLOT (ContactItemSelected(QListWidgetItem*)) );
    connect(ui->NewCont,
            SIGNAL (clicked()), this, SLOT (NewCont()) );
    connect(ui->DeleteCont,
            SIGNAL (clicked()), this, SLOT(DeleteCont()) );
    connect(ui->UpdateCont,
            SIGNAL (clicked()), this, SLOT(UpdateCont()) );
    connect(ui->SaveCont,
            SIGNAL (clicked()), this, SLOT(SaveCont()) );

    //Üzenetek felvétele/módosítása
    connect(ui->ListAllMess,
            SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT (MessageItemSelected(QListWidgetItem*)) );
    connect(ui->NewMess,
            SIGNAL (clicked()), this, SLOT(NewMess()) );
    connect(ui->DeleteMess,
           SIGNAL(clicked()), this, SLOT(DeleteMess()) );
    connect(ui->UpdateMess,
            SIGNAL (clicked()), this, SLOT(UpdateMess()) );
    connect(ui->SaveMess,
            SIGNAL (clicked()), this, SLOT(SaveMess()) );

    //Üzenetküldés azonos szöveggel
    connect(ui->AllCont,
            SIGNAL (clicked()), this, SLOT(AllCont()) );
    connect(ui->CustomCont,
           SIGNAL(clicked()), this, SLOT(CustomCont()) );
    connect(ui->ListAllCont2,
            SIGNAL (itemDoubleClicked(QListWidgetItem*) ), this, SLOT (ContactItemSelected2(QListWidgetItem*)) );
    connect(ui->ContToSend,
            SIGNAL (itemDoubleClicked(QListWidgetItem*)), this, SLOT(ContToSendSelected(QListWidgetItem*)) );
    connect(ui->ContToSend,
            SIGNAL (itemClicked(QListWidgetItem*)), this, SLOT(ContToSendSelected(QListWidgetItem*)) );
    connect(ui->DeleteFromSend,
            SIGNAL (clicked()), this, SLOT(DeleteFromSend()) );
    /*connect(ui->MessList,
            SIGNAL (highlighted(const QString*)), this, SLOT(MessageSelected(const QString*)) );*/
    connect(ui->Send,
            SIGNAL (clicked()), this, SLOT(Send()) );


    //Üzenetküldés több embernek más-más szöveggel
    connect(ui->ListAllCont3,
            SIGNAL (itemDoubleClicked(QListWidgetItem*) ), this, SLOT (ContactItemSelected3(QListWidgetItem*)) );
    connect(ui->ContToSend2,
            SIGNAL (itemClicked(QListWidgetItem*)), this, SLOT(ContToSendSelected2(QListWidgetItem*)) );
    connect(ui->ContToSend2,
            SIGNAL (itemDoubleClicked(QListWidgetItem*)), this, SLOT(ContToSendSelected2(QListWidgetItem*)) );
    connect(ui->DeleteFromSend2,
        SIGNAL (clicked()), this, SLOT(DeleteFromSend2()) );
    connect(ui->Send2,
        SIGNAL (clicked()), this, SLOT(Send2()) );




    //beolvasas
    OpenCSV();
    OpenCSVMess();
}


//DESTRUCTOR
MainWindow::~MainWindow()
{
    delete ui;
}


/*----------------------------------------------------Open and save contacts----------------------------------------*/


//OPEN


void MainWindow::OpenCSV()
{
    QFile file("data.txt");

    if(!file.exists())
    {
        QMessageBox::critical(this, "File hiba", "A kiválasztott fájl(data.txt) nem létezik.");
        return;
    }

    file.open(QFile::ReadOnly);
    QTextStream in(&file);

    QString ContactData;

    while(!in.atEnd())
    {
        ContactData=in.readLine();
        QStringList data = ContactData.split(';');
        ContactClass temp(data.at(1), data.at(0), data.at(2), data.at(3));
        vector.push_back(temp);
    }
    file.close();

    for(int i=0; i<vector.size(); ++i)
    {
        ui->ListAllCont->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");
        ui->ListAllCont2->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");
        ui->ListAllCont3->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");

    }
}


//SAVE
void MainWindow::SaveCSV()
{
    QFile file("data.txt");
    file.open(QFile::WriteOnly);
    QTextStream out(&file);

    for(int i=0; i<this->vector.size(); i++)
    {
        out<<this->vector.at(i).Name<<";"<<this->vector.at(i).Phone<<";"<<this->vector.at(i).Mail<<";"<<this->vector.at(i).Address<<"\r\n";
    }
    file.close();
}

/*----------------------------------------------------Open and save messages----------------------------------------*/

//OPEN

void MainWindow::OpenCSVMess()
{
    QFile file("messages.txt");

    if(!file.exists())
    {
        QMessageBox::critical(this, "File hiba", "A kiválasztott fájl(messages.txt) nem létezik.");
        return;
    }
    file.open(QFile::ReadOnly);
    QTextStream in(&file);

    QString MessData;

    while(!in.atEnd())
    {
        MessData=in.readLine();
        QStringList data=MessData.split(';');
        MessageClass temp(data.at(0), data.at(1));
        vectormess.push_back(temp);

    }

    file.close();

    //Fill out message lists
    for(int i=0; i<vectormess.size(); ++i)
    {
        ui->ListAllMess->addItem(vectormess.at(i).Id);
        ui->MessList->addItem(vectormess.at(i).Id);
        //ui->
    }

}

//SAVE
void MainWindow::SaveCSVMess()
{
    QFile file("messages.txt");
    file.open(QFile::WriteOnly);
    QTextStream out(&file);

    for(int i=0; i<vectormess.size();++i)
    {
        out<<vectormess.at(i).Id<<";"<<vectormess.at(i).MessageText<<"\r\n";
    }
    file.close();
}

/*-------------------------------------------------------Funtion definitions----------------------------------------------------------*/




//Menu bar


void MainWindow::actionImportContacts()
{
    //Select file to be imported
    QString filename=QFileDialog::getOpenFileName(this,
                                          tr("Kontaktok importálása"), "/home", tr("Text files(*.txt)"));
    if(filename.isNull()) return;

    //Open file
    QFile file(filename);

    if(!file.exists())
    {
        QMessageBox::critical(this, "File hiba", "Az importálásra kiválasztott fájl nem létezik");
    }


    file.open(QFile::ReadOnly);

    QTextStream in(&file);
    QString ContactData;

    while(!in.atEnd())
    {
        ContactData=in.readLine();
        if(ContactData.count(";")<3)
        {
            QMessageBox::critical(this, "Hibás fájl!", "Ön valószínûleg üzeneteket próbált importálni.");
        }

        QStringList data = ContactData.split(';');
        ContactClass temp(data.at(1), data.at(0), data.at(2), data.at(3));

        int sign=0;
        for(int i=0; i<vector.size(); ++i)
        {
            if(vector.at(i).Phone==temp.Phone) sign=1;
        }

        if(sign==0)
        {
            vector.push_back(temp);
        }
    }
    QMessageBox::information(this, "Sikeres importálás", "A kiválasztott fájlt sikeresen importálta!");
    file.close();

    ui->ListAllCont->clear();
    ui->ListAllCont2->clear();
    ui->ListAllCont3->clear();

    for(int i=0; i<vector.size(); ++i)
    {
        ui->ListAllCont->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");
        ui->ListAllCont2->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");
        ui->ListAllCont3->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");

    }

}

void MainWindow::actionImportMessages()
{
    QString filename=QFileDialog::getOpenFileName(this,
            tr("Üzenetek importálása"),"/home", tr("Text files(*.txt)"));
    if(filename.isNull()) return;

    //Open file
    QFile file(filename);

    if(!file.exists())
    {
        QMessageBox::critical(this, "File hiba", "Az importálásra kiválasztott fájl nem létezik");
    }


    file.open(QFile::ReadOnly);

    QTextStream in(&file);
    QString MessageData;

    while(!in.atEnd())
    {
        MessageData=in.readLine();
        if(MessageData.count(";")>2)
        {
            QMessageBox::critical(this, "Hibás fájl", "Ön valószínûleg kontaktokat próbált importálni");
        }

        QStringList data = MessageData.split(';');
        MessageClass temp(data.at(0), data.at(1));

        int sign=0;
        for(int i=0; i<vectormess.size(); ++i)
        {
            if(vectormess.at(i).Id==temp.Id) sign=1;
        }

        if(sign==0)
        {
            vectormess.push_back(temp);
        }
    }
    QMessageBox::information(this, "Sikeres importálás", "A kiválasztott fájlt sikeresen importálta!");
    file.close();

    ui->ListAllMess->clear();
    ui->MessList->clear();

    for(int i=0; i<vectormess.size(); ++i)
    {
        ui->ListAllMess->addItem(vectormess.at(i).Id);
        ui->MessList->addItem(vectormess.at(i).Id);
    }
}

void MainWindow::actionSave()
{
    SaveCSV();
    SaveCSVMess();
    QMessageBox::information(this, "Sikeres mentés", "Sikeresen mentette a módosításokat!");
}

void MainWindow::actionExit()
{
    SaveCSV();
    SaveCSVMess();
    close();
}

void MainWindow::actionPort()
{
    portset ablak;
    if(!ablak.exec()) {return;}

    port = ablak.getPort();



}

void MainWindow::actionContent()
{
    if( !QDesktopServices::openUrl(QUrl("Help.pdf")) )
    {
        QMessageBox::critical(this, "Help", "Hiba! A dokumentáció nem nyitható meg.");
    }


}

void MainWindow::actionContact()
{
    nevjegy about;
    if(!about.exec()) {return;}
}



//1st tab


void MainWindow::ContactItemSelected(QListWidgetItem* item)
{
    QString text=item->text();
    QString key("");

    for (int i=( text.indexOf("(")+1 ); i<text.indexOf(")"); ++i)
    {
        key.push_back( text[i] );
    }
    for (int i=0; i<vector.size(); ++i)
    {
        if(vector[i].Phone==key)
        {
            ui->Name->clear();
            ui->Name->insert(vector[i].Name);
            ui->Address->clear();
            ui->Address->insert(vector[i].Address);
            ui->Phone->clear();
            ui->Phone->insert(vector[i].Phone);
            ui->Mail->clear();
            ui->Mail->insert(vector[i].Mail);
            vector[i].SelectedPhoneNumber=vector[i].Phone;
        }
    }


    ui->DeleteCont->setEnabled(true);
    ui->UpdateCont->setEnabled(true);
    ui->SaveCont->setDisabled(true);
}

void MainWindow::NewCont()
{

    ui->Phone->clear();
    ui->Name->clear();
    ui->Address->clear();
    ui->Mail->clear();

    vector[0].SelectedPhoneNumber="";

    ui->UpdateCont->setDisabled(true);
    ui->SaveCont->setEnabled(true);
    ui->DeleteCont->setDisabled(true);



}

void MainWindow::DeleteCont()
{
    for(int i=0; i<vector.size(); ++i)
    {
        if(vector[i].Phone==vector[0].SelectedPhoneNumber)
        {
            vector.remove(i);
        }
    }
    //Update list
    ui->ListAllCont->clear();
    ui->ListAllCont2->clear();
    ui->ListAllCont3->clear();
    for(int i=0; i<vector.size(); ++i)
    {
        ui->ListAllCont->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");
        ui->ListAllCont2->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");
        ui->ListAllCont3->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");
    }

    //Clear boxes
    ui->Phone->clear();
    ui->Phone->setText("Telefonszám");
    ui->Name->clear();
    ui->Name->setText("Név");
    ui->Address->clear();
    ui->Address->setText("Cím");
    ui->Mail->clear();
    ui->Mail->setText("E-Mail");


    //Clear SelectedPhone memory
    vector[0].SelectedPhoneNumber="";

    //Buttons
    ui->DeleteCont->setDisabled(true);
    ui->UpdateCont->setDisabled(true);
    ui->SaveCont->setEnabled(true);
}

void MainWindow::UpdateCont()
{
    //--------------error-handling--------------
    //Must get a phone number
    if(ui->Phone->text()=="")
    {
        QMessageBox::critical(this, "Hiányzó adat!", "Meg kell adnia telefonszámot");
        return;
    }
    //Phone number can only contain '+' and '0-9' characters
    if( !((ui->Phone->text().at(0).toAscii())==43 ||
        ((47<ui->Phone->text().at(0).toAscii()) && (ui->Phone->text().at(0).toAscii()<58)))  )
    {
        ui->Phone->setFocus();
        ui->Phone->selectAll();
        QMessageBox::critical(this, "Hibás adat!", "A telefonszámban meg nem engedett karakter szerepel!");
        return;
    }

    for(int i=1; i<ui->Phone->text().size(); ++i)
    {

        if( (ui->Phone->text().at(i).toAscii())<48 || (ui->Phone->text().at(i).toAscii())>57)
        {

            ui->Phone->setFocus();
            ui->Phone->selectAll();
            QMessageBox::critical(this, "Hibás adat!", "A telefonszámban meg nem engedett karakter szerepel!");
            return;
        }
    }
    //If e-mail is given, it must contain an @
    if(ui->Mail->text() != "")
    {
        int ok=0;
        for(int i=0; i<ui->Mail->text().size(); ++i)
        {
            if(ui->Mail->text().at(i).toAscii()==64)
            {ok=1;}
        }
        if(ok==0)
        {
            ui->Mail->setFocus();
            ui->Mail->selectAll();
            QMessageBox::critical(this, "Hibás adat!", "Az e-mail címnek tartalmaznia kell '@'-ot");
            return;
        }
    }



    for(int i=0; i<vector.size(); ++i)
    {
        if(vector[i].Phone==vector[0].SelectedPhoneNumber)
        {
            vector[i].Address=ui->Address->text();
            vector[i].Name=ui->Name->text();
            vector[i].Phone=ui->Phone->text();
            vector[i].Mail=ui->Mail->text();
        }
    }

    //Update list
    ui->ListAllCont->clear();
    ui->ListAllCont2->clear();
    ui->ListAllCont3->clear();
    for(int i=0; i<vector.size(); ++i)
    {
        ui->ListAllCont->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");
        ui->ListAllCont2->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");
        ui->ListAllCont3->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");
    }

    //Clear boxes
    ui->Phone->clear();
    //ui->Phone->setText("Telefonszám");
    ui->Name->clear();
    //ui->Name->setText("Név");
    ui->Address->clear();
    //ui->Address->setText("Cím");
    ui->Mail->clear();
    //ui->Mail->setText("E-Mail");


    //Clear SelectedPhone memory
    vector[0].SelectedPhoneNumber="";

    //Buttons
    ui->DeleteCont->setDisabled(true);
    ui->UpdateCont->setDisabled(true);
    ui->SaveCont->setEnabled(true);

}

void MainWindow::SaveCont()
{
    //--------------error-handling--------------
    //Must get a phone number
    if(ui->Phone->text()=="")
    {
        ui->Phone->setFocus();
        ui->Phone->selectAll();
        QMessageBox::critical(this, "Hiányzó adat!", "Meg kell adnia telefonszámot");
        return;
    }
    //New contact must have a NEW number
    for(int i=0; i<vector.size(); ++i)
    {
        if(ui->Phone->text()==vector.at(i).Phone)
        {
            ui->Phone->setFocus();
            ui->Phone->selectAll();
            QMessageBox::critical(this, "Hibás adat!", "Ez a telefonszám már szerepel a rendszerben!");
            return;
        }
    }
    //Phone number can only contain '+' and '0-9' characters
    if( !((ui->Phone->text().at(0).toAscii())==43 ||
        ((47<ui->Phone->text().at(0).toAscii()) && (ui->Phone->text().at(0).toAscii()<58)))  )
    {
        ui->Phone->setFocus();
        ui->Phone->selectAll();
        QMessageBox::critical(this, "Hibás adat!", "A telefonszámban meg nem engedett karakter szerepel!");
        return;
    }
    for(int i=1; i<ui->Phone->text().size(); ++i)
    {

        if( (ui->Phone->text().at(i).toAscii())<48 || (ui->Phone->text().at(i).toAscii())>57)
        {
            ui->Phone->setFocus();
            ui->Phone->selectAll();
            QMessageBox::critical(this, "Hibás adat!", "A telefonszámban meg nem engedett karakter szerepel!");
            return;
        }
    }

    //If e-mail is given, it must contain an @
    if(ui->Mail->text() != "")
    {
        int ok=0;
        for(int i=0; i<ui->Mail->text().size(); ++i)
        {
            if(ui->Mail->text().at(i).toAscii()==64)
            {ok=1;}
        }
        if(ok==0)
        {
            ui->Mail->setFocus();
            ui->Mail->selectAll();
            QMessageBox::critical(this, "Hibás adat!", "Az e-mail címnek tartalmaznia kell '@'-ot");
            return;
        }
    }



    ContactClass curr(ui->Phone->text(), ui->Name->text(), ui->Address->text(), ui->Mail->text());
    vector.push_back(curr);

    //Update list
    ui->ListAllCont->clear();
    ui->ListAllCont2->clear();
    ui->ListAllCont3->clear();
    for(int i=0; i<vector.size(); ++i)
    {
        ui->ListAllCont->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");
        ui->ListAllCont2->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");
        ui->ListAllCont3->addItem(vector.at(i).Name + "   (" + vector.at(i).Phone + ")");
    }

    //Clear boxes
    ui->Phone->clear();
    ui->Name->clear();
    ui->Address->clear();
    ui->Mail->clear();

    //Clear SelectedPhone memory
    vector[0].SelectedPhoneNumber="";

    //Buttons
    ui->DeleteCont->setDisabled(true);
    ui->UpdateCont->setDisabled(true);
    ui->SaveCont->setEnabled(true);
}


//2nd tab

void MainWindow::MessageItemSelected(QListWidgetItem* item)
{
   QString text=item->text();

    for (int i=0; i<vectormess.size(); ++i)
    {
        if(vectormess[i].Id==text)
        {
            ui->MessId->clear();
            ui->MessId->setText(vectormess[i].Id);
            ui->MessSelect->clear();
            ui->MessSelect->setText(vectormess[i].MessageText);
            vectormess[i].SelectedMess=vectormess[i].Id;
        }
    }
    //Buttons
    ui->UpdateMess->setEnabled(true);
    ui->SaveMess->setDisabled(true);
    ui->DeleteMess->setEnabled(true);
}

void MainWindow::NewMess()
{
    ui->MessId->clear();
    ui->MessSelect->clear();
    vectormess[0].SelectedMess="";

    //Buttons
    ui->UpdateMess->setDisabled(true);
    ui->SaveMess->setEnabled(true);
    ui->DeleteMess->setDisabled(true);

}

void MainWindow::DeleteMess()
{
    //Select message from message vector
    for(int i=0; i<vectormess.size(); ++i)
    {
        if(vectormess[0].SelectedMess==vectormess[i].Id)
        {
            vectormess.remove(i);
        }
    }

    //Clear memory
    vectormess[0].SelectedMess="";

    //Clear boxes
    ui->MessId->clear();
    ui->MessSelect->clear();

    //Update
    ui->ListAllMess->clear();
    ui->MessList->clear();
    for(int i=0; i<vectormess.size(); ++i)
    {
        ui->ListAllMess->addItem(vectormess.at(i).Id);
        ui->MessList->addItem(vectormess.at(i).Id);
    }

    //Buttons
    ui->DeleteMess->setDisabled(true);
    ui->UpdateMess->setDisabled(true);
    ui->SaveMess->setEnabled(true);
}

void MainWindow::UpdateMess()
{
    //Must have an ID and a message
    if(ui->MessId->text()=="")
    {
        ui->MessId->selectAll();
        ui->MessId->setFocus();
        QMessageBox::critical(this, "Hiányzó adat!", "Meg kell adnia egy azonosítót!");
        return;
    }
    if(ui->MessSelect->toPlainText()=="")
    {
        ui->MessSelect->selectAll();
        ui->Messages->setFocus();
        QMessageBox::critical(this, "Hiányzó adat!", "Adjon meg valamilyen szöveget!");
        return;
    }

    //Select item from message vector
    for(int i=0; i<vectormess.size(); ++i)
    {
        if(vectormess[i].Id==vectormess[0].SelectedMess)
        {
            vectormess[i].Id=ui->MessId->text();
            vectormess[i].MessageText=ui->MessSelect->toPlainText();
        }
    }

    //Update list
    ui->ListAllMess->clear();
    ui->MessList->clear();
    for(int i=0; i<vectormess.size(); ++i)
    {
        ui->ListAllMess->addItem(vectormess.at(i).Id);
        ui->MessList->addItem(vectormess.at(i).Id);
    }

    //Clear boxes
    ui->MessId->clear();
    ui->MessSelect->clear();


    ui->DeleteMess->setDisabled(true);
    ui->UpdateMess->setDisabled(true);
    ui->SaveMess->setEnabled(true);

    //Clear SelectedPhone memory
    vectormess[0].SelectedMess="";

    //Buttons
    ui->DeleteMess->setDisabled(true);
    ui->UpdateMess->setDisabled(true);
    ui->SaveMess->setEnabled(true);
}

void MainWindow::SaveMess()
{
    //Must have Id and message
    if(ui->MessId->text()=="")
    {
        ui->MessId->selectAll();
        ui->MessId->setFocus();
        QMessageBox::critical(this, "Hiányzó adat!", "Meg kell adnia egy azonosítót!");
        return;
    }
    if(ui->MessSelect->toPlainText()=="")
    {
        ui->MessSelect->selectAll();
        ui->MessSelect->setFocus();
        QMessageBox::critical(this, "Hiányzó adat!", "Adjon meg valamilyen szöveget!");
        return;
    }
    //New message must have a NEW Id
    for(int i=0; i<vectormess.size(); ++i)
    {
        if(vectormess.at(i).Id==ui->MessId->text())
        {
            ui->MessId->selectAll();
            ui->MessId->setFocus();
            QMessageBox::critical(this, "Hibás adat!", "Ilyen azonosítójú üzenet már van a rendszerben!");
            return;
        }
    }


    //Save item
    MessageClass temp(ui->MessId->text(), ui->MessSelect->toPlainText());
    vectormess.push_back(temp);

    //Clear boxes
    ui->MessId->clear();
    ui->MessSelect->clear();

    //Clear memory
    vectormess[0].SelectedMess="";

    //Update List
    ui->ListAllMess->clear();
    ui->MessList->clear();
    for(int i=0; i<vectormess.size(); ++i)
    {
        ui->ListAllMess->addItem(vectormess.at(i).Id);
        ui->MessList->addItem(vectormess.at(i).Id);
    }

    //Buttons
    ui->DeleteMess->setDisabled(true);
    ui->UpdateMess->setDisabled(true);
    ui->SaveMess->setEnabled(true);
}


//3rd tab

void MainWindow::ContactItemSelected2(QListWidgetItem* item)
{
    //Key for the search
    QString text=item->text();
    QString key("");

    for (int i=( text.indexOf("(")+1 ); i<text.indexOf(")"); ++i)
    {
        key.push_back( text[i] );
    }

    //Searching for the contact AND putting it to MessSelect IF it is not there yet
    for(int i=0; i<ContactsToSend1.size(); ++i)
    {
        if(ContactsToSend1.at(i).Phone==key)
        {
            QMessageBox::information(this,"A mûvelet nem hajtható végre!","Ez a címzett már szerepel a listában!" );
            return;
        }
    }


    for(int i=0; i<vector.size(); ++i)
    {
        if(vector.at(i).Phone==key)
        {
            ContactClass temp(vector.at(i).Phone, vector.at(i).Name, vector.at(i).Address, vector.at(i).Mail);
            ContactsToSend1.push_back(temp);
        }
    }

    ui->ContToSend->addItem(item->text());

    ui->DeleteFromSend->setDisabled(true);

}

void MainWindow::AllCont()
{
    ui->AllCont->setAutoExclusive(true);

    ui->ListAllCont2->setDisabled(true);

    ui->ContToSend->clear();

    for (int i=0; i<vector.size(); ++i)
    {
        ui->ContToSend->addItem(vector.at(i).Name+"    ("+vector.at(i).Phone+")");

        ContactsToSend1.push_back(vector.at(i));

    }

    ui->DeleteFromSend->setDisabled(true);
}

void MainWindow::CustomCont()
{
    ui->ContToSend->clear();
    ContactsToSend1.clear();

    ui->ListAllCont2->setEnabled(true);
    ui->DeleteFromSend->setDisabled(true);
}

void MainWindow::ContToSendSelected(QListWidgetItem* item)
{
    //Generating the key to store in memory "SelectedTosend"
    QString text=item->text();
    QString key("");

    for (int i=( text.indexOf("(")+1 ); i<text.indexOf(")"); ++i)
    {
        key.push_back( text[i] );
    }

    ContactsToSend1.at(0).SelectedToSend=key;

    ui->DeleteFromSend->setEnabled(true);
}

void MainWindow::DeleteFromSend()
{
  for(int i=0; i<ContactsToSend1.size(); ++i)
  {
    if(ContactsToSend1.at(i).Phone==ContactsToSend1.at(0).SelectedToSend)
    {
        ContactsToSend1.remove(i);
    }
  }

  if(ContactsToSend1.size()!=0)
  {
    ContactsToSend1.at(0).SelectedToSend="";
  }
  ui->ContToSend->clear();

  for(int i=0; i<ContactsToSend1.size(); ++i)
  {
      ui->ContToSend->addItem(ContactsToSend1.at(i).Name+"   ("+ContactsToSend1.at(i).Phone+")");
  }


  ui->DeleteFromSend->setDisabled(true);
}

void MainWindow::MessageSelected(const QString &text)
{
    SelectedMessage=text;

    /*for(int i=0; i<ContactsToSend1.size(); ++i)
    {
        ContactsToSend1.at(i).Message=SelectedMessage;
    }*/
    ui->DeleteFromSend->setDisabled(true);
}

void MainWindow::Send()
{
    ui->DeleteFromSend->setDisabled(true);


    Serial rs(port, 9600);
    if(!rs.setup(5000))
    {
        qDebug() << "hiba";
        QMessageBox::critical(this, "Küldés sikertelen", "A kiválasztott adatokat nem tudta elküldeni az eszköznek. Valószínûleg rosszul állította be a portot.");
        return;
    }

    QString MessId=ui->MessList->currentText();

    QString MessText="";

    for(int i=0; i<vectormess.size(); ++i)
    {
        if(vectormess.at(i).Id==MessId)
        {
            MessText=vectormess.at(i).MessageText;
        }
    }
    for(int i=0; i<ContactsToSend1.size(); ++i)
    {
        rs.write(ContactsToSend1.at(i).Phone+"#"+MessText, true);
    }
    rs.close();

    if(ContactsToSend1.size()==0)
    {
        QMessageBox::critical(this, "Sikertelen küldés", "Nem választott ki egyetlen címzettet sem!");
        return;
    }


    ContactsToSend1.clear();
    ui->ContToSend->clear();




    for(int i=0; i<ContactsToSend1.size(); ++i)
    {
        ui->ContToSend->addItem(ContactsToSend1.at(i).Name+"   ("+ContactsToSend1.at(i).Phone+")");
    }


    QMessageBox::information(this, "Küldés sikeres", "A kiválasztott adatokat sikeresen elküldte az eszköznek!");

}


//4th tab
void MainWindow::ContactItemSelected3(QListWidgetItem* item)
{

    messagephone msgphone;
    QString nev;

    //Key(Phone num) for the search
    QString text=item->text();
    QString key("");

    for (int i=( text.indexOf("(")+1 ); i<text.indexOf(")"); ++i)
    {
        key.push_back( text[i] );
    }


    //msgphone Phone!
    msgphone.Phone = key;

    egyeniuzenet msg(vectormess);
    if(!msg.exec()) { return; }

    QString messName = msg.getMess();

    //Searching for the contact
    for(int i=0; i<vector.size(); ++i)
    {
        if(vector.at(i).Phone==key)
        {
            nev = vector.at(i).Name;
        }
    }

    //Searching for the message
    for(int i=0; i<vectormess.size(); ++i)
    {
        if(vectormess.at(i).Id==messName)
        {
            //msgPhone Message
            msgphone.Message = vectormess.at(i).Id;
        }
    }

    for(int i=0; i<ContactsToSend2.size(); ++i)
    {
        if(ContactsToSend2.at(i).Phone==key && ContactsToSend2.at(i).Message==messName)
        {
            QMessageBox::information(this, "A mûvelet nem hajtható végre!","Ez a címzett már szerepel a listában ezzel az üzenettel!");
            return;
        }
    }

    ContactsToSend2.push_back(msgphone);
    ui->ContToSend2->addItem(nev + " (" + msgphone.Phone + ") - " + messName);

    ui->DeleteFromSend2->setDisabled(true);
}

void MainWindow::ContToSendSelected2(QListWidgetItem* item)
{
    //Key(Phone num) for the search
    QString text=item->text();
    QString keyphone("");
    QString keymessage("");

    for (int i=( text.indexOf("(")+1 ); i<text.indexOf(")"); ++i)
    {
        keyphone.push_back( text[i] );
    }
    for(int i=(text.indexOf("-")+2); i<text.size(); ++i)
    {
        keymessage.push_back(text[i]);
    }

    //Set selected messagephone
    ContactsToSend2.at(0).SelectedMessagePhone.Phone=keyphone;
    ContactsToSend2.at(0).SelectedMessagePhone.Message=keymessage;

    ui->DeleteFromSend2->setEnabled(true);

}

void MainWindow::DeleteFromSend2()
{
    //Delete messagephone item
    for(int i=0; i<ContactsToSend2.size(); i++)
    {
        if(ContactsToSend2.at(i).Message==ContactsToSend2.at(0).SelectedMessagePhone.Message &&
              ContactsToSend2.at(i).Phone==ContactsToSend2.at(0).SelectedMessagePhone.Phone )
        {
            ContactsToSend2.remove(i);
        }
    }

    //Delete massagephone memory
    if(ContactsToSend2.size()!=0)
    {
        ContactsToSend2.at(0).SelectedMessagePhone.Phone="";
        ContactsToSend2.at(0).SelectedMessagePhone.Message="";
    }

    //Update list
    ui->ContToSend2->clear();


        for(int i=0; i<ContactsToSend2.size(); i++)
        {
            QString name;
            QString phone=ContactsToSend2.at(i).Phone;
            QString messId=ContactsToSend2.at(i).Message;

            for(int j=0; j<vector.size(); j++)
            {
                if(vector.at(j).Phone==phone)
                {
                    name=vector.at(j).Name;
                }
            }

            ui->ContToSend2->addItem(name + " (" + phone + ") - " + messId);
        }

    ui->DeleteFromSend2->setDisabled(true);
}


void MainWindow::Send2()
{
    ui->DeleteFromSend2->setDisabled(true);

    Serial rs(port, 9600);
    if(!rs.setup(5000))
    {
        qDebug() << "hiba";
        QMessageBox::critical(this, "Küldés sikertelen", "A kiválasztott adatokat nem tudta elküldeni az eszköznek. Valószínûleg rosszl állította be a portot.");
        return;
    }

    QString Phone;
    QString MessId;
    QString MessText;

    for(int i=0; i<ContactsToSend2.size(); ++i)
    {
        Phone=ContactsToSend2.at(i).Phone;
        MessId=ContactsToSend2.at(i).Message;
        for(int j=0; j<vectormess.size(); ++j)
        {
            if(vectormess.at(j).Id==MessId)
            {
                MessText=vectormess.at(j).MessageText;
            }
        }

        rs.write(Phone+"#"+MessText, true);

    }
    rs.close();

    if(ContactsToSend2.size()==0)
    {
        QMessageBox::critical(this, "Sikertelen küldés", "Nem választott ki egyetlen címzettet sem!");
        return;
    }

    ContactsToSend2.clear();
    ui->ContToSend2->clear();

    for(int i=0; i<ContactsToSend2.size(); i++)
    {
        QString name;
        QString phone=ContactsToSend2.at(i).Phone;
        QString messId=ContactsToSend2.at(i).Message;

        for(int j=0; j<vector.size(); j++)
        {
            if(vector.at(j).Phone==phone)
            {
                name=vector.at(j).Name;
            }
        }

        ui->ContToSend2->addItem(name + " (" + phone + ") - " + messId);
    }

    QMessageBox::information(this, "Küldés sikeres", "A kiválasztott adatokat sikeresen elküldte az eszköznek!");
}

