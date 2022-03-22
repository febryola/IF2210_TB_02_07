#ifndef _RECIPE_H
#define _RECIPE_H
#include "item.hpp"
#include <iostream>
#include <iterator>
#include <map>

const int row = 3;
const int col = 3;

class recipe{
    private:
        int row;
        int col;
        map<int, string> resep;
        map<int, string> resepMirror;
        int quantity;
        string hasil;

    public:
        recipe();
        recipe(int row, int col, map<int, item> resep, map<int, item> resepMirror, item hasil);
        int getRow();
        int getCol();
        string getResep(int idx);
        string getResepMirror(int idx);
        int getQuantity();
        string getHasil();



};

#endif