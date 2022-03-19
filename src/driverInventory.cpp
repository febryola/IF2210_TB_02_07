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
    tool *item3 = new tool(1, "STONE", "PLANK", 1, 10);
    tool *item4 = new tool(1, "OAK_STONE", "STONE", 1, 10);
    (*inven).addNonTool(item1,0);
    (*inven).addNonTool(item2,1);
    (*inven).addTool(item3,2);
    (*inven).addTool(item4,3);
    (*inven).displayMenu();
    (*inven).discard(2,1); //membuang item pada slot 1 dengan jumlah 2
    cout<<"Setelah item id 1 dibuang\n";
    (*inven).displayMenu();
    (*inven).discard(4,1);//membuang semua item pada slot 1 dan harusnya skrg sudah hilang
    (*inven).displayMenu();
    (*inven).displayDetails();
    return 0;
   
}