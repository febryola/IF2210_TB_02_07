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
        map<int, item> resep;
        map<int, item> resepMirror;
        item hasil;

    public:
        recipe();
        recipe(int row, int col, map<int, item> resep, map<int, item> resepMirror, item hasil);



};

#endif