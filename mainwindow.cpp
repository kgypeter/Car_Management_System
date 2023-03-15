#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "domain.h"
#include "csvfilerepository.h"
#include "controller.h"
MainWindow::MainWindow(shared_ptr<Controller> c,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


controller=c;
    ui->setupUi(this);
    updateTable();
    QLineEdit *passw=ui->Password_field;
    passw->setEchoMode(QLineEdit::Password);
    hide_manager();
    show_customer();
    for(int i=0;i<200;i++)
        favourites[i]=0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateTable(vector<Car> v1)
{

ui->tableWidget->setRowCount(0);

        for(int i=0;i<v1.size();i++)
        {
            ui->tableWidget->insertRow(i);
            vector<string> s=v1[i].car_to_string();

            for(int j=0;j<8;j++)
                ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::fromStdString(s[j])));
        }

}

void MainWindow::updateTable()
{
    ui->tableWidget->setRowCount(0);
vector<Car> v1=controller->all_cars();
for(int i=0;i<v1.size();i++)
{

    ui->tableWidget->insertRow(i);
    vector<string> s=v1[i].car_to_string();

    for(int j=0;j<8;j++)
        ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::fromStdString(s[j])));
}
}


void MainWindow::on_AllCars_clicked()
{
    populateTable(controller->all_cars());
}


void MainWindow::on_Sortbyprice_clicked()
{
    populateTable(controller->sort_by_price());
}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{

if(column==0)
populateTable(controller->sortById());
if(column==1)
populateTable(controller->sortByModel());
if(column==2)
populateTable(controller->sortByMark());
if(column==3)
populateTable(controller->sortByFabricationYear());
if(column==4)
populateTable(controller->sortByKm());
if(column==5)
populateTable(controller->sortByChargeTime());
if(column==6)
populateTable(controller->sortByMaxDistance());
if(column==7)
populateTable(controller->sort_by_price());

}


void MainWindow::on_pushButton_2_clicked()
{
    QString model,brand,price,mileage,maxrange,fabricy,chargetime;
    model=ui->Model->text();
    brand=ui->Brand->text();
    price=ui->Price->text();
    mileage=ui->Mileage->text();
    maxrange=ui->Maxrange->text();
    fabricy=ui->FabricationYear->text();
    chargetime=ui->Chargetime->text();
    int _price,_maxrange,_mileage,_year;
    float _chargetime;
    _price=price.toInt();
    _maxrange=maxrange.toInt();
    _mileage=mileage.toInt();
    _year=fabricy.toInt();
    _chargetime=chargetime.toFloat();
    try{
        controller->add_car(model.toStdString(),brand.toStdString(),_year,_mileage,_maxrange,_price,_chargetime);
    }
    catch(exception &e){
        ui->Model->setText("");
        ui->Brand->setText("");
        ui->Price->setText("");
        ui->Mileage->setText("");
        ui->Maxrange->setText("");
        ui->FabricationYear->setText("");
        ui->Chargetime->setText("");
        return;
    }
    updateTable();
    ui->Model->setText("");
    ui->Brand->setText("");
    ui->Price->setText("");
    ui->Mileage->setText("");
    ui->Maxrange->setText("");
    ui->FabricationYear->setText("");
    ui->Chargetime->setText("");

}


void MainWindow::on_Mark_brand_button_clicked()
{
    QString model,brand;
    model=ui->Model_filter->text();
    brand=ui->Brand_filter->text();
    populateTable(controller->search_by_model_and_mark(model.toStdString(),brand.toStdString()));
    ui->Model_filter->setText("");
    ui->Brand_filter->setText("");

}


void MainWindow::on_AllCars_3_clicked()
{
    populateTable(controller->all_cars());
}


void MainWindow::on_Year_button_clicked()
{
    QString year;
    year=ui->Year_filter->text();
    int i=year.toInt();
    ui->Year_filter->setText("");
    populateTable(controller->filter_by_year(i));
}


void MainWindow::on_Mileage_button_clicked()
{
    QString km;
        km=ui->Mileage_filter->text();
        int i=km.toInt();
        ui->Mileage_filter->setText("");
        populateTable(controller->filter_by_km(i));
}

