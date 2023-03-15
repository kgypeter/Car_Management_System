#include "inmemoryrepository.h"

void inMemoryRepo::add_car(const string &model, const string &mark, int fabricationYear, int km, int maxDistance, float price,
                    float chargeTime) {
    Car C = Car(model, mark, fabricationYear, km, maxDistance, price, chargeTime,++nr_cars);
    v.emplace_back(C);
}

bool inMemoryRepo::delete_car(int id) {
    if (!(0 < id < v.size()))
        return false;
    for(int i=0;i<v.size();i++)
        if(v[i].id==id)
        {
            v.erase(v.begin()+i);
            return true;
        }
    return false;
}

vector<Car> inMemoryRepo::filter_by_km(int km) {
    vector<Car> filtered;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getKm() < km)
            filtered.emplace_back(v[i]);
    }
    return filtered;
}

vector<Car> inMemoryRepo::filter_by_year(int year) {
    vector<Car> filtered;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getFabricationYear() < year)
            filtered.emplace_back(v[i]);
    }
    return filtered;

}


vector<Car> inMemoryRepo::search_by_model_and_mark(string model, string mark) {
    vector<Car> filtered;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getModel() == model && v[i].getMark() == mark)
            filtered.emplace_back(v[i]);
    }
    return filtered;
}

vector<Car> inMemoryRepo::sort_by_price() {
    vector<Car> sorted = v;
    std::sort(sorted.begin(), sorted.end(), Car::by_price);
    return sorted;
}

bool inMemoryRepo::edit_car(int id, float new_price) {
    for(int i=0;i<v.size();i++)
        if(v[i].id==id) {
            v[i].is_favourite = 1;
            return true;
        }
    return false;
}

bool inMemoryRepo::add_favourite(int id) {
    if (!(0 < id < v.size()))
        return false;
    for(int i=0;i<v.size();i++)
        if(v[i].id==id) {
            v[i].is_favourite = 1;
            return true;
        }

    return false;
}

vector<Car> inMemoryRepo::get_favourites() {
    vector<Car> vec1;
    for (int i = 0; i < v.size(); i++)
        if (v[i].is_favourite==1)
            vec1.emplace_back(v[i]);
    return vec1;

}

inMemoryRepo::inMemoryRepo(vector<Car> vec) {
    v = vec;
    nr_cars=vec.size();
}

Car inMemoryRepo::find_by_id(int id)
{
    for(int i=0;i<v.size();i++)
        if(v[i].id==id) return v[i];
    return Car();
}

vector<Car> inMemoryRepo::get_all()
{
    return v;
}


inMemoryRepo::inMemoryRepo() {
    nr_cars=0;
}

void inMemoryRepo::replace_cars(vector<vector<string>>)
{

}
