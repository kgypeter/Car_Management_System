#ifndef L5_ATOM_CONTROLLER_H
#define L5_ATOM_CONTROLLER_H
#include "inmemoryrepository.h"
#include  "crudrepository.h"
#include "csvfilerepository.h"

using namespace std;
class Controller {
private:
    shared_ptr<CrudRepository<Car>> R;
public:
    Controller(shared_ptr<CrudRepository<Car>> ptr);

    void add_car(const string &model, const string &mark, int fabricationYear, int km, int maxDistance, float price,
                 float chargeTime);
    void delete_car(int id);
    vector<Car> all_cars();
    vector<Car> search_by_model_and_mark(string model,string mark);
    void add_favourite(int id);
    vector<Car> get_favourites();
    vector<Car> filter_by_year(int year);
    vector<Car> filter_by_km(int km);
    vector<Car> sort_by_price();
    void edit_car(int id, float new_price);
    vector<Car> sortByModel();
        vector<Car> sortByMark();
        vector<Car> sortByFabricationYear();
        vector<Car> sortByKm();
        vector<Car> sortByMaxDistance();
        vector<Car> sortByPrice();
        vector<Car> sortByChargeTime();
       vector<Car> sortById();
       void replace_cars(vector<vector<string>> vec);
    //static void test_Controller_and_Repo();

};


#endif //L5_ATOM_CONTROLLER_H
