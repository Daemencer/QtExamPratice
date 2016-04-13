/********************************************************************************
** Form generated from reading UI file 'RenderWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDERWINDOW_H
#define UI_RENDERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "customopenglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_RenderWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    CustomOpenGLWidget *openGLWidget;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;

    void setupUi(QMainWindow *RenderWindow)
    {
        if (RenderWindow->objectName().isEmpty())
            RenderWindow->setObjectName(QStringLiteral("RenderWindow"));
        RenderWindow->resize(1095, 600);
        centralwidget = new QWidget(RenderWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        openGLWidget = new CustomOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));

        gridLayout->addWidget(openGLWidget, 5, 2, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(16777215, 30));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);


        gridLayout->addWidget(frame, 0, 2, 1, 1);

        RenderWindow->setCentralWidget(centralwidget);

        retranslateUi(RenderWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), openGLWidget, SLOT(ApplyRandomRed()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), openGLWidget, SLOT(ApplyRandomGreen()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), openGLWidget, SLOT(ApplyRandomBlue()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), openGLWidget, SLOT(ApplyDefaultColor()));

        QMetaObject::connectSlotsByName(RenderWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RenderWindow)
    {
        RenderWindow->setWindowTitle(QApplication::translate("RenderWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("RenderWindow", "Random Red", 0));
        pushButton_2->setText(QApplication::translate("RenderWindow", "Random Green", 0));
        pushButton_3->setText(QApplication::translate("RenderWindow", "Random Blue", 0));
        pushButton_4->setText(QApplication::translate("RenderWindow", "Default Color", 0));
    } // retranslateUi

};

namespace Ui {
    class RenderWindow: public Ui_RenderWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERWINDOW_H
