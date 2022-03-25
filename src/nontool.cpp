// nontool.cpp

#include "nontool.hpp"

nontool::nontool() : item() {

}

nontool::nontool(int id, string name, string type, int quantity) : item(id, name, type, quantity) {
} 

nontool* nontool :: clone(){
    return new nontool(*this);
}