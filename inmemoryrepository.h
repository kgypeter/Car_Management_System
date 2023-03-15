#ifndef L5_ATOM_REPOSITORY_H
#define L5_ATOM_REPOSITORY_H

#include "domain.h"
#include "crudrepository.h"

using namespace std;

class inMemoryRepo : public CrudRepository<Car> {
    friend class Controller;

private:
    vector<Car> v;
    int nr_cars=0;
public:
    inMemoryRepo();

    inMemoryRepo(vector<Car> vec);

    Car find_by_id(int id);

    vector<Car> get_all();

    void add_car(const string &model, const string &mark, int fabricationYear, int km, int maxDistance, float price,
                 float chargeTime);

    bool delete_car(int id);

    vector<Car> search_by_model_and_mark(string model, string mark);

    bool add_favourite(int id);

    vector<Car> get_favourites();

    vector<Car> filter_by_year(int year);

    vector<Car> filter_by_km(int km);

    vector<Car> sort_by_price();

    bool edit_car(int id, float new_price);

    void replace_cars(vector<vector<string>>);

};


#endif //L5_ATOM_REPOSITORY_H
