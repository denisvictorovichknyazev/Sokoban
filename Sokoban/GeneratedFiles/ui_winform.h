/********************************************************************************
** Form generated from reading UI file 'winform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINFORM_H
#define UI_WINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinForm
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *WinForm)
    {
        if (WinForm->objectName().isEmpty())
            WinForm->setObjectName(QStringLiteral("WinForm"));
        WinForm->resize(165, 86);
        pushButton = new QPushButton(WinForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 60, 41, 23));
        label = new QLabel(WinForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 81, 16));
        label_2 = new QLabel(WinForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 161, 16));

        retranslateUi(WinForm);

        QMetaObject::connectSlotsByName(WinForm);
    } // setupUi

    void retranslateUi(QWidget *WinForm)
    {
        WinForm->setWindowTitle(QApplication::translate("WinForm", "You win", 0));
        pushButton->setText(QApplication::translate("WinForm", "Ok", 0));
        label->setText(QApplication::translate("WinForm", "Congratulations!", 0));
        label_2->setText(QApplication::translate("WinForm", "You have completed the level!", 0));
    } // retranslateUi

};

namespace Ui {
    class WinForm: public Ui_WinForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINFORM_H
