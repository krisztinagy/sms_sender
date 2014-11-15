/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Jul 21 13:46:41 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImportContacts;
    QAction *actionExit;
    QAction *actionPort;
    QAction *actionSave;
    QAction *actionContent;
    QAction *actionContact;
    QAction *actionImportMessages;
    QWidget *centralWidget;
    QTabWidget *Tabs;
    QWidget *Contacts;
    QGroupBox *groupBox;
    QListWidget *ListAllCont;
    QPushButton *NewCont;
    QGroupBox *groupBox_2;
    QPushButton *SaveCont;
    QPushButton *DeleteCont;
    QPushButton *UpdateCont;
    QLineEdit *Mail;
    QLineEdit *Phone;
    QLineEdit *Address;
    QLineEdit *Name;
    QWidget *Usual;
    QGroupBox *groupBox_6;
    QListWidget *ListAllMess;
    QPushButton *NewMess;
    QGroupBox *groupBox_7;
    QLineEdit *MessId;
    QTextEdit *MessSelect;
    QPushButton *DeleteMess;
    QPushButton *SaveMess;
    QPushButton *UpdateMess;
    QWidget *Messages;
    QGroupBox *groupBox_3;
    QListWidget *ListAllCont2;
    QRadioButton *AllCont;
    QRadioButton *CustomCont;
    QGroupBox *groupBox_4;
    QComboBox *MessList;
    QGroupBox *groupBox_5;
    QListWidget *ContToSend;
    QPushButton *DeleteFromSend;
    QPushButton *Send;
    QWidget *Custom;
    QGroupBox *groupBox_8;
    QListWidget *ListAllCont3;
    QGroupBox *groupBox_10;
    QListWidget *ContToSend2;
    QPushButton *Send2;
    QPushButton *DeleteFromSend2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(750, 477);
        actionImportContacts = new QAction(MainWindow);
        actionImportContacts->setObjectName(QString::fromUtf8("actionImportContacts"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionPort = new QAction(MainWindow);
        actionPort->setObjectName(QString::fromUtf8("actionPort"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionContent = new QAction(MainWindow);
        actionContent->setObjectName(QString::fromUtf8("actionContent"));
        actionContact = new QAction(MainWindow);
        actionContact->setObjectName(QString::fromUtf8("actionContact"));
        actionImportMessages = new QAction(MainWindow);
        actionImportMessages->setObjectName(QString::fromUtf8("actionImportMessages"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Tabs = new QTabWidget(centralWidget);
        Tabs->setObjectName(QString::fromUtf8("Tabs"));
        Tabs->setGeometry(QRect(10, 10, 731, 421));
        Contacts = new QWidget();
        Contacts->setObjectName(QString::fromUtf8("Contacts"));
        groupBox = new QGroupBox(Contacts);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 361, 381));
        ListAllCont = new QListWidget(groupBox);
        ListAllCont->setObjectName(QString::fromUtf8("ListAllCont"));
        ListAllCont->setGeometry(QRect(20, 20, 311, 321));
#ifndef QT_NO_TOOLTIP
        ListAllCont->setToolTip(QString::fromUtf8(""));
#endif // QT_NO_TOOLTIP
        NewCont = new QPushButton(groupBox);
        NewCont->setObjectName(QString::fromUtf8("NewCont"));
        NewCont->setGeometry(QRect(140, 350, 75, 23));
        groupBox_2 = new QGroupBox(Contacts);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(380, 10, 301, 381));
        SaveCont = new QPushButton(groupBox_2);
        SaveCont->setObjectName(QString::fromUtf8("SaveCont"));
        SaveCont->setGeometry(QRect(180, 270, 75, 23));
        DeleteCont = new QPushButton(groupBox_2);
        DeleteCont->setObjectName(QString::fromUtf8("DeleteCont"));
        DeleteCont->setGeometry(QRect(20, 270, 75, 23));
        UpdateCont = new QPushButton(groupBox_2);
        UpdateCont->setObjectName(QString::fromUtf8("UpdateCont"));
        UpdateCont->setEnabled(false);
        UpdateCont->setGeometry(QRect(100, 270, 75, 23));
        Mail = new QLineEdit(groupBox_2);
        Mail->setObjectName(QString::fromUtf8("Mail"));
        Mail->setGeometry(QRect(10, 180, 251, 31));
        Phone = new QLineEdit(groupBox_2);
        Phone->setObjectName(QString::fromUtf8("Phone"));
        Phone->setGeometry(QRect(10, 130, 251, 31));
        Address = new QLineEdit(groupBox_2);
        Address->setObjectName(QString::fromUtf8("Address"));
        Address->setGeometry(QRect(10, 80, 251, 31));
        Name = new QLineEdit(groupBox_2);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setGeometry(QRect(10, 30, 251, 31));
        Tabs->addTab(Contacts, QString());
        groupBox_2->raise();
        groupBox->raise();
        Usual = new QWidget();
        Usual->setObjectName(QString::fromUtf8("Usual"));
        groupBox_6 = new QGroupBox(Usual);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(20, 10, 311, 371));
        ListAllMess = new QListWidget(groupBox_6);
        ListAllMess->setObjectName(QString::fromUtf8("ListAllMess"));
        ListAllMess->setGeometry(QRect(20, 20, 271, 311));
        NewMess = new QPushButton(groupBox_6);
        NewMess->setObjectName(QString::fromUtf8("NewMess"));
        NewMess->setGeometry(QRect(90, 340, 131, 23));
        groupBox_7 = new QGroupBox(Usual);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(370, 10, 331, 371));
        MessId = new QLineEdit(groupBox_7);
        MessId->setObjectName(QString::fromUtf8("MessId"));
        MessId->setGeometry(QRect(30, 20, 191, 31));
        MessSelect = new QTextEdit(groupBox_7);
        MessSelect->setObjectName(QString::fromUtf8("MessSelect"));
        MessSelect->setGeometry(QRect(30, 60, 271, 221));
        DeleteMess = new QPushButton(groupBox_7);
        DeleteMess->setObjectName(QString::fromUtf8("DeleteMess"));
        DeleteMess->setGeometry(QRect(40, 300, 75, 23));
        SaveMess = new QPushButton(groupBox_7);
        SaveMess->setObjectName(QString::fromUtf8("SaveMess"));
        SaveMess->setGeometry(QRect(220, 300, 75, 23));
        UpdateMess = new QPushButton(groupBox_7);
        UpdateMess->setObjectName(QString::fromUtf8("UpdateMess"));
        UpdateMess->setEnabled(false);
        UpdateMess->setGeometry(QRect(130, 300, 75, 23));
        Tabs->addTab(Usual, QString());
        Messages = new QWidget();
        Messages->setObjectName(QString::fromUtf8("Messages"));
        groupBox_3 = new QGroupBox(Messages);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 10, 311, 371));
        ListAllCont2 = new QListWidget(groupBox_3);
        ListAllCont2->setObjectName(QString::fromUtf8("ListAllCont2"));
        ListAllCont2->setGeometry(QRect(20, 50, 271, 311));
        AllCont = new QRadioButton(groupBox_3);
        AllCont->setObjectName(QString::fromUtf8("AllCont"));
        AllCont->setGeometry(QRect(70, 20, 82, 17));
        CustomCont = new QRadioButton(groupBox_3);
        CustomCont->setObjectName(QString::fromUtf8("CustomCont"));
        CustomCont->setGeometry(QRect(170, 20, 82, 17));
        CustomCont->setChecked(true);
        groupBox_4 = new QGroupBox(Messages);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(360, 10, 341, 61));
        MessList = new QComboBox(groupBox_4);
        MessList->setObjectName(QString::fromUtf8("MessList"));
        MessList->setGeometry(QRect(20, 20, 301, 31));
        groupBox_5 = new QGroupBox(Messages);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(360, 80, 341, 301));
        ContToSend = new QListWidget(groupBox_5);
        ContToSend->setObjectName(QString::fromUtf8("ContToSend"));
        ContToSend->setGeometry(QRect(20, 20, 301, 231));
        DeleteFromSend = new QPushButton(groupBox_5);
        DeleteFromSend->setObjectName(QString::fromUtf8("DeleteFromSend"));
        DeleteFromSend->setGeometry(QRect(70, 260, 81, 31));
        Send = new QPushButton(groupBox_5);
        Send->setObjectName(QString::fromUtf8("Send"));
        Send->setGeometry(QRect(190, 260, 81, 31));
        Tabs->addTab(Messages, QString());
        Custom = new QWidget();
        Custom->setObjectName(QString::fromUtf8("Custom"));
        groupBox_8 = new QGroupBox(Custom);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(20, 20, 301, 351));
        ListAllCont3 = new QListWidget(groupBox_8);
        ListAllCont3->setObjectName(QString::fromUtf8("ListAllCont3"));
        ListAllCont3->setGeometry(QRect(10, 20, 281, 321));
        groupBox_10 = new QGroupBox(Custom);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(350, 20, 351, 351));
        ContToSend2 = new QListWidget(groupBox_10);
        ContToSend2->setObjectName(QString::fromUtf8("ContToSend2"));
        ContToSend2->setGeometry(QRect(10, 20, 331, 281));
        Send2 = new QPushButton(groupBox_10);
        Send2->setObjectName(QString::fromUtf8("Send2"));
        Send2->setGeometry(QRect(200, 310, 71, 31));
        DeleteFromSend2 = new QPushButton(groupBox_10);
        DeleteFromSend2->setObjectName(QString::fromUtf8("DeleteFromSend2"));
        DeleteFromSend2->setGeometry(QRect(90, 310, 71, 31));
        Tabs->addTab(Custom, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionImportContacts);
        menuFile->addAction(actionImportMessages);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuSettings->addAction(actionPort);
        menuHelp->addAction(actionContent);
        menuHelp->addAction(actionContact);

        retranslateUi(MainWindow);

        Tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SMS-k\303\274ld\305\221 vez\303\251rl\305\221ablak", 0, QApplication::UnicodeUTF8));
        actionImportContacts->setText(QApplication::translate("MainWindow", "Kontaktok Import\303\241l\303\241sa", 0, QApplication::UnicodeUTF8));
        actionImportContacts->setShortcut(QApplication::translate("MainWindow", "Ctrl+K", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Kil\303\251p\303\251s", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionPort->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        actionPort->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Ment\303\251s", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionContent->setText(QApplication::translate("MainWindow", "Tartalom", 0, QApplication::UnicodeUTF8));
        actionContent->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionContact->setText(QApplication::translate("MainWindow", "N\303\251vjegy", 0, QApplication::UnicodeUTF8));
        actionContact->setShortcut(QApplication::translate("MainWindow", "F2", 0, QApplication::UnicodeUTF8));
        actionImportMessages->setText(QApplication::translate("MainWindow", "\303\234zenetek import\303\241l\303\241sa", 0, QApplication::UnicodeUTF8));
        actionImportMessages->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Contacts->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("MainWindow", "\303\226sszes kontakt", 0, QApplication::UnicodeUTF8));
        NewCont->setText(QApplication::translate("MainWindow", "\303\232j", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Kijel\303\266lt kontakt", 0, QApplication::UnicodeUTF8));
        SaveCont->setText(QApplication::translate("MainWindow", "Ment\303\251s", 0, QApplication::UnicodeUTF8));
        DeleteCont->setText(QApplication::translate("MainWindow", "T\303\266rl\303\251s", 0, QApplication::UnicodeUTF8));
        UpdateCont->setText(QApplication::translate("MainWindow", "M\303\263dos\303\255t", 0, QApplication::UnicodeUTF8));
        Mail->setText(QString());
        Mail->setPlaceholderText(QApplication::translate("MainWindow", "e-mail", 0, QApplication::UnicodeUTF8));
        Phone->setText(QString());
        Phone->setPlaceholderText(QApplication::translate("MainWindow", "Telefonsz\303\241m", 0, QApplication::UnicodeUTF8));
        Address->setText(QString());
        Address->setPlaceholderText(QApplication::translate("MainWindow", "C\303\255m", 0, QApplication::UnicodeUTF8));
        Name->setText(QString());
        Name->setPlaceholderText(QApplication::translate("MainWindow", "N\303\251v", 0, QApplication::UnicodeUTF8));
        Tabs->setTabText(Tabs->indexOf(Contacts), QApplication::translate("MainWindow", "Kontaktok kezel\303\251se", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\303\226sszes \303\274zenet", 0, QApplication::UnicodeUTF8));
        NewMess->setText(QApplication::translate("MainWindow", "\303\232j \303\274zenet felv\303\251tele", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Kiv\303\241lasztott \303\274zenet", 0, QApplication::UnicodeUTF8));
        MessId->setText(QString());
        MessId->setPlaceholderText(QApplication::translate("MainWindow", "N\303\251v/Azonos\303\255t\303\263", 0, QApplication::UnicodeUTF8));
        DeleteMess->setText(QApplication::translate("MainWindow", "T\303\266rl\303\251s", 0, QApplication::UnicodeUTF8));
        SaveMess->setText(QApplication::translate("MainWindow", "Ment\303\251s", 0, QApplication::UnicodeUTF8));
        UpdateMess->setText(QApplication::translate("MainWindow", "M\303\263dos\303\255t", 0, QApplication::UnicodeUTF8));
        Tabs->setTabText(Tabs->indexOf(Usual), QApplication::translate("MainWindow", "\303\234zenetek kezel\303\251se", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Nevek", 0, QApplication::UnicodeUTF8));
        AllCont->setText(QApplication::translate("MainWindow", "\303\226sszes", 0, QApplication::UnicodeUTF8));
        CustomCont->setText(QApplication::translate("MainWindow", "Egy\303\251ni", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\303\234zenet", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "C\303\255mzettek", 0, QApplication::UnicodeUTF8));
        DeleteFromSend->setText(QApplication::translate("MainWindow", "T\303\266r\303\266l", 0, QApplication::UnicodeUTF8));
        Send->setText(QApplication::translate("MainWindow", "K\303\274ld", 0, QApplication::UnicodeUTF8));
        Tabs->setTabText(Tabs->indexOf(Messages), QApplication::translate("MainWindow", "\303\234zenetk\303\274ld\303\251s", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "\303\226sszes kontakt", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "C\303\255mzettek", 0, QApplication::UnicodeUTF8));
        Send2->setText(QApplication::translate("MainWindow", "K\303\274ld", 0, QApplication::UnicodeUTF8));
        DeleteFromSend2->setText(QApplication::translate("MainWindow", "T\303\266r\303\266l", 0, QApplication::UnicodeUTF8));
        Tabs->setTabText(Tabs->indexOf(Custom), QApplication::translate("MainWindow", "Egy\303\251ni \303\274zenetk\303\274ld\303\251s", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "F\303\241jl", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Be\303\241ll\303\255t\303\241sok", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
