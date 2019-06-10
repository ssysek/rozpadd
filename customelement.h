#ifndef CUSTOMELEMENT_H
#define CUSTOMELEMENT_H

#include <QDialog>

namespace Ui {
class CustomElement;
}

class CustomElement : public QDialog
{
    Q_OBJECT

public:
    explicit CustomElement(QWidget *parent = nullptr);
    ~CustomElement();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CustomElement *ui;
};

#endif // CUSTOMELEMENT_H
