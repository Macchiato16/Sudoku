#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.h"
#include <QSignalMapper>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , sudoku(nullptr)
{
    ui->setupUi(this); // 设置UI
    qDebug() << "MainWindow setup completed";

    // 设置按键映射器，用于处理数字按钮点击事件
    QSignalMapper *signalMapper = new QSignalMapper(this);
    connect(ui->button1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->button2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->button3, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->button4, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->button5, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->button6, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->button7, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->button8, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->button9, SIGNAL(clicked()), signalMapper, SLOT(map()));

    signalMapper->setMapping(ui->button1, 1);
    signalMapper->setMapping(ui->button2, 2);
    signalMapper->setMapping(ui->button3, 3);
    signalMapper->setMapping(ui->button4, 4);
    signalMapper->setMapping(ui->button5, 5);
    signalMapper->setMapping(ui->button6, 6);
    signalMapper->setMapping(ui->button7, 7);
    signalMapper->setMapping(ui->button8, 8);
    signalMapper->setMapping(ui->button9, 9);

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(handleNumberButton(int)));

    // 连接关卡按钮点击事件到槽函数
    connect(ui->level1Button, &QPushButton::clicked, this, &MainWindow::on_level1Button_clicked);
    connect(ui->level2Button, &QPushButton::clicked, this, &MainWindow::on_level2Button_clicked);
    connect(ui->level3Button, &QPushButton::clicked, this, &MainWindow::on_level3Button_clicked);

    // 连接获取答案按钮点击事件到槽函数
    connect(ui->revealAnswerButton, &QPushButton::clicked, this, &MainWindow::on_revealAnswerButton_clicked);

    // 连接返回开始界面按钮点击事件到槽函数
    connect(ui->backToMainMenuButton, &QPushButton::clicked, this, &MainWindow::on_backToMainMenuButton_clicked);

    qDebug() << "Signal and slot connections established";
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sudoku;
}

void MainWindow::on_level1Button_clicked()
{
    qDebug() << "Level 1 button clicked";
    loadLevel(1); // 加载关卡1
    ui->stackedWidget->setCurrentWidget(ui->gamePage); // 切换到游戏界面
}

void MainWindow::on_level2Button_clicked()
{
    qDebug() << "Level 2 button clicked";
    loadLevel(2); // 加载关卡2
    ui->stackedWidget->setCurrentWidget(ui->gamePage); // 切换到游戏界面
}

void MainWindow::on_level3Button_clicked()
{
    qDebug() << "Level 3 button clicked";
    loadLevel(3); // 加载关卡3
    ui->stackedWidget->setCurrentWidget(ui->gamePage); // 切换到游戏界面
}

void MainWindow::handleNumberButton(int number)
{
    qDebug() << "Number button clicked:" << number;
    if (sudoku) {
        sudoku->setNumber(number); // 设置选中格子的数字
        checkWin(); // 检查是否获胜
    }
}

void MainWindow::loadLevel(int level)
{
    qDebug() << "Loading level:" << level;
    if (sudoku) {
        delete sudoku;
        sudoku = nullptr;
    }
    sudoku = new Sudoku(level, this); // 创建数独对象
    ui->gridLayout->addWidget(sudoku); // 将数独对象添加到布局中
    qDebug() << "Level loaded and added to grid layout";
}

void MainWindow::checkWin()
{
    if (sudoku && sudoku->checkWin()) {
        // 如果所有可编辑格子的内容都为正确答案，弹出提示框并返回开始界面
        QMessageBox::information(this, "胜利", "恭喜你，成功完成数独！");
        ui->stackedWidget->setCurrentWidget(ui->mainPage); // 切换到开始界面
    }
}

void MainWindow::on_revealAnswerButton_clicked()
{
    qDebug() << "Reveal Answer button clicked";
    if (sudoku) {
        sudoku->revealAnswer(); // 显示选中格子的正确答案
        checkWin(); // 检查是否获胜
    }
}

void MainWindow::on_backToMainMenuButton_clicked()
{
    // 切换到开始界面
    ui->stackedWidget->setCurrentWidget(ui->mainPage);
}
