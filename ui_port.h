/********************************************************************************
** Form generated from reading UI file 'port.ui'
**
** Created: Wed Apr 24 23:22:15 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORT_H
#define UI_PORT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_port
{
public:
    QGroupBox *groupBox;
    QLineEdit *Port;
    QPushButton *OK;
    QPushButton *Cancel;

    void setupUi(QDialog *port)
    {
        if (port->objectName().isEmpty())
            port->setObjectName(QString::fromUtf8("port"));
        port->resize(360, 235);
        groupBox = new QGroupBox(port);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 321, 151));
        Port = new QLineEdit(groupBox);
        Port->setObjectName(QString::fromUtf8("Port"));
        Port->setGeometry(QRect(60, 60, 201, 31));
        OK = new QPushButton(port);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setGeometry(QRect(60, 190, 75, 23));
        Cancel = new QPushButton(port);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(200, 190, 75, 23));

        retranslateUi(port);

        QMetaObject::connectSlotsByName(port);
    } // setupUi

    void retranslateUi(QDialog *port)
    {
        port->setWindowTitle(QApplication::translate("port", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("port", "Port Be\303\241ll\303\255t\303\241sa", 0, QApplication::UnicodeUTF8));
        Port->setPlaceholderText(QApplication::translate("port", " Port", 0, QApplication::UnicodeUTF8));
        OK->setText(QApplication::translate("port", "OK", 0, QApplication::UnicodeUTF8));
        Cancel->setText(QApplication::translate("port", "M\303\251gse", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class port: public Ui_port {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORT_H
