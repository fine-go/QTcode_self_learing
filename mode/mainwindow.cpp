#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *bar = menuBar();
    setMenuBar(bar);

    QMenu *menu = bar->addMenu("对话框");

    QAction *singal1 =menu-> addAction("模块对话框");
    QAction *singal2 =menu-> addAction("fei模块对话框");
    connect (singal1, &QAction::triggered,

             []()
            {
                QDialog motai;
                motai.setAttribute(Qt::WA_DeleteOnClose);
                motai.exec();

            }
    );

    connect (singal2, &QAction::triggered,

             []()
            {
                QDialog *feimotai = new QDialog;
                feimotai->setAttribute(Qt::WA_DeleteOnClose);
                feimotai->show();

            }
    );
}

MainWindow::~MainWindow()
{
}

