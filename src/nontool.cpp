// nontool.cpp

#include "nontool.hpp"

nontool::nontool() : item() {
    stacked = 0;
}

nontool::nontool(int id, string name, string type, int quantity) : item(id, name, type, quantity) {
    stacked = 0;
}

int nontool::getStack() {
    return stacked;
}

nontool* nontool :: clone(){
    return new nontool(*this);
}