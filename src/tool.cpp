// tool.cpp

#include "tool.hpp"

tool::tool() : item() {
    durability = 0;
}

tool::tool(int id, string name, string type, int quantity, int durability) : item(id, name, type, quantity) {
    this->durability = durability;
}

int tool::getDurability() {
    return durability;
}

void tool::useTool() {
    durability--;
    // kalau durability = 0, harus dihapus dari inventory
}

tool* tool :: clone(){
    return new tool(*this);
}

void tool::printDetails() {
    this->item::printDetails();
    cout << "Durability: " << this->durability << endl;
}