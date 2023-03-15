#include "csvfilerepository.h"
//
// Created by Peter on 08-May-22.
//

#include <iostream>
#include "fstream"
#include "sstream"
#include "vector"

using namespace std;

CSVfileRepository::CSVfileRepository(string filename) {
    file=filename;
    vector<vector<string>> rows=read_from_file();
    nr_cars=rows.size();


}

void CSVfileRepository::create() {
// file pointer
    ofstream fout(file);
    vector<Car> v1;
    v1.emplace_back(Car("X", "tesla", 2013, 123264, 231, 13412, 3,1));
    v1.emplace_back(Car("Z", "dacia", 2018, 126334, 98, 12412, 1,2));
    v1.emplace_back(Car("X", "tesla", 2017, 152324, 500, 5278, 3,3));
    v1.emplace_back(Car("K", "nissan", 2010, 172334, 876, 12442, 2,4));
    v1.emplace_back(Car("X", "tesla", 2011, 31234, 345, 12448, 4,5));
    v1.emplace_back(Car("H", "dacia", 2021, 61234, 452, 12363, 3.9,6));
    v1.emplace_back(Car("X", "nissan", 2007, 172364, 123, 24567, 3.7,7));
    v1.emplace_back(Car("L", "tesla", 2015, 132334, 456, 45678, 1.9,8));
    v1.emplace_back(Car("X", "dacia", 2013, 123264, 567, 12341,1.5,9));
    v1.emplace_back(Car("M", "nissan", 2018, 16236234, 456, 9887, 2,10));

    // opens an existing csv file or creates a new file.
    // model, brand, year of registration, kilometers, price, charging time, range


    int i, year_of_registration, id;
    float kilometers, price, charging_time, range;
    string model, brand;

    // Read the input
    for (i = 0; i < 10; i++) {
        // Insert the data to file
        fout << i<< "," << v1[i].getModel() << "," << v1[i].getMark() << "," << v1[i].getFabricationYear() << "," << v1[i].getKm() << "," << v1[i].getMaxDistance()
             << ","
             << v1[i].getPrice() << ","<< v1[i].getChargeTime() <<",0"<<endl;

    }
    fout.close();
}

vector<vector<string>> CSVfileRepository::read_from_file() {
    ifstream fin(file);


    string line, word;
    vector<vector<string>> rows;
    vector<string> aux;
    int i=0;
    while (fin>>line) {



        rows.emplace_back(aux);
        stringstream s(line);

        while (getline(s, word, ',')) {
            rows[i].push_back(word);
        }


        i++;
    }
    fin.close();
    return rows;
}

void CSVfileRepository::write_to_file(vector<vector<string>> rows) {
    ofstream fout(file);
    for(int k=0;k<rows.size();k++) {

        for (int j = 0; j < rows[k].size(); j++)
            fout << rows[k][j] << ",";
        fout << "\n";
    }
    fout.close();
}
bool CSVfileRepository::delete_car(int id) {
    // Open FIle pointers

    bool found=false;
    vector<vector<string>> vec=read_from_file();
    for(int i=0;i<vec.size();i++)
        if(stoi(vec[i][0])==id)
        {vec.erase(vec.begin()+i);
            found=true;}
    write_to_file(vec);
    return found;

}

Car CSVfileRepository::string_to_car(vector<string> vec) {
    return Car(vec[1],vec[2],stoi(vec[3]),stoi(vec[4]),stoi(vec[5]), stof(vec[6]),stof(vec[7]),stoi(vec[0]),stoi(vec[8]));
}

vector<Car> CSVfileRepository::search_by_model_and_mark(string model, string mark) {
    vector<vector<string>> vec=read_from_file();
    vector<Car> cars;
    for(int i=0;i<vec.size();i++)
    {

        if(vec[i][1]== mark && vec[i][2]==model)
        {
            cars.emplace_back(string_to_car(vec[i]));
        }
    }
    return cars;
}

vector<Car> CSVfileRepository::filter_by_year(int year) {
    vector<vector<string>> vec=read_from_file();
    vector<Car> cars;
    for(int i=0;i<vec.size();i++)
    {
        if(stoi(vec[i][3])>year)
        {
            cars.emplace_back(string_to_car(vec[i]));
        }
    }
    return cars;
}

