#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_film_window.h"
#include "add_series_window.h"
#include <QMessageBox>

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    videoContainer = new VideoCollection;

    connect(ui -> lineEdit, &QLineEdit::cursorPositionChanged,this,
            &MainWindow::check_field);

    ui -> dellButton -> setEnabled(false);
    ui -> notViewedButton -> setEnabled(false);

    ui -> tableWidget -> setColumnCount(6);
    ui -> tableWidget -> setColumnWidth(1, ui -> tableWidget -> width()/2);
    QStringList headers = {"Name","Year","Duration","Country","Type","View"};
    ui -> tableWidget -> setHorizontalHeaderLabels(headers);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::check_field()
{
    if (ui -> lineEdit -> text().size() != 0){
        ui -> findButton -> setEnabled(true);
    }
    else{
        ui -> findButton -> setEnabled(false);
    }
}

void MainWindow::refresh_table(){
    ui -> tableWidget -> clear();
    QStringList headers = {"Name","Year","Duration","Country","Type","View"};
    ui -> tableWidget -> setHorizontalHeaderLabels(headers);
    ui -> tableWidget -> setRowCount(0);

    for (int i = 0; i < videoContainer -> getNumber(); i++) {
        ui -> tableWidget -> insertRow(ui -> tableWidget -> rowCount());

        std::string item = videoContainer -> getVideo(i)->getName();
        ui -> tableWidget -> setItem(ui -> tableWidget -> rowCount()-1, 0,
                                 new QTableWidgetItem(item.c_str()));

        item = std::to_string(videoContainer -> getVideo(i) -> getYear());
        ui -> tableWidget -> setItem(ui->tableWidget -> rowCount()-1, 1,
                                 new QTableWidgetItem(item.c_str()));

        item = videoContainer -> getVideo(i) -> getDuration();
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2,
                                 new QTableWidgetItem(item.c_str()));

        item = videoContainer -> getVideo(i) -> getCountry();
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3,
                                 new QTableWidgetItem(item.c_str()));

        item = std::to_string(videoContainer -> getVideo(i) -> getType());
        if (item == "0") { item = "film";}
        if (item == "1") {item = "series";}
        ui -> tableWidget -> setItem(ui -> tableWidget -> rowCount()-1, 4,
                                 new QTableWidgetItem(item.c_str()));

        if (item == "series"){
            item = std::to_string(dynamic_cast<Series*>
                                  (videoContainer -> getVideo(i)) -> getView());
        }
        else if (item == "film"){
            item = std::to_string(dynamic_cast<Film*>
                                  (videoContainer -> getVideo(i)) -> getView());
        }
        if (item == "0") {item = "No";}
        if (item == "1") {item = "Yes";}
        ui -> tableWidget -> setItem(ui -> tableWidget -> rowCount()-1, 5,
                                 new QTableWidgetItem(item.c_str()));
    }
}

void MainWindow::on_filmButton_clicked()
{
    Add_Film_Window window(videoContainer);
    window.setModal(true);
    window.exec();

    if (!window.isVisible()){
        refresh_table();
        ui -> saveButton -> setEnabled(true);
        ui -> dellButton -> setEnabled(true);
        ui -> notViewedButton -> setEnabled(true);
    }
}

void MainWindow::on_seriesButton_clicked()
{
    Add_Series_Window window(videoContainer);
    window.setModal(true);
    window.exec();

    if (!window.isVisible()) {
        refresh_table();
        ui -> saveButton -> setEnabled(true);
        ui -> dellButton -> setEnabled(true);
        ui -> notViewedButton -> setEnabled(true);
    }
}

void MainWindow::on_dellButton_clicked() {
    videoContainer -> clear();
    ui -> saveButton->setEnabled(false);
    ui -> dellButton -> setEnabled(false);
    ui -> notViewedButton -> setEnabled(false);
    refresh_table();
}

void MainWindow::on_loadButton_clicked()
{
    std::string path = QFileDialog::getOpenFileName
            (0, "Open file", "", "TXT files (*.txt)").toStdString();
    if (!path.empty()){
        videoContainer -> readFile(path);
        ui -> saveButton -> setEnabled(true);
        ui -> dellButton -> setEnabled(true);
        ui -> notViewedButton -> setEnabled(true);
        refresh_table();
    }
}

void MainWindow::on_saveButton_clicked()
{
    std::string path = QFileDialog::getSaveFileName().toStdString();
    if (!path.empty()){
        videoContainer -> writeFile(path+".txt");
    }
}

void MainWindow::on_findButton_clicked()
{
    QString name = ui -> lineEdit -> text();
    std::string name_ = name.toStdString();
    if (videoContainer -> searchVideo(name_) == nullptr){
        QMessageBox::warning(this,"Oh...", "Video not found \n You can add it!");
    }
    else {
        if (videoContainer -> searchVideo(name_) -> getType() == 0){
            Show_Film_Window window(videoContainer, videoContainer -> searchVideo(name_));
            window.setModal(true);
            window.exec();
            if (!window.isVisible())
            refresh_table();
            if (videoContainer -> getNumber() == 0) {
                ui -> saveButton->setEnabled(false);
                ui -> dellButton -> setEnabled(false);
                ui -> notViewedButton -> setEnabled(false);
            }
            return;
        }
        if (videoContainer -> searchVideo(name_) -> getType() == 1){
            Show_Series_Window window(videoContainer, videoContainer -> searchVideo(name_));
            window.setModal(true);
            window.exec();
            if (!window.isVisible())
            refresh_table();
            if (videoContainer -> getNumber() == 0) {
                ui -> saveButton->setEnabled(false);
                ui -> dellButton -> setEnabled(false);
                ui -> notViewedButton -> setEnabled(false);
            }
            return;
        }
    }
}

void MainWindow::on_notViewedButton_clicked()
{
    Show_Not_Viewed window(videoContainer);
    window.setModal(true);
    window.exec();

    if (!window.isVisible()) {
        refresh_table();
        ui -> saveButton -> setEnabled(true);
        ui -> dellButton -> setEnabled(true);
        ui -> notViewedButton -> setEnabled(true);
    }
    if (videoContainer -> getNumber() == 0) {
        ui -> saveButton->setEnabled(false);
        ui -> dellButton -> setEnabled(false);
        ui -> notViewedButton -> setEnabled(false);
    }
}

