#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H

#include <QWidget>
#include "sudokucell.h"

class SudokuGrid : public QWidget {
    Q_OBJECT

public:
    SudokuGrid(QWidget *parent = nullptr, const int puzzle[9][9] = nullptr, const int solution[9][9] = nullptr);
    bool isSolved();

private:
    SudokuCell *cells[9][9];
};

#endif // SUDOKUGRID_H
