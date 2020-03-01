#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(300,200);
    //菜单栏
    //创建的方法是new内置的否则会出现未知错误等问题
    QMenuBar *menubar =  menuBar();

    //添加菜单
    QMenu *pmenu = menubar->addMenu("文件");
    QMenu *pedit = menubar->addMenu("编辑");

    //添加菜单选项和添加动作，
    // 返回的是一个信号
    QAction *paction = pmenu->addAction("新建");
    QAction *popen =pmenu->addAction("打开");

    //将信号和动作连接
    connect(paction, &QAction::triggered,
            [=]()
            {
                qDebug() <<"已新建文件";
            }
            );
    connect(popen, &QAction::triggered,
            [=]()
            {
                qDebug() <<"已打开新文件";
            }
            );
    pmenu->addSeparator();//添加分割线


    //工具栏：实质上是菜单栏动作的快捷方式
    // 创建的方式 ：实质上是用方法创建ADD
    QToolBar *toolbar = addToolBar("toolbar");  //创建一个工具栏(一个大的title)

    //添加工具栏快捷键 -----添加快捷键实际上就是添加动作
    toolbar->addAction(paction);
    //类似于软件的工具栏小案件相当与一个按钮

    QPushButton *b1 = new QPushButton(this);
    //添加的按钮是用函数添加的不是福对象
    toolbar->addWidget(b1);
    b1->setText("新建");

    connect(b1, &QPushButton::released,
            [=]()
            {
                qDebug() <<"已新建文件";
                }
            );


    //状态栏
    QStatusBar *sbur = statusBar();
    //在状态栏添加的是QLabel类型的变量
    QLabel *label = new QLabel(this);
    label->setText("hhhhhhh");
    //默认是从左往右添加标签
    sbur->addWidget(label);
    //可以在函数里面动态分配的空间里面添加
    sbur->addWidget(new QLabel("2", this));
    //也可以反着添加
    sbur->addPermanentWidget(new QLabel("s", this));

    //核心控件
    //文本编辑区
    QTextEdit *text = new QTextEdit(this);
    setCentralWidget(text);

    //浮动窗口
    QDockWidget *d = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,d );


}

MainWindow::~MainWindow()
{
}

