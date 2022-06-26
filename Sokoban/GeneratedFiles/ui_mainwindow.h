/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QToolButton *editButton;
    QToolButton *saveButton;
    QToolButton *loadButton;
    QToolButton *exitButton;
    QToolButton *homeButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(543, 346);
        MainWindow->setMinimumSize(QSize(543, 346));
        MainWindow->setMaximumSize(QSize(543, 346));
        MainWindow->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QStringLiteral("../../Resorses/MainIcon.gif"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 521, 311));
        editButton = new QToolButton(centralWidget);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(10, 0, 25, 19));
        editButton->setCursor(QCursor(Qt::PointingHandCursor));
        editButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        saveButton = new QToolButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(90, 0, 25, 19));
        saveButton->setCursor(QCursor(Qt::PointingHandCursor));
        loadButton = new QToolButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(50, 0, 25, 19));
        loadButton->setCursor(QCursor(Qt::PointingHandCursor));
        exitButton = new QToolButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(510, 0, 25, 19));
        exitButton->setCursor(QCursor(Qt::PointingHandCursor));
        homeButton = new QToolButton(centralWidget);
        homeButton->setObjectName(QStringLiteral("homeButton"));
        homeButton->setGeometry(QRect(130, 0, 25, 19));
        homeButton->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Sokoban", 0));
#ifndef QT_NO_TOOLTIP
        editButton->setToolTip(QApplication::translate("MainWindow", "Create level", 0));
#endif // QT_NO_TOOLTIP
        editButton->setText(QApplication::translate("MainWindow", "Edit level", 0));
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("MainWindow", "Save progress", 0));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0));
#ifndef QT_NO_TOOLTIP
        loadButton->setToolTip(QApplication::translate("MainWindow", "Load level", 0));
#endif // QT_NO_TOOLTIP
        loadButton->setText(QApplication::translate("MainWindow", "Load", 0));
#ifndef QT_NO_TOOLTIP
        exitButton->setToolTip(QApplication::translate("MainWindow", "Exit", 0));
#endif // QT_NO_TOOLTIP
        exitButton->setText(QApplication::translate("MainWindow", "Exit", 0));
#ifndef QT_NO_TOOLTIP
        homeButton->setToolTip(QApplication::translate("MainWindow", "Home", 0));
#endif // QT_NO_TOOLTIP
        homeButton->setText(QApplication::translate("MainWindow", "Home", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
