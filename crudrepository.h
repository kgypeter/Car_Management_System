#pragma once

//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <memory>

using namespace std;

template<class E>
class CrudRepository {
public:
    virtual E find_by_id(int id) = 0;

    virtual vector<E> get_all() = 0;

    virtual void
    add_car(const string &model, const string &mark, int fabricationYear, int km, int maxDistance, float price,
            float chargeTime) = 0;

    virtual bool delete_car(int id) = 0;

    virtual bool add_favourite(int id) = 0;

    virtual vector<E> get_favourites() = 0;

    virtual vector<E> search_by_model_and_mark(string model, string mark) = 0;

    virtual vector<E> filter_by_year(int year) = 0;

    virtual vector<E> filter_by_km(int km) = 0;

    virtual vector<E> sort_by_price() = 0;

    virtual bool edit_car(int id, float new_price) = 0;
    virtual void replace_cars(vector<vector<string>> vec)=0;

};
