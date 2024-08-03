#ifndef CUSTOMBOARD_H
#define CUSTOMBOARD_H

#include <QWidget>
#include <QGridLayout>
#include "custombutton.h"

class CustomBoard : public QWidget {
    Q_OBJECT

public:
    CustomBoard(QWidget *parent = nullptr);

private:
    QGridLayout *gridLayout;
    CustomButton *buttons[9][9];
};

#endif // CUSTOMBOARD_H
