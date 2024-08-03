#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sudoku.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_level1Button_clicked(); // 处理关卡1按钮点击事件
    void on_level2Button_clicked(); // 处理关卡2按钮点击事件
    void on_level3Button_clicked(); // 处理关卡3按钮点击事件
    void handleNumberButton(int number); // 处理数字按钮点击事件
    void checkWin(); // 检查是否获胜
    void on_revealAnswerButton_clicked(); // 处理获取答案按钮点击事件
    void on_backToMainMenuButton_clicked(); // 处理返回开始界面按钮点击事件

private:
    Ui::MainWindow *ui;
    Sudoku *sudoku;
    void loadLevel(int level); // 加载关卡
};

#endif // MAINWINDOW_H
