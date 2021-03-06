#include "Console.hpp"
#include "crafting.hpp"
#include "item.hpp"
#include "tool.hpp"
#include "exception.hpp"
#include <iostream>
using namespace std;

crafting::crafting(){
    item item1(0, "UNKNOWN", "UNKNOWN", 0);
    item* newItem = item1.clone();
    int i = 0;
    for(i = 0; i < 9; i++){
        this->table[i] = newItem;
    }
    for(i = 0; i < 9; i++){
        this->stringTable[i] = "abc";
    }
    this->max_row_filled = 0;
    this->max_col_filled = 0;
}
// move ke crafting
void crafting::move(item *itemMoved, int crafting_slot){
    if (crafting_slot < 0 || crafting_slot > 8) {
        CraftIndexOutOfBoundException exc(crafting_slot, 9);
        throw (exc);
    }
    if((*this->table[crafting_slot]).getQuantity() == 0){
        this->table[crafting_slot] = itemMoved;
        (*this->table[crafting_slot]).setQuantity(1);
    } else{
        // throw exception
        CraftSlotExistException (*exc) = new CraftSlotExistException();
        throw (*exc);
    }
    checkCol(crafting_slot);
    checkRow(crafting_slot);
}


// move ke inventory
item* crafting::move(int crafting_slot){
    if (crafting_slot < 0 || crafting_slot > 8) {
        CraftIndexOutOfBoundException exc(crafting_slot, 9);
        throw (exc);
    }
    item item1(0, "UNKNOWN", "UNKNOWN", 0);
    item* def = this->table[crafting_slot];
    item* clone = item1.clone();
    this->table[crafting_slot] = clone;
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
            int id = 0;
            int jumlah = 0;
            if((*this->table[id_counter]).getName() != "UNKNOWN"){
                id = (this->table[id_counter])->getId();
                jumlah = 1;
            }
            cout << "[C" << to_string(id_counter) <<" "
                << to_string(id)<<" "
                << to_string(jumlah) << " "
                << (this->table[id_counter])->getDurability()<<"]";
            id_counter++;
        }
        cout << "\n";
    }
    cout << "\n";
}

