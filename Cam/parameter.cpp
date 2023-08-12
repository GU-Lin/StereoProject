#include "parameter.h"
#include "ui_parameter.h"


Parameter::Parameter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Parameter)
{
    //ui->setupUi(this);
}

Parameter::~Parameter()
{
    delete ui;
}
