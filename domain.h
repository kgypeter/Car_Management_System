#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <memory>
#ifndef L5_ATOM_DOMAIN_H
#define L5_ATOM_DOMAIN_H
using namespace std;

class Car {
private:
    friend class inMemoryRepo;
    friend class Controller;
    string model, mark;
    int fabrication_year,km,max_distance,id;
    float price,charge_time;
    bool is_favourite;
    static int nr_cars;
public:
    Car(const string &model, const string &mark, int fabricationYear, int km, int maxDistance, float price,
        float chargeTime,int id,bool is_favourite=0);
    Car();


    static bool by_price(Car c1,Car c2);
    const string &getModel() const;

    void setModel(const string &model);

    const string &getMark() const;

    void setMark(const string &mark);

    int getFabricationYear() const;

    void setFabricationYear(int fabricationYear);

    int getKm() const;

    void setKm(int km);

    int getMaxDistance() const;

    void setMaxDistance(int maxDistance);

    float getPrice() const;

    void setPrice(float price);

    float getChargeTime() const;

    void setChargeTime(float chargeTime);
    vector<string> car_to_string();

};


#endif //L5_ATOM_DOMAIN_H