vector<Car> CSVfileRepository::filter_by_km(int km) {
    vector<vector<string>> rows=read_from_file();
    vector<Car> cars;
    for(int i=0;i<rows.size();i++)
    {
        if(stoi(rows[i][4])<km)
        {
            cars.emplace_back(string_to_car(rows[i]));
        }
    }
    return cars;
}

bool CSVfileRepository::compare_cars(vector<string> v1, vector<string> v2) {
    return (stoi(v1[5])>stoi(v2[5]));
}
vector<Car> CSVfileRepository::sort_by_price() {
    vector<vector<string>> rows = read_from_file();
    vector<Car> cars;
    for (int i = 0; i < rows.size();i++)
        cars.emplace_back(string_to_car(rows[i]));
    std::sort(cars.begin(), cars.end(), Car::by_price);
    return cars;

}

bool CSVfileRepository::edit_car(int id, float new_price) {
    vector<vector<string>> rows=read_from_file();
    for(int i=0;i<rows.size();i++)
    {
        if(stoi(rows[i][0])==id){
            rows[i][6]= to_string(new_price);
            write_to_file(rows);
            return true;}
    }
    return false;

}

bool CSVfileRepository::add_favourite(int id) {
    vector<vector<string>> rows=read_from_file();
    if(id < 0 || id>rows.size())
        return false;
    for(int i=0;i<rows.size();i++)
    {
        if(stoi(rows[i][0])==id)
            rows[i][8]="1";
    }
    write_to_file(rows);
    return true;
}
void CSVfileRepository::add_car(const string& model, const string& mark, int fabricationYear, int km, int maxDistance, float price, float chargeTime)
{
    vector<vector<string>> vec = read_from_file();
    vector<string> stringCar;
    string smodel = model;
    string smark = mark;
    string sfabYear = to_string(fabricationYear);
    string skm = to_string(km);
    string sprice = to_string(price);
    int whole=(int)(chargeTime*100)/100;
    int dec=(int)(chargeTime*100)%100;
    string s1;
    s1.append(to_string(whole));
    s1.append(".");
    s1.append(to_string(dec));
    string scharge = s1;
    string smaxDistance = to_string(maxDistance);
    stringCar.push_back(to_string(nr_cars++));
    stringCar.push_back(smodel);
    stringCar.push_back(smark);
    stringCar.push_back(sfabYear);
    stringCar.push_back(skm);
    stringCar.push_back(smaxDistance);
    stringCar.push_back(sprice);
    stringCar.push_back(scharge);
    vec.push_back(stringCar);
    write_to_file(vec);
}
Car CSVfileRepository::find_by_id(int id)
{
    string stringID = to_string(id);
    vector<vector<string>> vec = read_from_file();
    int index = -1;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i][0] == stringID)
            index = i;
    }
    string model = vec[index][1];
    string mark = vec[index][2];
    int prod_year = stoi(vec[index][3]);
    int km = stoi(vec[index][4]);
    int price = stoi(vec[index][5]);
    int charge_time = stoi(vec[index][6]);
    int range = stoi(vec[index][7]);
    Car c(model, mark, prod_year, km, price, charge_time, range,stoi(vec[index][0]));
    return c;
}

vector<Car> CSVfileRepository::get_all()
{
    vector<vector<string>> vec = read_from_file();
    vector<Car> cars;

    for (int i = 0; i < vec.size(); i++) {
        string model = vec[i][1];
        string mark = vec[i][2];
        int prod_year = stoi(vec[i][3]);
        int km = stoi(vec[i][4]);
        int price = stof(vec[i][5]);
        int charge_time = stof(vec[i][6]);
        int range = stoi(vec[i][7]);
        Car c(model, mark, prod_year, km, price, charge_time, range,stoi(vec[i][0]));
        cars.push_back(c);
    }
    return cars;
}

vector<Car> CSVfileRepository::get_favourites() {
    vector<vector<string>> rows=read_from_file();
    vector<Car> cars;
    for(int i=0;i<rows.size();i++)
    {
        if(stoi(rows[i][8])==1)
            cars.emplace_back(string_to_car(rows[i]));

    }
    return cars;

}
void CSVfileRepository::replace_cars(vector<vector<string>> vec)
{
    write_to_file(vec);
}
