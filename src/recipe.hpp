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
        string firstItem;
        int quantity;
        string hasil;

    public:
        recipe();
        recipe(int row, int col, map<int, string> resep, map<int, string> resepMirror, map<int, string> resepMirror2, string hasil);
        int getRow();
        int getCol();
        void setRow(int x);
        void setCol(int x);
        void setResep(int idx, string kata);
        string getResep(int idx);
        void setResepMirror(int idx, string kata);
        string getResepMirror(int idx);
        string getFirstItem();
        void setFirstItem(string fi);
        int getQuantity();
        void setQuantity(int x);
        string getHasil();
        void setHasil(string word);
        int getNoItem();
        void showRecipe();
        void showMirrorRecipe();



};

#endif