#include "show_series_window.h"
#include "ui_show_series_window.h"

Show_Series_Window::Show_Series_Window(VideoCollection *container, Video *series, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Show_Series_Window)
{
    ui->setupUi(this);
    this -> series = series;
    this -> container = container;

    ui -> edit_name -> setText(series -> getName().c_str());
    ui -> edit_year -> setText(std::to_string(series -> getYear()).c_str());
    ui -> edit_duration -> setText(series -> getDuration().c_str());
    ui -> edit_region -> setText(series -> getCountry().c_str());
    ui -> edit_seasons -> setText(std::to_string(dynamic_cast<Series*>(series) -> getNumberOfSeasons()).c_str());
    ui -> edit_episodes -> setText(std::to_string(dynamic_cast<Series*>(series) -> getNumberOfEpisodes()).c_str());
    std::string view = std::to_string(dynamic_cast<Series*>(series) -> getView());
    if (view == "1") {
        ui -> checkBox -> setCheckState(Qt::Checked);
    } else if (view == "0"){
        ui -> checkBox -> setCheckState(Qt::Unchecked);
    }
}

Show_Series_Window::~Show_Series_Window()
{
    delete ui;
}

void Show_Series_Window::on_okButton_clicked()
{
    if (ui -> checkBox -> isChecked()){
        dynamic_cast<Series*>(series) -> setView(true);
    } else {
        dynamic_cast<Series*>(series) -> setView(false);
    }

    QString word = ui -> edit_name -> text();
    std::string word_ = word.toStdString();
    dynamic_cast<Series*>(series) -> setName(word_);

    word_ = (ui -> edit_year -> text()).toStdString();
    dynamic_cast<Series*>(series) -> setYear(std::stoi(word_));

    word_ = (ui -> edit_year -> text()).toStdString();
    dynamic_cast<Series*>(series) -> setYear(std::stoi(word_));

    word_ = (ui -> edit_duration -> text()).toStdString();
    dynamic_cast<Series*>(series) -> setDuration(word_);

    word_ = (ui -> edit_region -> text()).toStdString();
    dynamic_cast<Series*>(series) -> setCountry(word_);

    word_ = (ui -> edit_seasons -> text()).toStdString();
    dynamic_cast<Series*>(series) -> setNumberOfSeasons(std::stoi(word_));

    word_ = (ui -> edit_episodes -> text()).toStdString();
    dynamic_cast<Series*>(series) -> setNumberOfEpisodes(std::stoi(word_));

    this -> close();
}

void Show_Series_Window::on_dellButton_clicked() {
    QString word = ui -> edit_name -> text();
    std::string word_ = word.toStdString();

    container -> dellVideo(word_);
    this -> close();
}
