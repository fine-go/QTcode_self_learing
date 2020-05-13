/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myWidget
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QTextEdit *textEditwrite;
    QTextEdit *textEditread;
    QGridLayout *gridLayout_2;
    QProgressBar *progressBar;
    QPushButton *pushBottonsend;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonclose;

    void setupUi(QWidget *myWidget)
    {
        if (myWidget->objectName().isEmpty())
            myWidget->setObjectName(QString::fromUtf8("myWidget"));
        myWidget->resize(767, 714);
        gridLayout_3 = new QGridLayout(myWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEditwrite = new QTextEdit(myWidget);
        textEditwrite->setObjectName(QString::fromUtf8("textEditwrite"));

        gridLayout->addWidget(textEditwrite, 2, 1, 1, 1);

        textEditread = new QTextEdit(myWidget);
        textEditread->setObjectName(QString::fromUtf8("textEditread"));
        textEditread->setReadOnly(true);

        gridLayout->addWidget(textEditread, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        progressBar = new QProgressBar(myWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout_2->addWidget(progressBar, 0, 0, 1, 3);

        pushBottonsend = new QPushButton(myWidget);
        pushBottonsend->setObjectName(QString::fromUtf8("pushBottonsend"));

        gridLayout_2->addWidget(pushBottonsend, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(584, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 1, 1, 1);

        pushButtonclose = new QPushButton(myWidget);
        pushButtonclose->setObjectName(QString::fromUtf8("pushButtonclose"));

        gridLayout_2->addWidget(pushButtonclose, 1, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);


        retranslateUi(myWidget);

        QMetaObject::connectSlotsByName(myWidget);
    } // setupUi

    void retranslateUi(QWidget *myWidget)
    {
        myWidget->setWindowTitle(QApplication::translate("myWidget", "myWidget", nullptr));
        pushBottonsend->setText(QApplication::translate("myWidget", "send", nullptr));
        pushButtonclose->setText(QApplication::translate("myWidget", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myWidget: public Ui_myWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
