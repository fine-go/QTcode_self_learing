/********************************************************************************
** Form generated from reading UI file 'clienwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENWIDGET_H
#define UI_CLIENWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClienWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QLabel *label_2;
    QLineEdit *lineEditIP;
    QTextEdit *textEditRead;
    QTextEdit *textEditWrite;
    QPushButton *pushButtonsend;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonclose;
    QPushButton *pushButtonConnect;

    void setupUi(QWidget *ClienWidget)
    {
        if (ClienWidget->objectName().isEmpty())
            ClienWidget->setObjectName(QString::fromUtf8("ClienWidget"));
        ClienWidget->resize(630, 555);
        gridLayout = new QGridLayout(ClienWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelPort = new QLabel(ClienWidget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));

        gridLayout->addWidget(labelPort, 0, 0, 1, 1);

        lineEditPort = new QLineEdit(ClienWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 0, 1, 1, 2);

        label_2 = new QLabel(ClienWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditIP = new QLineEdit(ClienWidget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));

        gridLayout->addWidget(lineEditIP, 1, 1, 1, 2);

        textEditRead = new QTextEdit(ClienWidget);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));
        textEditRead->setReadOnly(true);

        gridLayout->addWidget(textEditRead, 2, 0, 1, 4);

        textEditWrite = new QTextEdit(ClienWidget);
        textEditWrite->setObjectName(QString::fromUtf8("textEditWrite"));

        gridLayout->addWidget(textEditWrite, 3, 0, 1, 4);

        pushButtonsend = new QPushButton(ClienWidget);
        pushButtonsend->setObjectName(QString::fromUtf8("pushButtonsend"));

        gridLayout->addWidget(pushButtonsend, 4, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(447, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 2, 1, 1);

        pushButtonclose = new QPushButton(ClienWidget);
        pushButtonclose->setObjectName(QString::fromUtf8("pushButtonclose"));

        gridLayout->addWidget(pushButtonclose, 4, 3, 1, 1);

        pushButtonConnect = new QPushButton(ClienWidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));

        gridLayout->addWidget(pushButtonConnect, 0, 3, 2, 1);


        retranslateUi(ClienWidget);

        QMetaObject::connectSlotsByName(ClienWidget);
    } // setupUi

    void retranslateUi(QWidget *ClienWidget)
    {
        ClienWidget->setWindowTitle(QApplication::translate("ClienWidget", "Form", nullptr));
        labelPort->setText(QApplication::translate("ClienWidget", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        lineEditPort->setText(QApplication::translate("ClienWidget", "8888", nullptr));
        label_2->setText(QApplication::translate("ClienWidget", "Ip", nullptr));
        lineEditIP->setText(QApplication::translate("ClienWidget", "127.0.0.1", nullptr));
        pushButtonsend->setText(QApplication::translate("ClienWidget", "send", nullptr));
        pushButtonclose->setText(QApplication::translate("ClienWidget", "close", nullptr));
        pushButtonConnect->setText(QApplication::translate("ClienWidget", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClienWidget: public Ui_ClienWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENWIDGET_H
