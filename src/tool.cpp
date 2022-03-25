// tool.cpp

#include "tool.hpp"

// CONSTRUCTOR TOOL ITEM 
tool::tool() : item() {
    durability = 0;
}

tool::tool(int id, string name, string type, int quantity, int durability) : item(id, name, type, quantity) {
    this->durability = durability;
}

// Mendapatkan durability item
int tool::getDurability() {
    return durability;
}

// Menggunakan tool item
void tool::useTool() {
    durability--;
    // kalau durability = 0, harus dihapus dari inventory
}

// Duplikasi item tool
tool* tool :: clone(){
    return new tool(*this);
}

// Print details item tool
void tool::printDetails() {
    this->item::printDetails();
    cout << "Durability: " << this->durability << endl;
}