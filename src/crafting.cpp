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
    this->max_row_filled = 0;
    this->max_col_filled = 0;
}
// move ke crafting
void crafting::move(item *itemMoved, int crafting_slot){
    this->table[crafting_slot] = *itemMoved;
    (this->table[crafting_slot]).setQuantity(1);
    checkCol(crafting_slot);
    checkRow(crafting_slot);
}
//move ke inventory
item crafting::move(int crafting_slot){
    item item1(0, "UNKNOWN", "UNKNOWN", 0);
    item def = this->table[crafting_slot];
    this->table[crafting_slot] = item1;
    checkCol(crafting_slot);
    checkRow(crafting_slot);
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

    cout << "Max Row : " << max_row_filled << endl;
    cout << "Max Col : " << max_col_filled << endl;
}

void crafting::checkRow(int crafting_slot){
    int counter_row = 0;
    int which_row = crafting_slot/3;
    int counter = 0;
    int i = which_row*3;
    // ngecek row tempat masuk barang
    while(counter != 2){
        if(this->table[i].getName() != "UNKNOWN"){
            counter_row++;
        }
        counter++;
        i++;
    }
    if (counter_row > max_row_filled){
        max_row_filled = counter_row;
    }
}
void crafting::checkCol(int crafting_slot){
    int counter_col = 0;
    int which_col = crafting_slot % 3;
    for(int i = which_col; i<9; i+=3){
        if (this->table[i].getName() != "UNKNOWN"){
            counter_col++;
        }
    }
    if (counter_col > max_col_filled){
        max_col_filled = counter_col;
    }
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