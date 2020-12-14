#ifndef SHOW_SERIES_WINDOW_H
#define SHOW_SERIES_WINDOW_H

#include <QDialog>
#include "videocollection.h"

namespace Ui {
class Show_Series_Window;
}

class Show_Series_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Show_Series_Window(VideoCollection *, Video *, QWidget *parent = nullptr);
    ~Show_Series_Window();

private slots:
    void on_okButton_clicked();
    void on_dellButton_clicked();

private:
    Ui::Show_Series_Window *ui;
    Video* series;
    VideoCollection *container;
};

#endif // SHOW_SERIES_WINDOW_H