void crafting::checkRow(int crafting_slot){
    int counter_row = 0;
    int which_row = crafting_slot/3;
    int counter = 0;
    int i = which_row*3;
    // ngecek row tempat masuk barang
    while(counter != 3){
        if((*this->table[i]).getName() != "UNKNOWN"){
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
        if ((*this->table[i]).getName() != "UNKNOWN"){
            counter_col++;
        }
    }
    if (counter_col > max_col_filled){
        max_col_filled = counter_col;
    }
}

item* crafting::craft(listOfRecipe& recipe_list, map<string, item*> itemMap){
    int idxFound = -1;
    bool sama = true;
    tool* dummy = new tool();
    for(int i=0; i<9; i++){
        string name = (*table[i]).getName();
        if(name!="UNKNOWN"){
            string tipe = itemMap[name]->getName();
            if(tipe!="PLANK" && tipe!="STONE"){
                stringTable[i] = name;
            }else{
                stringTable[i] = tipe;
            }
        } else {
            stringTable[i] = "-";
        }
    }

    // kalo yang dimasukkin ternyata tool semua
    string tipe;
    vector<int> idxTool;
    int countTool = 0;
    int countNonTool = 0;
    int i = 0;
    for(i = 0; i < 9; i++){
        if ((*table[i]).getDurability() > 0){
            countTool++;
            idxTool.push_back(i);
        }else if((*table[i]).getType() == "NONTOOL"){
            countNonTool++;
        }
    }
    if(countTool == 2 && countNonTool == 0 && (*table[idxTool[0]]).getName() == (*table[idxTool[1]]).getName()){
        string name = (*table[idxTool[0]]).getName();
        int id = (*itemMap[name]).getId();
        string tipe = "TOOL";
        int qty = 1;
        int dur = (*table[idxTool[0]]).getDurability() + (*table[idxTool[1]]).getDurability();
        item* newItem = new tool(id, name, tipe, qty, dur);
        return newItem;
    } else if(countTool > 1 && countNonTool > 0) {
        // throw exception
        CraftDifferentTypeException (*exc) =  new CraftDifferentTypeException();
        throw (*exc);
    }

    // NONTOOL
    // check based on recipe list (for 3x3 & 3&2 recipes)
    for(int i=0; i<recipe_list.getSize(); i++){
        recipe temp = recipe_list.getRecipe(i);
        if(temp.getRow() == max_col_filled && temp.getCol() == max_row_filled && temp.getRow() == 3 && temp.getCol() > 1){
            for(int j=0; j<9; j++){
                if(stringTable[j] != temp.getResep(j)){
                    sama = false;
                    break;
                }
            }
            if(sama==true){
                idxFound = i;
            }else{
                sama = true;
            }
        }else{ // check based on first item on table and on recipe
            int firstIdx = 0;
            int firstIdxResep = 0;
            for(int k = 0; k < 9; k++){
                if(stringTable[k] != "-"){
                    firstIdx = k;
                    break;
                }
            }
            string namaItem = stringTable[firstIdx];
            if(temp.getFirstItem() == namaItem && countNonTool == 1){
                idxFound = i;
            }else if(countNonTool>1){
                for(int h = 0; h < 9; h++){
                    if(temp.getResep(h) == temp.getFirstItem()){
                        firstIdxResep = h;
                        break;
                    }
                }
                int cek=0;
                while(isThereItem(firstIdx) && sama && firstIdx < 9 && firstIdxResep < 9){
                    if(stringTable[firstIdx] != temp.getResep(firstIdxResep)){
                        sama = false;
                    }else{
                        if(stringTable[firstIdx]!="-"){
                            cek++;
                        }
                        firstIdx++;
                        firstIdxResep++;
                    }
                }
                if(sama && cek == temp.getNoItem()){
                    idxFound = i;
                }else{
                    sama = true;
                }
            }
        }
    }
    // kalau ga nemu, cek mirror
    if(idxFound==-1){
        for(int i=0; i<recipe_list.getSize(); i++){
            recipe temp = recipe_list.getRecipe(i);
            if(temp.getRow() == max_col_filled && temp.getCol() == max_row_filled  && temp.getRow() == 3 && temp.getCol() > 1){
                for(int j=0; j<9; j++){
                    if(stringTable[j] != temp.getResepMirror(j)){
                        sama = false;
                        break;
                    }
                }
                if(sama==true){
                    idxFound = i;
                }else{
                    sama = false;
                }
            }
        }
    }
    // kalau ketemu resepnya
    if(idxFound != -1){
        string name = recipe_list.getRecipe(idxFound).getHasil();
        int id = itemMap[name]->getId();
        string tipe = itemMap[name]->getType();
        int qty = recipe_list.getRecipe(idxFound).getQuantity();
        if(tipe != "NONTOOL"){
            tool* newItem = new tool(id, name, tipe, qty, 10);
            return newItem;
        }else{
            nontool* newItem = new nontool(id, name, tipe, qty);
            return newItem;
        }
    } else{
        // throw exception
        InvalidRecipeException (*exc) = new InvalidRecipeException();
        throw (*exc);
        // cout << "Not Found" << endl;
    }
    return dummy;
}

bool crafting::isThereItem(int idx){ //ngecek setelah idx masih ada item atau ga
    bool Found = false;
    for(int i = idx;i<9;i++){
        if(stringTable[i] != "-"){
            return true;
        }
    }
    return false;
}

void crafting::deleteAllTable(){ //ngehapus semua item yg ada di table
    item item1(0, "UNKNOWN", "UNKNOWN", 0);
    item* newItem = item1.clone();
    int i = 0;
    for(i = 0; i < 9; i++){
        this->table[i] = newItem;
    }
    for(i = 0; i < 9; i++){
        this->stringTable[i] = "abc";
    }
    this->max_row_filled = 0;
    this->max_col_filled = 0;
}

bool crafting::isSlotEmpty(int idx){ //ngecek apakah di slot idx kosong
    if(this->table[idx]->getId() == 0){
        return true;
    }
    return false;
}

string crafting::getSlotName(int idx){ //get nama item dari slot idx
    return this->table[idx]->getName();
}
