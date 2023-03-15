#include "controller.h"

Controller::Controller(shared_ptr<CrudRepository<Car>> ptr) {
    R=ptr;
}


void Controller::edit_car(int id, float new_price) {
    if (id < 0 || new_price < 0)
        throw exception();
    if(!R->edit_car(id, new_price))
        throw exception();

}

void
Controller::add_car(const string &model, const string &mark, int fabricationYear, int km, int maxDistance, float price,
                    float chargeTime) {
    if(fabricationYear<1900 || chargeTime<0 || km<0 ||maxDistance<0 || chargeTime<0 || model=="" || mark=="")
        throw exception();
    R->add_car(model, mark, fabricationYear, km, maxDistance, price, chargeTime);
}

vector<Car> Controller::sort_by_price() {
    vector<Car> vec1 = R->sort_by_price();
    return vec1;
}

vector<Car> Controller::search_by_model_and_mark(string model, string mark) {
    //string s;
    vector<Car> vec1 = R->search_by_model_and_mark(mark, model);
    /*for (int i = 0; i < vec1.size(); i++) {
        s.append(vec1[i].car_to_string());
    }*/
    return vec1;
}

vector<Car> Controller::filter_by_year(int year) {
    //string s;
    vector<Car> vec1 = R->filter_by_year(year);
    /*for (int i = 0; i < vec1.size(); i++) {

        s.append(vec1[i].car_to_string());
    }*/
    return vec1;
}

vector<Car> Controller::filter_by_km(int km) {
    //string s;
    vector<Car> vec1 = R->filter_by_km(km);
    /*for (int i = 0; i < vec1.size(); i++) {

        s.append(vec1[i].car_to_string());
    }*/
    return vec1;
}

vector<Car> Controller::all_cars() {
    //string s;
    vector<Car> vec1 = R->get_all();

    /*for (int i = 0; i < vec1.size(); i++) {

        s.append(vec1[i].car_to_string());
    }*/
    return vec1;
}

void Controller::delete_car(int id) {
    if (id < 0)
        throw exception();
    if(!R->delete_car(id))
        throw exception();

}

void Controller::add_favourite(int id) {
    if(id<0)
        throw exception();

    if(!R->add_favourite(id))
        throw exception();

}

vector<Car> Controller::get_favourites() {
    vector<Car> vec1 = R->get_favourites();

    return vec1;
}
vector<Car> Controller:: sortByModel(){
    vector<Car> cars=R->get_all();
    std::sort(cars.begin(), cars.end(),[](Car c1, Car c2){ return c1.model<c2.model;});
    return cars;
}

vector<Car> Controller::sortByKm() {
    vector<Car> cars=R->get_all();
    std::sort(cars.begin(), cars.end(),[](Car c1, Car c2){ return c1.km<c2.km;});
    return cars;
}

vector<Car> Controller::sortByMark() {
    vector<Car> cars=R->get_all();
    std::sort(cars.begin(), cars.end(),[](Car c1, Car c2){ return c1.mark<c2.mark;});
    return cars;
}

vector<Car> Controller::sortByMaxDistance() {
    vector<Car> cars=R->get_all();
    std::sort(cars.begin(), cars.end(),[](Car c1, Car c2){ return c1.max_distance<c2.max_distance;});
    return cars;
}

vector<Car> Controller::sortByFabricationYear() {
    vector<Car> cars=R->get_all();
    std::sort(cars.begin(), cars.end(),[](Car c1, Car c2){ return c1.fabrication_year<c2.fabrication_year;});
    return cars;
}

vector<Car> Controller::sortByChargeTime() {
    vector<Car> cars=R->get_all();
    std::sort(cars.begin(), cars.end(),[](Car c1, Car c2){ return c1.charge_time<c2.charge_time;});
    return cars;
}

vector<Car> Controller::sortByPrice() {
    vector<Car> cars=R->get_all();
    std::sort(cars.begin(), cars.end(),[](Car c1, Car c2){ return c1.price<c2.price;});
    return cars;
}
vector<Car> Controller::sortById() {
    vector<Car> cars=R->get_all();
    std::sort(cars.begin(), cars.end(),[](Car c1, Car c2){ return c1.id<c2.id;});
    return cars;
}
void Controller::replace_cars(vector<vector<string>> vec)
{
    R->replace_cars(vec);
}
//void Controller::test_Controller_and_Repo() {
//    vector<Car> v1;
//    v1.emplace_back(Car("X", "tesla", 2013, 123264, 231, 13412, 3,1));
//    v1.emplace_back(Car("Z", "dacia", 2018, 126334, 98, 12412, 1,2));
//    v1.emplace_back(Car("X", "tesla", 2017, 152324, 500, 5278, 3,3));
//    v1.emplace_back(Car("K", "nissan", 2010, 172334, 876, 12442, 2,4));
//    v1.emplace_back(Car("X", "tesla", 2011, 31234, 345, 12448, 4,5));
//    v1.emplace_back(Car("H", "dacia", 2021, 61234, 452, 12363, 3.9,6));
//    v1.emplace_back(Car("X", "nissan", 2007, 172364, 123, 24567, 3.7,7));
//    v1.emplace_back(Car("L", "tesla", 2015, 132334, 456, 45678, 1.9,8));
//    v1.emplace_back(Car("X", "dacia", 2013, 123264, 567, 12341,1.5,9));
//    v1.emplace_back(Car("M", "nissan", 2018, 16236234, 456, 9887, 2,10));
//    shared_ptr<inMemoryRepo> repo= make_shared<inMemoryRepo>(v1);
//    Controller C = Controller(repo);
//    string s;
//    s = C.sort_by_price();
//    assert(s != "");
//    s = C.filter_by_km(123);
//    assert(s == "");
//    s = C.filter_by_year(2022);
//    assert(s != "");
//    s = C.filter_by_km(100000);
//    assert(s != "");
//    s = C.filter_by_year(2000);
//    assert(s == "");
//    try {
//        C.delete_car(-1);
//        assert(false);
//    }
//    catch (exception &e) {
//
//    }
//    try {
//        C.delete_car(100);
//        assert(false);
//    }
//    catch (exception &e) {
//
//    }
//    try {
//        C.edit_car(100, 0);
//        assert(false);
//    }
//    catch (exception &e) {
//
//    }
//
//
//}
//
