/********************************************************************************
** Form generated from reading UI file 'clienwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClienWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditIp;
    QPushButton *pushButtonConnect;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QTextEdit *textEdit;
    QProgressBar *progressBar;

    void setupUi(QWidget *ClienWidget)
    {
        if (ClienWidget->objectName().isEmpty())
            ClienWidget->setObjectName(QString::fromUtf8("ClienWidget"));
        ClienWidget->resize(400, 300);
        gridLayout = new QGridLayout(ClienWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ClienWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(60, 0));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditIp = new QLineEdit(ClienWidget);
        lineEditIp->setObjectName(QString::fromUtf8("lineEditIp"));

        gridLayout->addWidget(lineEditIp, 0, 1, 1, 1);

        pushButtonConnect = new QPushButton(ClienWidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));

        gridLayout->addWidget(pushButtonConnect, 0, 2, 2, 1);

        label_2 = new QLabel(ClienWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditPort = new QLineEdit(ClienWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 1, 1, 1, 1);

        textEdit = new QTextEdit(ClienWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 2, 0, 1, 2);

        progressBar = new QProgressBar(ClienWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 3, 0, 1, 3);


        retranslateUi(ClienWidget);

        QMetaObject::connectSlotsByName(ClienWidget);
    } // setupUi

    void retranslateUi(QWidget *ClienWidget)
    {
        ClienWidget->setWindowTitle(QApplication::translate("ClienWidget", "Form", nullptr));
        label->setText(QApplication::translate("ClienWidget", "\346\234\215\345\212\241\345\231\250Ip", nullptr));
        lineEditIp->setText(QApplication::translate("ClienWidget", "127.0.0.1", nullptr));
        pushButtonConnect->setText(QApplication::translate("ClienWidget", "connect", nullptr));
        label_2->setText(QApplication::translate("ClienWidget", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", nullptr));
        lineEditPort->setText(QApplication::translate("ClienWidget", "8888", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClienWidget: public Ui_ClienWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENWIDGET_H
