/********************************************************************************
** Form generated from reading UI file 'portset.ui'
**
** Created: Thu Apr 25 00:03:01 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTSET_H
#define UI_PORTSET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_portset
{
public:
    QGroupBox *groupBox;
    QLineEdit *Port;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *portset)
    {
        if (portset->objectName().isEmpty())
            portset->setObjectName(QString::fromUtf8("portset"));
        portset->resize(308, 169);
        groupBox = new QGroupBox(portset);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 271, 141));
        Port = new QLineEdit(groupBox);
        Port->setObjectName(QString::fromUtf8("Port"));
        Port->setGeometry(QRect(30, 40, 221, 31));
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(50, 90, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(portset);
        QObject::connect(buttonBox, SIGNAL(accepted()), portset, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), portset, SLOT(reject()));

        QMetaObject::connectSlotsByName(portset);
    } // setupUi

    void retranslateUi(QDialog *portset)
    {
        portset->setWindowTitle(QApplication::translate("portset", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("portset", "Port be\303\241ll\303\255t\303\241sa", 0, QApplication::UnicodeUTF8));
        Port->setText(QString());
        Port->setPlaceholderText(QApplication::translate("portset", "Port", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class portset: public Ui_portset {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTSET_H
