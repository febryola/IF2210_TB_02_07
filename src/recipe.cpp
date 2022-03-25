#include "recipe.hpp"
#include "item.hpp"

recipe::recipe(){
    row = -1;
    col = -1;
    int i = 0;
    for(i = 0; i < 9; i++){
        this->resep[i] = "-";
    }
    hasil = "UNKNOWN";
    firstItem = "-";
}

recipe::recipe(int row, int col,  map<int, string> resep, map<int, string> resepMirror, map<int, string> resepMirror2, string hasil){
    this->row = row;
    this->col = col;
    this->resep = resep;
    this->resepMirror = resepMirror;
    for(int i = 0; i<9;i++){
        if(resep[i] != "-"){
            firstItem = resep[i];
            break;
        }
    }
    this->hasil = hasil;
}

int recipe::getRow(){
    return row;
}
int recipe::getCol(){
    return col;
}

void recipe::setRow(int x){
    this->row = x;
}

void recipe::setCol(int x){
    this->col = x;
}

void recipe::setResep(int x, string word){
    this->resep[x] = word;
}

string recipe::getResep(int idx){
    return resep[idx];
}

void recipe::setResepMirror(int x, string word){
    this->resepMirror[x] = word;
}

string recipe::getResepMirror(int idx){
    return resepMirror[idx];
}

string recipe::getFirstItem(){
    return this->firstItem;
}
void recipe::setFirstItem(string fi){
    this->firstItem = fi;
}

int recipe::getQuantity(){
    return quantity;
}

void recipe::setQuantity(int x){
    this->quantity = x;
}

string recipe::getHasil(){
    return hasil;
}

void recipe::setHasil(string word){
    this->hasil = word;
}

void recipe::showRecipe(){
    int i = 0;
    int j = 0;
    int id_counter = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if (this->resep[id_counter] == "UNKNOWN"){
                cout << "- ";
            }else{
                cout << this->resep[id_counter] + " ";
            }
            id_counter++;
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "row : " << this->row << " col : " << this->col << endl;
    cout << this->hasil << endl;
}

void recipe::showMirrorRecipe(){
    int i = 0;
    int j = 0;
    int id_counter = 0;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if (this->resepMirror[id_counter] == "UNKNOWN"){
                cout << "- ";
            }else{
                cout << this->resepMirror[id_counter] + " ";
            }
            id_counter++;
        }
        cout << "\n";
    }
    cout << "\n";
}

int recipe::getNoItem(){
    int counter = 0;
    for(int i = 0; i<9;i++){
        if(resep[i] != "-"){
            counter++;
        }
    }
    return counter;
}