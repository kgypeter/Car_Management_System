#include "domain.h"

const string &Car::getModel() const {
    return model;
}

void Car::setModel(const string &model) {
    Car::model = model;
}

const string &Car::getMark() const {
    return mark;
}

void Car::setMark(const string &mark) {
    Car::mark = mark;
}

int Car::getFabricationYear() const {
    return fabrication_year;
}

void Car::setFabricationYear(int fabricationYear) {
    fabrication_year = fabricationYear;
}

int Car::getKm() const {
    return km;
}

void Car::setKm(int km) {
    Car::km = km;
}

int Car::getMaxDistance() const {
    return max_distance;
}

void Car::setMaxDistance(int maxDistance) {
    max_distance = maxDistance;
}

float Car::getPrice() const {
    return price;
}

void Car::setPrice(float price) {
    Car::price = price;
}

float Car::getChargeTime() const {
    return charge_time;
}

void Car::setChargeTime(float chargeTime) {
    charge_time = chargeTime;
}

Car::Car(const string &model, const string &mark, int fabricationYear, int km, int maxDistance, float price,
         float chargeTime,int id,bool is_favourite) : model(model), mark(mark), fabrication_year(fabricationYear), km(km),
         max_distance(maxDistance), price(price), charge_time(chargeTime) {
    this->id=id;

    is_favourite=0;
}
Car::Car() {
    price=0;
}

bool Car::by_price(Car c1, Car c2) {
    return c1.price<c2.price;
}

vector<string> Car::car_to_string() {
    vector<string> s;
    s.emplace_back(to_string(id));
    s.emplace_back(model);
    s.emplace_back(mark);
    s.emplace_back(to_string(fabrication_year));
    s.emplace_back(to_string(km));
    int whole=(int)(charge_time*100)/100;
    int dec=(int)(charge_time*100)%100;
    string s1;
    s1.append(to_string(whole));
    s1.append(".");
    s1.append(to_string(dec));
    s.emplace_back(s1);
    s.emplace_back(to_string(max_distance));
    s.emplace_back(to_string((int)price));



    return s;
}
