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
    tool *item3 = new tool(1, "IRON_PICKAXE", "-", 1, 10);
    tool *item4 = new tool(1, "WOODEN_AXE", "-", 1, 10);
    nontool *item5 = new nontool(0, "OAK_LOG", "LOG", 8);
    nontool *item6 = new nontool(0, "OAK_LOG", "LOG", 60);
    (*inven).addNonTool(item1,0);
    (*inven).addNonTool(item2,1);
    (*inven).addTool(item3,2);
    (*inven).addTool(item4,3);
    (*inven).addNonTool(item5,4);
    (*inven).addNonTool(item6,5);
    (*inven).displayMenu();
    (*inven).discard(2,1); //membuang item pada slot 1 dengan jumlah 2
    cout<<"Setelah item id 1 dibuang\n";
    (*inven).displayMenu();
    (*inven).discard(4,1);//membuang semua item pada slot 1 dan harusnya skrg sudah hilang
    (*inven).displayMenu();
    (*inven).displayDetails();
    (*inven).toAnotherSlot(4,0);//item pada slot 4 akan hilang
    (*inven).displayMenu();
    (*inven).toAnotherSlot(5,0);//item pada slot 5 masih tersisa
    (*inven).displayMenu();
    (*inven).exportInventory("apa");
    return 0;
   
}