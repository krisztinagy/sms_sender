#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "contactclass.h"
#include "messageclass.h"
#include "egyeniuzenet.h"
#include "portset.h"
#include "messagephone.h"
#include <QListWidgetItem>
#include <QString>

/*SMS_KULDO*/

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

//Men�sor
    void actionImportContacts();
    void actionImportMessages();
    void actionSave();
    void actionExit();

    void actionPort();

    void actionContent();
    void actionContact();


//Kontaktok felv�tele
    void ContactItemSelected(QListWidgetItem*);
    void NewCont();
    void DeleteCont();
    void UpdateCont();
    void SaveCont();
    //void DelData();


//�zenetek felv�tele/m�dos�t�sa
    void MessageItemSelected(QListWidgetItem*);
    void NewMess();
    void DeleteMess();
    void UpdateMess();
    void SaveMess();


//�zenetk�ld�s sablon
    void AllCont();
    void CustomCont();
    void ContactItemSelected2(QListWidgetItem*);
    void ContToSendSelected(QListWidgetItem*);
    void DeleteFromSend();
    void MessageSelected(const QString &text);
    void Send();


//�zenetk�ld�s egy�ni
    void ContactItemSelected3(QListWidgetItem*);
    void ContToSendSelected2(QListWidgetItem*);
    void DeleteFromSend2();
    void Send2();



//Save/Open
    void OpenCSV();
    void SaveCSV();
    void OpenCSVMess();
    void SaveCSVMess();


protected:
    QVector<ContactClass> vector;
    QVector<ContactClass> ContactsToSend1;
    QVector<messagephone> ContactsToSend2;
    QVector<MessageClass> vectormess;

    QString SelectedMessage;

    QString port;

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H


