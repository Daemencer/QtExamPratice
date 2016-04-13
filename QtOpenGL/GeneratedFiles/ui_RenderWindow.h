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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "customopenglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_RenderWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    CustomOpenGLWidget *openGLWidget;
    QPushButton *translateXPosButton;

    void setupUi(QMainWindow *RenderWindow)
    {
        if (RenderWindow->objectName().isEmpty())
            RenderWindow->setObjectName(QStringLiteral("RenderWindow"));
        RenderWindow->resize(684, 544);
        centralwidget = new QWidget(RenderWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        openGLWidget = new CustomOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(openGLWidget, 3, 2, 2, 1);

        translateXPosButton = new QPushButton(centralwidget);
        translateXPosButton->setObjectName(QStringLiteral("translateXPosButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(translateXPosButton->sizePolicy().hasHeightForWidth());
        translateXPosButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(translateXPosButton, 3, 3, 1, 1);

        RenderWindow->setCentralWidget(centralwidget);

        retranslateUi(RenderWindow);
        QObject::connect(translateXPosButton, SIGNAL(clicked()), openGLWidget, SLOT(TranslateXPos()));

        QMetaObject::connectSlotsByName(RenderWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RenderWindow)
    {
        RenderWindow->setWindowTitle(QApplication::translate("RenderWindow", "MainWindow", 0));
        translateXPosButton->setText(QApplication::translate("RenderWindow", "TranslateXPos", 0));
    } // retranslateUi

};

namespace Ui {
    class RenderWindow: public Ui_RenderWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERWINDOW_H
