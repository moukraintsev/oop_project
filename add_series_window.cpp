#include "add_series_window.h"
#include "ui_add_series_window.h"

Add_Series_Window::Add_Series_Window(VideoCollection *container, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Series_Window)
{
    ui -> setupUi(this);
    this -> container = container;

    connect(ui -> enter_name, &QLineEdit::cursorPositionChanged, this,
            &Add_Series_Window::check_add_button);
    connect(ui -> enter_year, &QLineEdit::cursorPositionChanged, this,
            &Add_Series_Window::check_add_button);
    connect(ui -> enter_duration, &QLineEdit::cursorPositionChanged, this,
            &Add_Series_Window::check_add_button);
    connect(ui -> enter_country, &QLineEdit::cursorPositionChanged, this,
            &Add_Series_Window::check_add_button);
    connect(ui -> enter_season, &QLineEdit::cursorPositionChanged, this,
            &Add_Series_Window::check_add_button);
    connect(ui -> enter_episode, &QLineEdit::cursorPositionChanged, this,
            &Add_Series_Window::check_add_button);


    ui -> addButton -> setEnabled(false);
}

Add_Series_Window::~Add_Series_Window()
{
    delete ui;
}

void Add_Series_Window::check_add_button()
{
    if (ui -> enter_name -> text().size() != 0
        && ui -> enter_year -> text().size() !=0
        && ui -> enter_duration -> text().size() != 0
        && ui -> enter_country -> text().size() != 0
        && ui -> enter_episode -> text().size() != 0
        && ui -> enter_season -> text().size() != 0){

        ui -> addButton -> setEnabled(true);
    } else {
        ui -> addButton -> setEnabled(false);
    }
}

void Add_Series_Window::on_cancelButton_clicked()
{
    this -> close();
}

void Add_Series_Window::on_addButton_clicked()
{
    Series* temp = new Series;

    QString word = ui -> enter_name -> text();
    std::string word_ = word.toStdString();
    temp -> setName(word_);

    word = ui -> enter_year -> text();
    word_ = word.toStdString();
    temp -> setYear(std::stoi(word_));

    word = ui -> enter_duration -> text();
    word_ = word.toStdString();
    temp -> setDuration(word_);

    word = ui -> enter_country -> text();
    word_ = word.toStdString();
    temp -> setCountry(word_);

    word = ui -> enter_season -> text();
    word_ = word.toStdString();
    temp -> setNumberOfSeasons(std::stoi(word_));

    word = ui -> enter_episode -> text();
    word_ = word.toStdString();
    temp -> setNumberOfEpisodes(std::stoi(word_));

    if (ui -> checkBox -> isChecked()){
        temp -> setView(true);
    } else if (!ui -> checkBox -> isChecked()) {
        temp -> setView(false);
    }

    container -> addVideo(temp);

    this -> close();
}
