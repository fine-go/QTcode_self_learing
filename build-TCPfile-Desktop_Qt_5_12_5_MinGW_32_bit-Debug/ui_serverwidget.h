/********************************************************************************
** Form generated from reading UI file 'serverwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWIDGET_H
#define UI_SERVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWidget
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QTextEdit *textEdit;
    QGridLayout *gridLayout;
    QPushButton *pushButtonFile;
    QPushButton *pushButtonclose;
    QPushButton *pushButtonconnect;
    QPushButton *pushButtonSend;
    QProgressBar *progressBar;

    void setupUi(QWidget *ServerWidget)
    {
        if (ServerWidget->objectName().isEmpty())
            ServerWidget->setObjectName(QString::fromUtf8("ServerWidget"));
        ServerWidget->resize(667, 433);
        gridLayout_2 = new QGridLayout(ServerWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(ServerWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setIndent(-1);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        textEdit = new QTextEdit(ServerWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout_2->addWidget(textEdit, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButtonFile = new QPushButton(ServerWidget);
        pushButtonFile->setObjectName(QString::fromUtf8("pushButtonFile"));

        gridLayout->addWidget(pushButtonFile, 1, 0, 1, 1);

        pushButtonclose = new QPushButton(ServerWidget);
        pushButtonclose->setObjectName(QString::fromUtf8("pushButtonclose"));

        gridLayout->addWidget(pushButtonclose, 1, 1, 1, 1);

        pushButtonconnect = new QPushButton(ServerWidget);
        pushButtonconnect->setObjectName(QString::fromUtf8("pushButtonconnect"));

        gridLayout->addWidget(pushButtonconnect, 1, 2, 1, 1);

        pushButtonSend = new QPushButton(ServerWidget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));

        gridLayout->addWidget(pushButtonSend, 1, 3, 1, 1);

        progressBar = new QProgressBar(ServerWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 0, 0, 1, 4);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 2);


        retranslateUi(ServerWidget);

        QMetaObject::connectSlotsByName(ServerWidget);
    } // setupUi

    void retranslateUi(QWidget *ServerWidget)
    {
        ServerWidget->setWindowTitle(QApplication::translate("ServerWidget", "ServerWidget", nullptr));
        label->setText(QApplication::translate("ServerWidget", "test", nullptr));
        pushButtonFile->setText(QApplication::translate("ServerWidget", "openfile", nullptr));
        pushButtonclose->setText(QApplication::translate("ServerWidget", "close", nullptr));
        pushButtonconnect->setText(QApplication::translate("ServerWidget", "connect", nullptr));
        pushButtonSend->setText(QApplication::translate("ServerWidget", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWidget: public Ui_ServerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWIDGET_H
