#include "show_film_window.h"
#include "ui_show_film_window.h"

Show_Film_Window::Show_Film_Window(VideoCollection *container, Video *film, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Show_Film_Window)
{
    ui -> setupUi(this);
    this -> film = film;
    this -> container = container;

    ui -> edit_name -> setText(film -> getName().c_str());
    ui -> edit_year -> setText(std::to_string(film -> getYear()).c_str());
    ui -> edit_duration -> setText(film -> getDuration().c_str());
    ui -> edit_region -> setText(film -> getCountry().c_str());
    ui -> edit_style -> setText(dynamic_cast<Film*>(film) -> getStyle().c_str());

    std::string view = std::to_string(dynamic_cast<Film*>(film) -> getView());
    if (view == "1") {
        ui -> checkBox -> setCheckState(Qt::Checked);
    } else if (view == "0"){
        ui -> checkBox -> setCheckState(Qt::Unchecked);
    }
}

Show_Film_Window::~Show_Film_Window()
{
    delete ui;
}

void Show_Film_Window::on_okButton_clicked()
{
    if (ui -> checkBox -> isChecked()){
        dynamic_cast<Film*>(film) -> setView(true);
    } else {
        dynamic_cast<Film*>(film) -> setView(false);
    }

    QString word = ui -> edit_name -> text();
    std::string word_ = word.toStdString();
    dynamic_cast<Film*>(film) -> setName(word_);

    word_ = (ui -> edit_year -> text()).toStdString();
    dynamic_cast<Film*>(film) -> setYear(std::stoi(word_));

    word_ = (ui -> edit_year -> text()).toStdString();
    dynamic_cast<Film*>(film) -> setYear(std::stoi(word_));

    word_ = (ui -> edit_duration -> text()).toStdString();
    dynamic_cast<Film*>(film) -> setDuration(word_);

    word_ = (ui -> edit_region -> text()).toStdString();
    dynamic_cast<Film*>(film) -> setCountry(word_);

    word_ = (ui -> edit_style -> text()).toStdString();
    dynamic_cast<Film*>(film) -> setStyle(word_);


    this -> close();
}

void Show_Film_Window::on_dellButton_clicked() {
    QString word = ui -> edit_name -> text();
    std::string word_ = word.toStdString();

    container -> dellVideo(word_);
    this -> close();
}
