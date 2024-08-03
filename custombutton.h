#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>

class CustomButton : public QPushButton {
    Q_OBJECT

public:
    CustomButton(QWidget *parent = nullptr);
    void setValue(int value);
    int value() const;

private:
    int m_value;
};

#endif // CUSTOMBUTTON_H
