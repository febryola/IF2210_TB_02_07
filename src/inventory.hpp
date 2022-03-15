//base class buat inventory

#ifndef _INVENTORY_H
#define _INVENTORY_H
#include <iostream>
#include <iterator>
#include <map>
#include "item.hpp"
#define MAX_SIZE 64;
using namespace std;


template <class T> //ini maksudnya bisa tool atau nontool
class block {
    private:
        T item;
        int jumlah;
    public:
        block();
        block(T item, int jumlah);
        ~block();
        T getItem();
        int getJumlah();
        friend block operator+ (block const&, block const&);
};

class inventory {
    private:
        map<int, block<item>> inven;
    public:
        inventory();
        inventory(const inventory &other);
        ~inventory();
};

#endif