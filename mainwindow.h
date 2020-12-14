#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QFileDialog>
#include <QCompleter>
#include <string>
#include <videocollection.h>
#include <show_film_window.h>
#include <show_series_window.h>
#include <show_not_viewed.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_filmButton_clicked();
    void on_seriesButton_clicked();
    void refresh_table();
    void check_field();
    void on_dellButton_clicked();
    void on_loadButton_clicked();
    void on_saveButton_clicked();
    void on_findButton_clicked();
    void on_notViewedButton_clicked();

private:
    Ui::MainWindow *ui;
    VideoCollection *videoContainer;
};
#endif // MAINWINDOW_H
