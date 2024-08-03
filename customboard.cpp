#include "customboard.h"

CustomBoard::CustomBoard(QWidget *parent)
    : QWidget(parent) {
    gridLayout = new QGridLayout(this);

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            buttons[row][col] = new CustomButton(this);
            gridLayout->addWidget(buttons[row][col], row, col);
        }
    }
}
