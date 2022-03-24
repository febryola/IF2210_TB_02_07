//#include "inventory.cpp"
#include "item.cpp"
#include "tool.cpp"
#include "nontool.cpp"
#include "inventory.cpp"
#include "exception.cpp"
#include <iostream>
using namespace std;

int main(){
    inventory *inven = new inventory();
    nontool *item1 = new nontool(1, "OAK_LOG", "LOG", 1660);
    nontool *item2 = new nontool(4, "OAK_PLANK", "PLANK", 200);
    tool *item3 = new tool(13, "IRON_PICKAXE", "-", 1, 2);
    tool *item4 = new tool(14, "WOODEN_AXE", "-", 1, 10);
    nontool *item5 = new nontool(1, "OAK_LOG", "LOG", 60);
    nontool *item6 = new nontool(1, "OAK_LOG", "LOG", 60);

    try {
        (*inven).addNonTool(item1,0); 
        (*inven).addNonTool(item2,0);
        //(*inven).addTool(item3,0); 
        //(*inven).addTool(item4,0);
    }
    catch (InvalidAddItemException e) {
        e.printMessage();
    }

   /* try {
        // (*inven).addNonTool(item1,0); 
        (*inven).toAnotherSlot(0,1); 
        (*inven).toAnotherSlot(1,2);
    }
    catch (DifferentItemNameException e) {
        e.printMessage();
    }*/
    /*(*inven).addNonTool(item2,1);
    (*inven).addTool(item3,2);
    (*inven).addTool(item4,3);
    (*inven).addNonTool(item5,0);
    (*inven).addTool(item4,4);*/
    (*inven).displayMenu();

    //coba use item3 sampai durability habis;
    /*(*item3).printDetails();
    (*inven).useTool(2);
    (*item3).printDetails();
    (*inven).displayDetails();

    (*inven).useTool(2);
    (*item3).printDetails();
    (*inven).displayDetails();
    
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
    (*inven).moveFromCraft(item5,4);
    (*inven).displayMenu();
    (*inven).moveFromCraft(item5,4);
    (*inven).displayMenu();
    (*inven).moveToCraft(4,7);
    item *items = (*inven).moveToCraft(4,7);
    items->printDetails();
    (*inven).displayDetails();
    (*inven).exportInventory("../tests/1.out");*/
    return 0;
}