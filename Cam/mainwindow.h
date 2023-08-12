#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QUrl>
#include <QPixmap>
#include <QDialog>
#include <QString>
#include <QMovie>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <QTimer>
#include <QTime>
#include <QtUiTools/QUiLoader>
#include <QSlider>
#include "dialog_parameter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void getImg();
    void initial();

private:
    Ui::MainWindow      *ui;
    Dialog_parameter    *camera_parameter;

    cv::VideoCapture    *cap;
    cv::Mat             *frame;
    bool                *cam_Flag;
    float               *contrast;
    float               *brightness;

    QPixmap             *currentPicture;
    QImage              *image;
    QString             currentFileName;
    QString             *UI_SelectedPath;
    QString             *UI_ImageName;
    QTimer              *timer ;
    int                 *image_num;
    QSlider             *slider_contrast;
    QSlider             *slider_brightness;
private slots:
    void pushButton_Cam_on();
    void pushButton_Cam_off();
    void update_Frame();
    void on_pushButton_Exit_clicked();
    void on_pushButton_Path_Set_clicked();
    void on_pushButton_Save_img_clicked();
    void on_pushButton_FileName_Set_clicked();
    void on_pushButton_Adjust_clicked();
    //void image_process_brignt_and_contrast(cv::Mat &src, int bright, int contrast);

};

#endif // MAINWINDOW_H
