#ifndef CELL_H
#define CELL_H

#include <QWidget>
#include <QLineEdit>

class Cell : public QLineEdit
{
    Q_OBJECT

public:
    explicit Cell(QWidget *parent = nullptr);
    void setNumber(int number, bool fixed = false); // 设置格子中的数字
    void setCorrectAnswer(int answer); // 设置格子的正确答案
    int number() const; // 获取格子中的数字
    int correctAnswer() const; // 获取格子的正确答案
    bool isEditable() const; // 判断格子是否可编辑
    bool isSelected() const; // 判断格子是否被选中
    void setSelected(bool selected); // 设置格子是否被选中

signals:
    void clicked(); // 点击信号

protected:
    void mousePressEvent(QMouseEvent *event) override; // 处理鼠标点击事件
    void keyPressEvent(QKeyEvent *event) override; // 禁用键盘输入

private:
    bool editable; // 是否可编辑
    bool selected; // 是否被选中
    int correct_answer; // 正确答案
};

#endif // CELL_H
