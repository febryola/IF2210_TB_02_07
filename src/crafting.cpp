#include "crafting.hpp"
#include "item.hpp"
#include <iostream>
using namespace std;

crafting::crafting(){
    item item1(0, "UNKNOWN", "UNKNOWN", 0);
    int i = 0;
    for(i = 0; i < 9; i++){
        this->table[i] = item1;
    }
}
// move ke crafting
void crafting::move(item itemMoved, int crafting_slot){
    this->table[crafting_slot] = itemMoved;
}
//move ke inventory
item crafting::move(int crafting_slot){
    item item1(0, "UNKNOWN", "UNKNOWN", 0);
    item def = this->table[crafting_slot];
    this->table[crafting_slot] = item1;
    return def;
}

// print crafting table
void crafting::show(){
    int i = 0;
    int j = 0;
    int id_counter = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if (this->table[id_counter].getName() == "UNKNOWN"){
                cout << "- ";
            }else{
                cout << this->table[id_counter].getName() + " ";
            }
            id_counter++;
        }
        cout << "\n";
    }
    cout << "\n";
}

bool crafting::isTableEmpty(){
    int i = 0;
    for(i = 0; i < 9; i++){
        if(this->table[i].getName() != "UNKNOWN"){
            return false;
        }
    }
    return true;
}