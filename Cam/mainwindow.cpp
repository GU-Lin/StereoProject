#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initial();
    //getImg();

    // Cam on
    connect(ui->pushButton_Cam_on, &QPushButton::clicked, this, &MainWindow::pushButton_Cam_on);
    // Cam off
    connect(ui->pushButton_Cam_off, &QPushButton::clicked, this, &MainWindow::pushButton_Cam_off);

}

void MainWindow::getImg()
{
    currentPicture = new QPixmap;
    image = new QImage;
    QString open_file, open_file_path;

    image->load("./Rose.jpg");

    ui->label_MainWindow->setPixmap(QPixmap::fromImage(*image).scaled(ui->label_MainWindow->size()));

}

void MainWindow::initial()
{

    cout << "Initial Start !" << endl;
    cap             = new cv::VideoCapture(0);
    frame           = new cv::Mat;
    currentPicture  = new QPixmap;
    image           = new QImage;
    cam_Flag        = new bool;
    *cam_Flag       = false;
    timer           = new QTimer(this);
    UI_SelectedPath = new QString;
    UI_ImageName    = new QString;
    image_num       = new int(0);
    contrast        = new float(1.0);
    brightness      = new float(0.0);
    *UI_ImageName   = ui->textEdit_File_Name->toPlainText();

    camera_parameter = new Dialog_parameter;
    slider_contrast = new QSlider(Qt::Horizontal, this);
    slider_brightness = new QSlider(Qt::Horizontal, this);
    //connect(slider_contrast, &QSlider::valueChanged, this, &Dialog_parameter::on_horizontalSlider_Contrast_valueChanged);

    cout << "Initial End !" << endl;

}


void MainWindow::pushButton_Cam_on()
{
    //cap->open(0);

    cv::VideoCapture cap_test;
    cap->open(0);
    if (!cap->isOpened())
    {
        QMessageBox::information(this, "Message", "No camera is be detected!");
        return;
    }
    *cam_Flag = true;

    cout << "Start capture !" << endl;
    connect(timer, &QTimer::timeout, this, &MainWindow::update_Frame);
    timer->start(30);


}

void MainWindow::update_Frame()
{
    cv::Mat frame_test;
    *cap >> *frame;
    *contrast   = camera_parameter->on_horizontalSlider_Contrast_valueChanged();
    *brightness = camera_parameter->on_horizontalSlider_Brightness_valueChanged();

    frame->convertTo(*frame, CV_32F, *contrast, *brightness);
    frame->convertTo(*frame, CV_8U);
    QImage qImage = QImage(frame->data,
                          frame->cols,
                          frame->rows,
                          (size_t)frame->step,
                          QImage::Format_RGB888).rgbSwapped();
    ui->label_MainWindow->setPixmap(QPixmap::fromImage(qImage));
    ui->label_MainWindow->setScaledContents(true);
}

void MainWindow::pushButton_Cam_off()
{

    *cam_Flag = false;
    cout << "Cam result : " << *cam_Flag << endl;
    cap->release();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Exit_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Question", "Do you want to exit?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QCoreApplication::quit();
    } else {
        return;
    }
}

void MainWindow::on_pushButton_Path_Set_clicked()
{
    *UI_SelectedPath = QFileDialog::getExistingDirectory(this, "Select a directory", "", QFileDialog::ShowDirsOnly);
    if (!UI_SelectedPath->isEmpty()) {
        ui->textBrowser_save_path->setText(*UI_SelectedPath);
        cout << "Selected path: "  << endl;
    } else {
        cout << "No path selected" << endl;
    }
}

void MainWindow::on_pushButton_Save_img_clicked()
{

    // Get current time
    QDateTime current_time = QDateTime::currentDateTime();
    QString formatted_time = current_time.toString("yyyy-MM-dd-hh-mm-ss");
    QString selected_format = ui->comboBox_file_format->currentText();
    QString numberString = QString::number(*image_num);

    //Prepare the output name
    string path = UI_SelectedPath->toStdString();
    string image_format = selected_format.toStdString();
    string image_num_str = numberString.toStdString();
    string image_name_out = UI_ImageName->toStdString();
    if (*cam_Flag)
    {
        string out_pah = path + "//" + image_name_out + "_" + image_num_str + "_" + formatted_time.toStdString() + image_format;
        cout << out_pah<< endl;
        cv::imwrite(out_pah,*frame);
        (*image_num)++;
    }else
    {
        QMessageBox::information(nullptr, "Warning", "Camera is off! No image be detected");
    }


}


void MainWindow::on_pushButton_FileName_Set_clicked()
{
    *UI_ImageName = ui->textEdit_File_Name->toPlainText();
}

void MainWindow::on_pushButton_Adjust_clicked()
{
    camera_parameter->exec();
}
