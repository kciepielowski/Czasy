/********************************************************************************
** Form generated from reading UI file 'przyklczasy.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRZYKLCZASY_H
#define UI_PRZYKLCZASY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrzyklczasyClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *rPast;
    QRadioButton *rPresent;
    QRadioButton *rFuture;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rSimple;
    QRadioButton *rContinuous;
    QRadioButton *rPerfect;
    QRadioButton *rPerfectC;
    QRadioButton *rPerfectP;
    QPushButton *pOK;
    QLineEdit *lZdanie;
    QLabel *lNoweZdanie;

    void setupUi(QMainWindow *PrzyklczasyClass)
    {
        if (PrzyklczasyClass->objectName().isEmpty())
            PrzyklczasyClass->setObjectName(QString::fromUtf8("PrzyklczasyClass"));
        PrzyklczasyClass->resize(600, 296);
        centralWidget = new QWidget(PrzyklczasyClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rPast = new QRadioButton(groupBox);
        rPast->setObjectName(QString::fromUtf8("rPast"));
        rPast->setChecked(true);

        verticalLayout->addWidget(rPast);

        rPresent = new QRadioButton(groupBox);
        rPresent->setObjectName(QString::fromUtf8("rPresent"));

        verticalLayout->addWidget(rPresent);

        rFuture = new QRadioButton(groupBox);
        rFuture->setObjectName(QString::fromUtf8("rFuture"));

        verticalLayout->addWidget(rFuture);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        rSimple = new QRadioButton(groupBox_2);
        rSimple->setObjectName(QString::fromUtf8("rSimple"));
        rSimple->setChecked(true);

        verticalLayout_2->addWidget(rSimple);

        rContinuous = new QRadioButton(groupBox_2);
        rContinuous->setObjectName(QString::fromUtf8("rContinuous"));

        verticalLayout_2->addWidget(rContinuous);

        rPerfect = new QRadioButton(groupBox_2);
        rPerfect->setObjectName(QString::fromUtf8("rPerfect"));

        verticalLayout_2->addWidget(rPerfect);

        rPerfectC = new QRadioButton(groupBox_2);
        rPerfectC->setObjectName(QString::fromUtf8("rPerfectC"));

        verticalLayout_2->addWidget(rPerfectC);

        rPerfectP = new QRadioButton(groupBox_2);
        rPerfectP->setObjectName(QString::fromUtf8("rPerfectP"));
        rPerfectP->setEnabled(false);

        verticalLayout_2->addWidget(rPerfectP);


        horizontalLayout->addWidget(groupBox_2);

        pOK = new QPushButton(groupBox_3);
        pOK->setObjectName(QString::fromUtf8("pOK"));

        horizontalLayout->addWidget(pOK);


        verticalLayout_3->addWidget(groupBox_3);

        lZdanie = new QLineEdit(centralWidget);
        lZdanie->setObjectName(QString::fromUtf8("lZdanie"));

        verticalLayout_3->addWidget(lZdanie);

        lNoweZdanie = new QLabel(centralWidget);
        lNoweZdanie->setObjectName(QString::fromUtf8("lNoweZdanie"));

        verticalLayout_3->addWidget(lNoweZdanie);

        PrzyklczasyClass->setCentralWidget(centralWidget);

        retranslateUi(PrzyklczasyClass);

        QMetaObject::connectSlotsByName(PrzyklczasyClass);
    } // setupUi

    void retranslateUi(QMainWindow *PrzyklczasyClass)
    {
        PrzyklczasyClass->setWindowTitle(QApplication::translate("PrzyklczasyClass", "Przekszta\305\202cacz czas\303\263w angielskich", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        groupBox->setTitle(QString());
        rPast->setText(QApplication::translate("PrzyklczasyClass", "Past", 0, QApplication::UnicodeUTF8));
        rPresent->setText(QApplication::translate("PrzyklczasyClass", "Present", 0, QApplication::UnicodeUTF8));
        rFuture->setText(QApplication::translate("PrzyklczasyClass", "Future", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        rSimple->setText(QApplication::translate("PrzyklczasyClass", "Simple", 0, QApplication::UnicodeUTF8));
        rContinuous->setText(QApplication::translate("PrzyklczasyClass", "Continuous", 0, QApplication::UnicodeUTF8));
        rPerfect->setText(QApplication::translate("PrzyklczasyClass", "Perfect", 0, QApplication::UnicodeUTF8));
        rPerfectC->setText(QApplication::translate("PrzyklczasyClass", "Perfect Continuous", 0, QApplication::UnicodeUTF8));
        rPerfectP->setText(QApplication::translate("PrzyklczasyClass", "Perfect In The Past", 0, QApplication::UnicodeUTF8));
        pOK->setText(QApplication::translate("PrzyklczasyClass", "OK", 0, QApplication::UnicodeUTF8));
        lNoweZdanie->setText(QApplication::translate("PrzyklczasyClass", "Tu b\304\231dzie wynik.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PrzyklczasyClass: public Ui_PrzyklczasyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRZYKLCZASY_H
