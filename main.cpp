#include "mainwindow.h"
#include "controller.h"
#include"crudrepository.h"
#include "inmemoryrepository.h"
#include <QApplication>
#include "domain.h"
#include<bits/stdc++.h>
#include <QFile>
#include<QtWidgets/QApplication>
using namespace std;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
        QFile styleSheetFile("D:\College\Y1S2\Atom_L7\SpyBot.qss");

        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet=QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);

    vector<Car> v1;
        v1.emplace_back(Car("X", "tesla", 2013, 123264, 231, 13412, 3,1,0));
        v1.emplace_back(Car("Z", "dacia", 2018, 126334, 98, 12412, 1,2,0));
        v1.emplace_back(Car("X", "tesla", 2017, 152324, 500, 5278, 3,3,0));
        v1.emplace_back(Car("K", "nissan", 2010, 172334, 876, 12442, 2,4,0));
        v1.emplace_back(Car("X", "tesla", 2011, 31234, 345, 12448, 4,5,0));
        v1.emplace_back(Car("H", "dacia", 2021, 61234, 452, 12363, 3.9,6,0));
        v1.emplace_back(Car("X", "nissan", 2007, 172364, 123, 24567, 3.7,7,0));
        v1.emplace_back(Car("L", "tesla", 2015, 132334, 456, 45678, 1.9,8,0));
        v1.emplace_back(Car("X", "dacia", 2013, 123264, 567, 12341,1.5,9,0));
        v1.emplace_back(Car("M", "nissan", 2018, 16236234, 456, 9887, 2,10,0));


    shared_ptr<CrudRepository<Car>> repo;

    repo=make_shared<CSVfileRepository>("D:\College\Y1S2\Atom_L7\cars2.csv");


    shared_ptr<Controller> contr;
    contr=make_shared<Controller>(repo);

    MainWindow w=MainWindow(contr);
    w.show();
    return a.exec();
}
