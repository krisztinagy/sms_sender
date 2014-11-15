/********************************************************************************
** Form generated from reading UI file 'egyeniuzenet.ui'
**
** Created: Sat Apr 20 16:11:13 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EGYENIUZENET_H
#define UI_EGYENIUZENET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_egyeniuzenet
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *uzenet;

    void setupUi(QDialog *egyeniuzenet)
    {
        if (egyeniuzenet->objectName().isEmpty())
            egyeniuzenet->setObjectName(QString::fromUtf8("egyeniuzenet"));
        egyeniuzenet->resize(251, 131);
        buttonBox = new QDialogButtonBox(egyeniuzenet);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 70, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        uzenet = new QComboBox(egyeniuzenet);
        uzenet->setObjectName(QString::fromUtf8("uzenet"));
        uzenet->setGeometry(QRect(40, 30, 161, 22));

        retranslateUi(egyeniuzenet);
        QObject::connect(buttonBox, SIGNAL(accepted()), egyeniuzenet, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), egyeniuzenet, SLOT(reject()));

        QMetaObject::connectSlotsByName(egyeniuzenet);
    } // setupUi

    void retranslateUi(QDialog *egyeniuzenet)
    {
        egyeniuzenet->setWindowTitle(QApplication::translate("egyeniuzenet", "\303\234zenet kiv\303\241laszt\303\241sa", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class egyeniuzenet: public Ui_egyeniuzenet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EGYENIUZENET_H
