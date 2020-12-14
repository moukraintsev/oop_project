#ifndef SHOW_FILM_WINDOW_H
#define SHOW_FILM_WINDOW_H

#include <QDialog>
#include <videocollection.h>


namespace Ui {
class Show_Film_Window;
}

class Show_Film_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Show_Film_Window(VideoCollection *, Video *, QWidget *parent = nullptr);
    ~Show_Film_Window();

private slots:
    void on_okButton_clicked();
    void on_dellButton_clicked();

private:
    Ui::Show_Film_Window *ui;
    VideoCollection *container;
    Video *film;
};

#endif // SHOW_FILM_WINDOW_H
