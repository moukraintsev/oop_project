#ifndef ADD_SERIES_WINDOW_H
#define ADD_SERIES_WINDOW_H

#include "videocollection.h"
#include <QDialog>

namespace Ui {
class Add_Series_Window;
}

class Add_Series_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Series_Window(VideoCollection *, QWidget *parent = nullptr);
    ~Add_Series_Window();

private slots:
    void on_addButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::Add_Series_Window *ui;
    VideoCollection *container;
    void check_add_button();
};

#endif // ADD_SERIES_WINDOW_H
