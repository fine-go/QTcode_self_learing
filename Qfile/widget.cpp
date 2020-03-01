#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QFileInfo> //读取文件信息
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open", "../",  "TxT(*.txt)");
    if (path.isEmpty() == false)
    {
        //创建文件对象
        QFile file(path);
       bool isOK =  file.open(QIODevice::ReadOnly);

       if(isOK == true)
       {

#if 0
          //读文件
          //默认是只能读取utf8编码要想改变智能通过文本流来改写
           // 一次性全堵
           QByteArray text = file.readAll();
           ui->textEdit->setText(text);
#endif

           QByteArray array;

           while (file.atEnd() == false)
           {
               array += file.readLine();
           }

           ui->textEdit->setText(array);
       }

       //打开文件之后一定要关闭
       file.close();

       QFileInfo info = QFileInfo(path);
       qDebug() << "文件名" << info.fileName().toUtf8().data();
       qDebug() << "文件后缀" << info.suffix();
       qDebug() << "文件大小" << (info.size())/1024;
       qDebug() << "文件创建时间" << info.created().toString("yyyy-MM-DD hh-mm-ss");

    }
}

void Widget::on_pushButton_2_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "save", "../", "TXT(*.txt)");
    if (path.isEmpty() == false)
    {
        QFile file; //先创建一个对象文件

        //关联对象与文件， 实质上是匹配文件和对象关系
        file.setFileName(path);
        bool isok = file.open(QIODevice::WriteOnly);
        if(isok == true)
        {
            //获取编辑区内容
            QString str = ui->textEdit->toPlainText();
            //写文件
            //1.把QString -> QBtyearray
            //file.write(str.toUtf8());

            //AString -> string ->char *
            //toStdString -> std string .data() ->char *
            file.write(str.toStdString().data());

            //QString -> QByteArray
            QString buf = "123";
            QByteArray a = buf.toUtf8(); //中文转
            a = buf.toLocal8Bit(); // 转本地编码

            //QByteArray -> char *
            char *b = a.data();

            // char * —> QByteArray
            char *p = "123";
            QString m = QString(p);



        }
        file.close();
    }
}
