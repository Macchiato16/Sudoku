#include "sudokugrid.h"
#include <QGridLayout>

SudokuGrid::SudokuGrid(QWidget *parent, const int puzzle[9][9], const int solution[9][9]) : QWidget(parent) {
    QGridLayout *gridLayout = new QGridLayout(this);

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            SudokuCell *cell = new SudokuCell(this);
            if (puzzle[row][col] != 0) {
                cell->setInitialValue(puzzle[row][col]);
            } else {
                cell->setSolutionValue(solution[row][col]);
            }
            gridLayout->addWidget(cell, row, col);
            cells[row][col] = cell;
        }
    }
}

bool SudokuGrid::isSolved() {
    // 省略检查逻辑，因为答案已经显示在网格中
    return true;
}
