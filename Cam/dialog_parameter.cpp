#include "dialog_parameter.h"
#include "ui_dialog_parameter.h"

Dialog_parameter::Dialog_parameter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_parameter)
{
    ui->setupUi(this);
    initial();
}

Dialog_parameter::~Dialog_parameter()
{
    delete ui;
}

void Dialog_parameter::initial()
{
    contrast    = new int(100);
    hue         = new int(1);
    exposure    = new int;
    gain        = new int(1);

    ui->horizontalSlider_Contrast->setRange(1,500);
    ui->horizontalSlider_Contrast->setValue(*contrast);

    ui->horizontalSlider_Contrast->setRange(0,255);

}

int Dialog_parameter::on_horizontalSlider_Contrast_valueChanged()
{
    //cout << "Slider value from Second UI: " << value << endl;
    return ui->horizontalSlider_Contrast->value()/100;
}

int Dialog_parameter::on_horizontalSlider_Brightness_valueChanged()
{
    return ui->horizontalSlider_Brightness->value();
}

/*
void Dialog_parameter::on_horizontalSlider_Exposure_valueChanged(int value)
{

}

void Dialog_parameter::on_horizontalSlider_Gain_valueChanged(int value)
{

}



void Dialog_parameter::on_horizontalSlider_Hue_valueChanged(int value)
{

}



*/
