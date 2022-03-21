#include "recipe.hpp"
#include "item.hpp"

recipe::recipe(){
    item item1(0, "UNKNOWN", "UNKNOWN", 0, 0, "UNKNOWN");
    row = 0;
    col = 0;
    int i = 0;
    for(i = 0; i < 9; i++){
        this->resep[i] = item1;
    }
    hasil = item1;
}

recipe::recipe(int row, int col,  map<int, item> resep, map<int, item> resepMirror, item hasil){
    this->row = row;
    this->col = col;
    this->resep = resep;
    this->resepMirror = resepMirror;
    this->hasil = hasil;
}
