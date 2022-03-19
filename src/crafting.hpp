//base class buat crafting
#ifndef _CRAFTING_H
#define _CRAFTING_H
#include "item.hpp"
#include <iostream>
#include <iterator>
#include <map>

using namespace std;

class crafting{
    private:
        map<int, item> table;
        int max_row_filled;
        int max_col_filled;
        
    public:
        crafting();
        // move ke crafting
        void move(item itemMoved, int crafting_slot);
        // move k inventory
        item move(int crafting_slot);
        void show();
        item craft();
        int checkRow(int crafting_slot);
        int checkCol(int crafting_slot);
        bool isTableEmpty();

};

#endif