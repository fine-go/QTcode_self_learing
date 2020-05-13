/********************************************************************************
** Form generated from reading UI file 'severwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEVERWIDGET_H
#define UI_SEVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SeverWidget
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEditread;
    QTextEdit *textEditWrite;
    QPushButton *pushButtonsend;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonclose;

    void setupUi(QWidget *SeverWidget)
    {
        if (SeverWidget->objectName().isEmpty())
            SeverWidget->setObjectName(QString::fromUtf8("SeverWidget"));
        SeverWidget->resize(800, 600);
        gridLayout = new QGridLayout(SeverWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEditread = new QTextEdit(SeverWidget);
        textEditread->setObjectName(QString::fromUtf8("textEditread"));
        textEditread->setReadOnly(true);

        gridLayout->addWidget(textEditread, 0, 0, 1, 3);

        textEditWrite = new QTextEdit(SeverWidget);
        textEditWrite->setObjectName(QString::fromUtf8("textEditWrite"));

        gridLayout->addWidget(textEditWrite, 1, 0, 1, 3);

        pushButtonsend = new QPushButton(SeverWidget);
        pushButtonsend->setObjectName(QString::fromUtf8("pushButtonsend"));

        gridLayout->addWidget(pushButtonsend, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(617, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 1, 1, 1);

        pushButtonclose = new QPushButton(SeverWidget);
        pushButtonclose->setObjectName(QString::fromUtf8("pushButtonclose"));

        gridLayout->addWidget(pushButtonclose, 2, 2, 1, 1);


        retranslateUi(SeverWidget);

        QMetaObject::connectSlotsByName(SeverWidget);
    } // setupUi

    void retranslateUi(QWidget *SeverWidget)
    {
        SeverWidget->setWindowTitle(QApplication::translate("SeverWidget", "SeverWidget", nullptr));
        pushButtonsend->setText(QApplication::translate("SeverWidget", "send", nullptr));
        pushButtonclose->setText(QApplication::translate("SeverWidget", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SeverWidget: public Ui_SeverWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEVERWIDGET_H
