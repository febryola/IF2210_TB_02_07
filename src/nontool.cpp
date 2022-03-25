// nontool.cpp

#include "nontool.hpp"

//  CONSTRUCTOR NON-TOOL ITEM
nontool::nontool() : item() {}

nontool::nontool(int id, string name, string type, int quantity) : item(id, name, type, quantity) {
} 

// Duplikasi non-tool item
nontool* nontool :: clone(){
    return new nontool(*this);
}