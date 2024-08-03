#include "cell.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>

Cell::Cell(QWidget *parent)
    : QLineEdit(parent), editable(true), selected(false), correct_answer(0)
{
    setAlignment(Qt::AlignCenter); // 设置文本居中
    setReadOnly(true); // 禁止用户直接输入
    setFixedSize(40, 40); // 设置固定大小
    qDebug() << "Cell created";
}

void Cell::setNumber(int number, bool fixed)
{
    // 设置格子中的数字，0 表示空
    setText(number == 0 ? "" : QString::number(number));
    editable = !fixed; // 固定格子不可编辑
    setReadOnly(fixed); // 设置是否只读

    // 设置格子样式
    if (fixed) {
        setStyleSheet("background-color: lightgrey; color: black;"); // 固定格子样式
    } else {
        setStyleSheet("background-color: white; color: black;"); // 可编辑格子样式
    }

    qDebug() << "Cell set to number:" << number << "fixed:" << fixed;
}

void Cell::setCorrectAnswer(int answer)
{
    // 设置格子的正确答案
    correct_answer = answer;
    qDebug() << "Cell correct answer set to:" << answer;
}

int Cell::number() const
{
    // 获取格子中的数字
    return text().isEmpty() ? 0 : text().toInt();
}

int Cell::correctAnswer() const
{
    // 获取格子的正确答案
    return correct_answer;
}

bool Cell::isEditable() const
{
    // 判断格子是否可编辑
    return editable;
}

bool Cell::isSelected() const
{
    // 判断格子是否被选中
    return selected;
}

void Cell::setSelected(bool selected)
{
    // 设置格子是否被选中
    this->selected = selected;
    if (selected) {
        setStyleSheet("background-color: yellow;"); // 选中的格子高亮显示
    } else if (editable) {
        setStyleSheet("background-color: white; color: black;"); // 可编辑格子样式
    } else {
        setStyleSheet("background-color: lightgrey; color: black;"); // 固定格子样式
    }
}

void Cell::mousePressEvent(QMouseEvent *event)
{
    if (editable) {
        // 如果格子可编辑，选中格子并发出点击信号
        setSelected(true);
        qDebug() << "Cell clicked and focused";
        emit clicked();
    } else {
        qDebug() << "Cell clicked but not editable";
    }
    QLineEdit::mousePressEvent(event);
}

void Cell::keyPressEvent(QKeyEvent *event)
{
    if (editable) {
        // 禁止键盘输入
        event->ignore();
    } else {
        QLineEdit::keyPressEvent(event);
    }
}
