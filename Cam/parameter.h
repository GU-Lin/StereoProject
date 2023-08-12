#ifndef PARAMETER_H
#define PARAMETER_H

#include <QDialog>

namespace Ui {
class Parameter;
}

class Parameter : public QDialog
{
    Q_OBJECT

public:
    explicit Parameter(QWidget *parent = nullptr);
    ~Parameter();

private:
    Ui::Parameter *ui;
};

#endif // PARAMETER_H
