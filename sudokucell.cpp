#include "sudokucell.h"

SudokuCell::SudokuCell(QWidget *parent) : QLineEdit(parent), initialValue(0), solutionValue(0) {
    setAlignment(Qt::AlignCenter);
}

void SudokuCell::setInitialValue(int value) {
    initialValue = value;
    setText(QString::number(value));
    setReadOnly(true);
    setStyleSheet("color: black;");
}

void SudokuCell::setSolutionValue(int value) {
    solutionValue = value;
    if (initialValue == 0) {
        setText(QString::number(value));
        setReadOnly(true);
        setStyleSheet("color: blue;");
    }
}
