#ifndef ADD_FILM_WINDOW_H
#define ADD_FILM_WINDOW_H

#include <QDialog>
#include "videocollection.h"


namespace Ui {
class Add_Film_Window;
}

class Add_Film_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Film_Window(VideoCollection *, QWidget *parent = nullptr);
    ~Add_Film_Window();

private slots:
    void on_cancel_button_clicked();
    void on_add_button_clicked();


private:
    Ui::Add_Film_Window *ui;
    VideoCollection *collection;
    void check_button_add();
};

#endif // ADD_FILM_WINDOW_H
