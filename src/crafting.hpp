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
        
    public:
        crafting();
        // move ke crafting
        void move(item itemMoved, int crafting_slot);
        // move k inventory
        item move(int crafting_slot);
        void show();
        item craft();
        bool isTableEmpty();

        // ngecek row + column yg udah diisi
        int checkFilledSlot();

};

#endif