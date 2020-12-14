#ifndef SHOW_NOT_VIEWED_H
#define SHOW_NOT_VIEWED_H

#include <QDialog>
#include <QMessageBox>
#include <videocollection.h>
#include "show_film_window.h"
#include "show_series_window.h"

namespace Ui {
class Show_Not_Viewed;
}

class Show_Not_Viewed : public QDialog
{
    Q_OBJECT

public:
    explicit Show_Not_Viewed(VideoCollection *, QWidget *parent = nullptr);
    ~Show_Not_Viewed();

private slots:
    void refresh_table();
    void on_findButton_clicked();
    void on_exitButton_clicked();
    void check_field();

private:
    Ui::Show_Not_Viewed *ui;
    VideoCollection *container;
};

#endif // SHOW_NOT_VIEWED_H
