#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int favourites[200];
    void populateTable(vector<Car> v1);
    void updateTable();
    MainWindow(shared_ptr<Controller>,QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void hide_manager();
    void show_manager();
    void hide_customer();
    void show_customer();

    void on_AllCars_clicked();

    void on_Sortbyprice_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_pushButton_2_clicked();

    void on_Mark_brand_button_clicked();

    void on_AllCars_3_clicked();

    void on_Year_button_clicked();

    void on_Mileage_button_clicked();

    void on_pushButton_3_clicked();

    void on_DeleteButton_clicked();

    void on_Customer_button_clicked();

    void on_Manager_button_clicked();

    void on_Add_favourite_clicked();

    void on_Show_favourites_clicked();

    void on_File_button_clicked();

    void on_Save_changes_clicked();

private:
    shared_ptr<Controller> controller;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
