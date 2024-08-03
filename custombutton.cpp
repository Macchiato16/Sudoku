#include "custombutton.h"

CustomButton::CustomButton(QWidget *parent)
    : QPushButton(parent), m_value(0) {
    connect(this, &QPushButton::clicked, this, [this]() {
        setValue((m_value + 1) % 10);
    });
}

void CustomButton::setValue(int value) {
    m_value = value;
    setText(m_value == 0 ? "" : QString::number(m_value));
}

int CustomButton::value() const {
    return m_value;
}
