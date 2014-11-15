/********************************************************************************
** Form generated from reading UI file 'nevjegy.ui'
**
** Created: Mon May 6 22:47:35 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEVJEGY_H
#define UI_NEVJEGY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_nevjegy
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *nevjegy)
    {
        if (nevjegy->objectName().isEmpty())
            nevjegy->setObjectName(QString::fromUtf8("nevjegy"));
        nevjegy->resize(240, 160);
        buttonBox = new QDialogButtonBox(nevjegy);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(80, 110, 81, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        label = new QLabel(nevjegy);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 141, 31));
        label_2 = new QLabel(nevjegy);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 70, 151, 20));

        retranslateUi(nevjegy);
        QObject::connect(buttonBox, SIGNAL(accepted()), nevjegy, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), nevjegy, SLOT(reject()));

        QMetaObject::connectSlotsByName(nevjegy);
    } // setupUi

    void retranslateUi(QDialog *nevjegy)
    {
        nevjegy->setWindowTitle(QApplication::translate("nevjegy", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("nevjegy", "Verzi\303\263sz\303\241m:      1.0", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("nevjegy", "K\303\251sz\303\255tette:        Nagy Krisztina", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class nevjegy: public Ui_nevjegy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEVJEGY_H
