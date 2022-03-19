#include "inventory.cpp"
#include "item.cpp"
#include "tool.cpp"
#include "nontool.cpp"
#include <iostream>
using namespace std;

int main(){
    inventory *inven = new inventory();
    nontool *item1 = new nontool(0, "OAK_LOG", "LOG", 7);
    nontool *item2 = new nontool(0, "OAK_PLANK", "PLANK", 6);
    (*inven).addNonTool(item1,0);
    (*inven).addNonTool(item2,1);
    (*inven).displayMenu();
    (*inven).discard(2,1); //membuang item pada slot 1 dengan jumlah 2
    cout<<"Setelah dibuang\n";
    (*inven).displayMenu();
    return 0;
   
}