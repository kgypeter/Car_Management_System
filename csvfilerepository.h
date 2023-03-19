#ifndef A_CSVFILEREPOSITORY_H
#define A_CSVFILEREPOSITORY_H
#ifndef CSV_FILE_REPOSITORY_CSV_FILE_REPOSITORY_H
#define CSV_FILE_REPOSITORY_CSV_FILE_REPOSITORY_H

#endif //CSV_FILE_REPOSITORY_CSV_FILE_REPOSITORY_H

#include "crudrepository.h"
#include "domain.h"

class CSVfileRepository : public CrudRepository<Car> {
private:
    string file;

    vector<vector<string>> read_from_file();

    void write_to_file(vector<vector<string>> vec);

    Car string_to_car(vector<string> vec);

    static bool compare_cars(vector<string> v1, vector<string> v2);
    int nr_cars;

public:
    CSVfileRepository(string filename);

    void create();

    Car find_by_id(int id);

    vector<Car> get_all();

    void
    add_car(const string &model, const string &mark, int fabricationYear, int km, int maxDistance, float price,
            float chargeTime);

    bool delete_car(int id);

    bool add_favourite(int id);

    vector<Car> search_by_model_and_mark(string model, string mark);

    vector<Car> filter_by_year(int year) override;

    vector<Car> get_favourites();

    vector<Car> filter_by_km(int km);

    vector<Car> sort_by_price();

    bool edit_car(int id, float new_price);

    void replace_cars(vector<vector<string>> vec);
};

#endif //A_CSVFILEREPOSITORY_H
