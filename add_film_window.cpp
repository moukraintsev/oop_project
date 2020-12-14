#include "add_film_window.h"
#include "ui_add_film_window.h"

Add_Film_Window::Add_Film_Window(VideoCollection *collection, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_Film_Window)
{
    ui -> setupUi(this);
    this -> collection = collection;

    connect(ui -> enter_name, &QLineEdit::cursorPositionChanged, this,
            &Add_Film_Window::check_button_add);
    connect(ui -> enter_year, &QLineEdit::cursorPositionChanged, this,
            &Add_Film_Window::check_button_add);
    connect(ui -> enter_duration, &QLineEdit::cursorPositionChanged, this,
            &Add_Film_Window::check_button_add);
    connect(ui -> enter_country, &QLineEdit::cursorPositionChanged, this,
            &Add_Film_Window::check_button_add);
    connect(ui -> enter_style, &QLineEdit::cursorPositionChanged, this,
            &Add_Film_Window::check_button_add);

    ui -> add_button -> setEnabled(false);
}

Add_Film_Window::~Add_Film_Window()
{
    delete ui;
}

void Add_Film_Window::check_button_add()
{
    if (ui -> enter_name -> text().size() != 0
        && ui -> enter_year -> text().size() !=0
        && ui -> enter_duration -> text().size() != 0
        && ui -> enter_country -> text().size() != 0
        && ui -> enter_style -> text().size() != 0){

        ui -> add_button -> setEnabled(true);
    } else {
        ui -> add_button -> setEnabled(false);
    }
}

void Add_Film_Window::on_cancel_button_clicked()
{
    this -> close();
}

void Add_Film_Window::on_add_button_clicked()
{
    Film* temp = new Film;
    QString word = ui -> enter_name->text();
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

    if (ui -> checkBox -> isChecked()){
        temp -> setView(true);
    } else if (!ui -> checkBox -> isChecked()) {
        temp -> setView(false);
    }

    word = ui -> enter_style -> text();
    word_ = word.toStdString();
    temp -> setStyle(word_);

    collection -> addVideo(temp);

    this -> close();

}
