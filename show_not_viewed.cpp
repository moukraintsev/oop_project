#include "show_not_viewed.h"
#include "ui_show_not_viewed.h"

Show_Not_Viewed::Show_Not_Viewed(VideoCollection *container, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Show_Not_Viewed)
{
    ui -> setupUi(this);
    this -> container = container;

    connect(ui->lineEdit, &QLineEdit::cursorPositionChanged,this,
            &Show_Not_Viewed::check_field);

    ui -> tableWidget -> setColumnCount(6);
    ui -> tableWidget -> setColumnWidth(1, ui -> tableWidget -> width()/2);
    QStringList headers = {"Name","Year","Duration","Country","Type","View"};
    ui -> tableWidget -> setHorizontalHeaderLabels(headers);
    refresh_table();
}

void Show_Not_Viewed::check_field()
{
    if (ui -> lineEdit -> text().size() != 0){
        ui -> findButton -> setEnabled(true);
    }
    else{
        ui -> findButton -> setEnabled(false);
    }
}

Show_Not_Viewed::~Show_Not_Viewed()
{
    delete ui;
}

void Show_Not_Viewed::refresh_table(){
    ui -> tableWidget -> clear();
    QStringList headers = {"Name","Year","Duration","Country","Type","View"};
    ui -> tableWidget -> setHorizontalHeaderLabels(headers);
    ui -> tableWidget -> setRowCount(0);

    for (int i = 0; i < container -> getNumber(); i++) {
        std::string type = std::to_string(container -> getVideo(i) -> getType());

        if ((type == "0" && std::to_string(dynamic_cast<Film*>(container -> getVideo(i)) -> getView()) == "0") ||
               (type == "1" && std::to_string(dynamic_cast<Series*>(container -> getVideo(i)) -> getView()) == "0" )) {

        ui -> tableWidget -> insertRow(ui -> tableWidget -> rowCount());

        std::string item = container -> getVideo(i)->getName();
        ui -> tableWidget -> setItem(ui -> tableWidget -> rowCount()-1, 0,
                                 new QTableWidgetItem(item.c_str()));

        item = std::to_string(container -> getVideo(i) -> getYear());
        ui -> tableWidget -> setItem(ui->tableWidget -> rowCount()-1, 1,
                                 new QTableWidgetItem(item.c_str()));

        item = container -> getVideo(i) -> getDuration();
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2,
                                 new QTableWidgetItem(item.c_str()));

        item = container -> getVideo(i) -> getCountry();
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3,
                                 new QTableWidgetItem(item.c_str()));

        item = std::to_string(container -> getVideo(i) -> getType());
        if (item == "0") { item = "film";}
        if (item == "1") {item = "series";}
        ui -> tableWidget -> setItem(ui -> tableWidget -> rowCount()-1, 4,
                                 new QTableWidgetItem(item.c_str()));

        if (item == "series") {
            item = std::to_string(dynamic_cast<Series*>
                                  (container -> getVideo(i)) -> getView());
        } else if (item == "film") {
            item = std::to_string(dynamic_cast<Film*>
                                  (container -> getVideo(i)) -> getView());
        }
        if (item == "0") {item = "No";}
        if (item == "1") {item = "Yes";}
        ui -> tableWidget -> setItem(ui -> tableWidget -> rowCount()-1, 5,
                                 new QTableWidgetItem(item.c_str()));
        }
    }
}

void Show_Not_Viewed::on_findButton_clicked()
{
    QString name = ui -> lineEdit -> text();
    std::string name_ = name.toStdString();
    if (container -> searchVideo(name_) != nullptr) {
        if (container -> searchVideo(name_) -> getType() == 0){
            Show_Film_Window window(container, container -> searchVideo(name_));
            window.setModal(true);
            window.exec();
            if (!window.isVisible())
            refresh_table();
            return;
        }
        if (container -> searchVideo(name_) -> getType() == 1){
            Show_Series_Window window(container, container -> searchVideo(name_));
            window.setModal(true);
            window.exec();
            if (!window.isVisible())
            refresh_table();
            return;
        }
    } else {
        QMessageBox::warning(this,"Oh...", "Video not found!");
    }
}

void Show_Not_Viewed::on_exitButton_clicked()
{
    this->close();
}