void MainWindow::hide_manager()
{
    ui->delete_id->setVisible(0);
    ui->DeleteButton->setVisible(0);
    ui->Model->setVisible(0);
    ui->Brand->setVisible(0);
    ui->Mileage->setVisible(0);
    ui->Chargetime->setVisible(0);
    ui->Maxrange->setVisible(0);
    ui->Price->setVisible(0);
    ui->FabricationYear->setVisible(0);
    ui->pushButton_2->setVisible(0);
    ui->Manager_button->setVisible(1);
    ui->Save_changes->setVisible(0);
}
void MainWindow::hide_customer(){
ui->Add_favourite->setVisible(0);
ui->Show_favourites->setVisible(0);
ui->favourite_id->setVisible(0);
ui->Customer_button->setVisible(1);


}
void MainWindow::show_manager(){
    ui->delete_id->setVisible(1);
    ui->DeleteButton->setVisible(1);
    ui->Model->setVisible(1);
    ui->Brand->setVisible(1);
    ui->Mileage->setVisible(1);
    ui->Chargetime->setVisible(1);
    ui->Maxrange->setVisible(1);
    ui->Price->setVisible(1);
    ui->FabricationYear->setVisible(1);
    ui->pushButton_2->setVisible(1);
    ui->Manager_button->setVisible(0);
    ui->Save_changes->setVisible(1);

}
void MainWindow::show_customer()
{
    ui->Add_favourite->setVisible(1);
    ui->Show_favourites->setVisible(1);
    ui->favourite_id->setVisible(1);
    ui->Customer_button->setVisible(0);
    ui->Save_changes->setVisible(0);

}
void MainWindow::on_pushButton_3_clicked()
{


}


void MainWindow::on_DeleteButton_clicked()
{
    QString id;
    id=ui->delete_id->text();
    int i=id.toInt();
    try{
        controller->delete_car(i);
    }
    catch(exception &e){
        ui->delete_id->clear();
        return;
    }
    ui->delete_id->setText("");
    updateTable();
}


void MainWindow::on_Customer_button_clicked()
{
    QString pswd;
    pswd=ui->Password_field->text();
    ui->Password_field->setText("");
    if(pswd=="us3r"){
    hide_manager();
    show_customer();
    ui->tableWidget->setEditTriggers(QTableView::NoEditTriggers);
}
    else
    {

    }
}


void MainWindow::on_Manager_button_clicked()
{
    QString pswd;
    pswd=ui->Password_field->text();
    ui->Password_field->setText("");
    if(pswd=="admin"){
    hide_customer();
    show_manager();
    ui->tableWidget->setEditTriggers(QTableView::AllEditTriggers);
}
    else
    {

    }
}


void MainWindow::on_Add_favourite_clicked()
{
    QString id;
    id=ui->favourite_id->text();
    int i=id.toInt();

    try{
        controller->add_favourite(i);
        favourites[id.toInt()]=1;
    }
    catch(exception &e){
        ui->favourite_id->setText("");
        return;
    }
    ui->favourite_id->setText("");

}


void MainWindow::on_Show_favourites_clicked()
{
    populateTable(controller->get_favourites());
}


void MainWindow::on_File_button_clicked()
{
    QString s;
    s=ui->Filename->text();
    ui->Filename->setText("");

    shared_ptr<CSVfileRepository> repo = make_shared<CSVfileRepository>(s.toStdString());
    controller=make_shared<Controller>(repo);
    updateTable();

}


void MainWindow::on_Save_changes_clicked()
{

    vector<vector<string>> string_cars;
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
        vector<string> s;
        QTableWidgetItem *it;
        for(int j=0;j<ui->tableWidget->columnCount()-3;j++)
        {it=ui->tableWidget->item(i,j);
            s.emplace_back(it->text().toStdString());

    }
        it=ui->tableWidget->item(i,6);
        s.emplace_back(it->text().toStdString());
        it=ui->tableWidget->item(i,7);
        s.emplace_back(it->text().toStdString());
        it=ui->tableWidget->item(i,5);
        s.emplace_back(it->text().toStdString());
        s.emplace_back(to_string(favourites[ui->tableWidget->item(i,0)->text().toInt()]));
        string_cars.emplace_back(s);



    }
    controller->replace_cars(string_cars);
    updateTable();
}

