#ifndef SUDOKUCELL_H
#define SUDOKUCELL_H

#include <QLineEdit>

class SudokuCell : public QLineEdit {
    Q_OBJECT

public:
    explicit SudokuCell(QWidget *parent = nullptr);

    void setInitialValue(int value);
    void setSolutionValue(int value);

private:
    int initialValue;
    int solutionValue;
};

#endif // SUDOKUCELL_H
