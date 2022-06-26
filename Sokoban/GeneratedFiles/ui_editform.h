/********************************************************************************
** Form generated from reading UI file 'editform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITFORM_H
#define UI_EDITFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditForm
{
public:
    QGraphicsView *graphicsView;
    QToolButton *hero;
    QToolButton *wall;
    QToolButton *box;
    QToolButton *save;
    QToolButton *toolButton_5;
    QToolButton *toolButton;

    void setupUi(QWidget *EditForm)
    {
        if (EditForm->objectName().isEmpty())
            EditForm->setObjectName(QStringLiteral("EditForm"));
        EditForm->resize(543, 346);
        EditForm->setMinimumSize(QSize(543, 346));
        EditForm->setMaximumSize(QSize(543, 346));
        QIcon icon;
        icon.addFile(QStringLiteral("Sokoban.ico"), QSize(), QIcon::Normal, QIcon::Off);
        EditForm->setWindowIcon(icon);
        graphicsView = new QGraphicsView(EditForm);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 521, 311));
        hero = new QToolButton(EditForm);
        hero->setObjectName(QStringLiteral("hero"));
        hero->setGeometry(QRect(10, 0, 25, 19));
        hero->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../Resorses/MarioStay.gif"), QSize(), QIcon::Normal, QIcon::Off);
        hero->setIcon(icon1);
        wall = new QToolButton(EditForm);
        wall->setObjectName(QStringLiteral("wall"));
        wall->setGeometry(QRect(50, 0, 25, 19));
        wall->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../Resorses/wall.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        wall->setIcon(icon2);
        box = new QToolButton(EditForm);
        box->setObjectName(QStringLiteral("box"));
        box->setGeometry(QRect(90, 0, 25, 19));
        box->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../Resorses/box.gif"), QSize(), QIcon::Normal, QIcon::Off);
        box->setIcon(icon3);
        save = new QToolButton(EditForm);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(170, 0, 25, 19));
        save->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../../Resorses/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        save->setIcon(icon4);
        toolButton_5 = new QToolButton(EditForm);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(510, 0, 25, 19));
        toolButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../../Resorses/Exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon5);
        toolButton = new QToolButton(EditForm);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(130, 0, 25, 19));
        toolButton->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../../Resorses/undored.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon6);

        retranslateUi(EditForm);

        QMetaObject::connectSlotsByName(EditForm);
    } // setupUi

    void retranslateUi(QWidget *EditForm)
    {
        EditForm->setWindowTitle(QApplication::translate("EditForm", "Create level", 0));
        hero->setText(QApplication::translate("EditForm", "...", 0));
        wall->setText(QApplication::translate("EditForm", "...", 0));
        box->setText(QApplication::translate("EditForm", "...", 0));
        save->setText(QApplication::translate("EditForm", "...", 0));
        toolButton_5->setText(QApplication::translate("EditForm", "...", 0));
        toolButton->setText(QApplication::translate("EditForm", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class EditForm: public Ui_EditForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITFORM_H
