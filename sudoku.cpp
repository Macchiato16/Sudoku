#include "sudoku.h"
#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Sudoku::Sudoku(int level, QWidget *parent)
    : QWidget(parent), selectedCell(nullptr)
{
    QGridLayout *layout = new QGridLayout(this); // 创建网格布局
    layout->setSpacing(1); // 设置间距
    for (int row = 0; row < 9; ++row) {
        std::vector<Cell*> rowCells;
        for (int col = 0; col < 9; ++col) {
            Cell *cell = new Cell(this);
            cell->setFixedSize(40, 40); // 设置固定大小
            layout->addWidget(cell, row, col); // 将格子添加到布局中
            rowCells.push_back(cell);
            // 连接格子的点击信号和处理函数
            connect(cell, &Cell::clicked, [this, cell, row, col]() {
                if (selectedCell) {
                    selectedCell->setSelected(false); // 取消之前选中格子的选中状态
                }
                selectedCell = cell; // 设置当前选中的格子
                selectedCell->setSelected(true); // 设置当前格子为选中状态
                selectedCell->setProperty("row", row); // 设置行属性
                selectedCell->setProperty("col", col); // 设置列属性
            });
            qDebug() << "Cell at (" << row << "," << col << ") created";
        }
        grid.push_back(rowCells); // 将当前行添加到网格中
    }
    setLayout(layout); // 设置布局
    qDebug() << "Sudoku grid layout created";
    loadLevel(level); // 加载关卡
}

void Sudoku::loadLevel(int level)
{
    QString filename = QString(":/level/res/level%1.txt").arg(level); // 构建关卡文件名
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open level file:" << filename;
        return;
    }

    QTextStream in(&file);
    // 读取初始数独数据
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            QString numStr;
            in >> numStr;
            int num = numStr.toInt();
            qDebug() << "Read initial number at (" << row << "," << col << "):" << num;
            if (num != 0) {
                grid[row][col]->setNumber(num, true); // 设置初始数字
            }
        }
    }

    // 跳过空行
    in.readLine();
    in.readLine();

    // 读取正确答案
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            QString answerStr;
            in >> answerStr;
            int answer = answerStr.toInt();
            grid[row][col]->setCorrectAnswer(answer); // 设置正确答案
            qDebug() << "Read correct answer at (" << row << "," << col << "):" << answer;
        }
    }
    qDebug() << "Level" << level << "loaded";
}

void Sudoku::setNumber(int number)
{
    if (selectedCell && selectedCell->isEditable()) {
        selectedCell->setNumber(number); // 设置选中格子的数字
        qDebug() << "Set number" << number << "at selected cell";
    }
}

void Sudoku::revealAnswer()
{
    if (selectedCell && selectedCell->isEditable()) {
        selectedCell->setNumber(selectedCell->correctAnswer()); // 显示选中格子的正确答案
        qDebug() << "Revealed answer" << selectedCell->correctAnswer() << "at selected cell";
    }
}

bool Sudoku::checkWin() const
{
    // 检查所有可编辑格子的内容是否都为正确答案
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (grid[row][col]->isEditable() && grid[row][col]->number() != grid[row][col]->correctAnswer()) {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::isSolved() const
{
    // 检查所有格子的内容是否都为正确答案
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (grid[row][col]->number() != grid[row][col]->correctAnswer()) {
                qDebug() << "Cell" << row << "," << col << "is incorrect";
                return false;
            }
        }
    }
    qDebug() << "Sudoku solved!";
    return true;
}
