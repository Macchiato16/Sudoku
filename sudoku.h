#ifndef SUDOKU_H
#define SUDOKU_H

#include <QWidget>
#include <vector>
#include "cell.h"

class Sudoku : public QWidget
{
    Q_OBJECT

public:
    explicit Sudoku(int level, QWidget *parent = nullptr);
    void setNumber(int number); // 设置格子中的数字
    bool isSolved() const; // 判断数独是否解出
    void revealAnswer(); // 显示正确答案
    bool checkWin() const; // 检查可编辑格子是否都为正确答案

private:
    std::vector<std::vector<Cell*>> grid; // 数独网格
    std::vector<std::vector<int>> solution; // 数独答案
    Cell* selectedCell; // 当前选中的格子
    void loadLevel(int level); // 加载关卡
};

#endif // SUDOKU_H
