#ifndef DIALOG_PARAMETER_H
#define DIALOG_PARAMETER_H

#include <QDialog>
#include <iostream>
using namespace std;


namespace Ui {
class Dialog_parameter;
}

class Dialog_parameter : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_parameter(QWidget *parent = nullptr);
    void initial();
    ~Dialog_parameter();

public slots:

    //void on_horizontalSlider_Exposure_valueChanged(int value);

    //void on_horizontalSlider_Gain_valueChanged(int value);

    int on_horizontalSlider_Contrast_valueChanged();

    //void on_horizontalSlider_Hue_valueChanged(int value);

    int on_horizontalSlider_Brightness_valueChanged();

private:
    Ui::Dialog_parameter *ui;

    int *exposure;
    int *gain;
    int *contrast;
    int *hue;
};

#endif // DIALOG_PARAMETER_H
