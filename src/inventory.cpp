#include "inventory.hpp"
#include "exception.hpp"
#include "crafting.hpp"
#include <iostream>
#include <fstream>
using namespace std;

inventory :: inventory(){
    this->inv_buffer = new item*[size_inventory];
    for(int i = 0; i < size_inventory; i++){
        this->inv_buffer[i] = new item();
    }
}

inventory :: ~inventory(){
    delete[] this->inv_buffer;
}

item* inventory :: get(int pos){
    if(pos < 0 || pos >= size_inventory){
        cout<<"INVALID"<<endl; //ini bisa pake exception nanti
    }
    return this->inv_buffer[pos];                                           
}

void inventory :: set(int pos, item* items){
    if(pos < 0 || pos >= size_inventory){
        cout<<"INVALID"<<endl; //ini bisa pake exception nanti
    }
    (this->inv_buffer[pos]) = items;               
}

void inventory :: specify(int pos){

}

void inventory :: displayMenu(){
    cout << "\nInventory: " << endl;
    for(int i=0; i<size_inventory;i++){
        cout<<"[I" << i << " "
            << (this->inv_buffer[i])->getId()<<" "
            << (this->inv_buffer[i])->getQuantity()<<"] ";
            //<< (this->inv_buffer[i])->getDurability()<<" "
        if((i+1)%COLOM ==0){
            cout<<endl;
        }
    }
}

void inventory :: displayDetails(){
    cout << "\nInventory Details: " << endl;
        for(int i=0; i<size_inventory;i++){
            if((this->inv_buffer[i])->getId()==1){
                cout<<"Jenis: Tool, Slot_inv: "<<i<<", Nama: "
                <<this->inv_buffer[i]->getName()<<
                " Durability: "<<this->inv_buffer[i]->getQuantity()<<endl;//harusnya ini durability
            }
            else{
                cout<<"Jenis: NonTool, Slot_inv: "
                <<i<<", Nama: "<<this->inv_buffer[i]->getName()<<
                " Quantity: "<<this->inv_buffer[i]->getQuantity()<<endl;
            }
        }
}

void inventory :: addNonTool(nontool* item, int start){
    for(int i = start; i<size_inventory;i++){
        if(this->get(i)->getId()==item->getId()){
            if(this->get(i)->getQuantity()+item->getQuantity()<=MAX_SIZE){
                set(i,item);
                return;
            }
            else{
                item->setQuantity(item->getQuantity()-(MAX_SIZE-this->get(i)->getQuantity()));
                cout << "Stacked item, "<<item->getQuantity()<<" left" << endl;
                this->get(i)->setQuantity(MAX_SIZE);
                this->addNonTool(item,i+1);
                return;
            }
        }
    }
}

void inventory :: addTool(tool* item, int quant){
    for(int i = quant; i<size_inventory;i++){
        if(this->get(i)->getId()+1==item->getId()){
            set(i,item);
            return;
        }
    }
}

void inventory :: discard(int quantity, int slot){
    if(this->inv_buffer[slot]->getQuantity()-quantity>0){
        this->inv_buffer[slot]->setQuantity(this->inv_buffer[slot]->getQuantity()-quantity);
    }
    else if(this->inv_buffer[slot]->getQuantity()-quantity==0){
        set(slot, new item());
    }
    else{
        cout<<"EMPTY"<<endl; //bisa pake exception nanti
    }
}

void inventory :: moveToCraft(int slotInvent, int slotCraft, int N){
    crafting *crafting1 = new crafting();
    item *items = this->inv_buffer[slotInvent];
    if(this->inv_buffer[slotInvent]->getQuantity()>=N){
        for(int i=0;i<=slotCraft;i++){
            (*crafting1).move(items,i);
        }
        this->inv_buffer[slotInvent]->setQuantity(items->getQuantity()-N);
    }
    (*crafting1).show();
}

void inventory :: toAnotherSlot(int slotSrc, int destSlot){
    if(this->inv_buffer[slotSrc]->getName()==this->inv_buffer[destSlot]->getName()){
        if(this->inv_buffer[slotSrc]->getQuantity()+this->inv_buffer[destSlot]->getQuantity()<=64){
            this->inv_buffer[destSlot]->setQuantity(this->inv_buffer[slotSrc]->getQuantity()+this->inv_buffer[destSlot]->getQuantity());
            set(slotSrc, new item());
        }
        else{
            this->inv_buffer[slotSrc]->setQuantity((this->inv_buffer[slotSrc]->getQuantity()+this->inv_buffer[destSlot]->getQuantity())%64);
            this->inv_buffer[destSlot]->setQuantity(64);
        }
    }
}

void inventory :: exportInventory(){
    ofstream fw;
    fw.open("inventory.txt");
    if (fw.is_open())
    {
      for (int i = 0; i < size_inventory; i++) {
          if(this->inv_buffer[i]->getId()==0){//nontool
                if(this->inv_buffer[i]->getQuantity()==0){
                    fw <<"0:0"<< "\n";
                }
                else{
                    fw << i <<":"<<this->inv_buffer[i]->getQuantity()<< "\n";
                }
                
          }
            else if(this->inv_buffer[i]->getId()==1){//tool
                if(this->inv_buffer[i]->getQuantity()==0){
                    fw <<"0:0"<< "\n";
                }
                else{
                fw << i <<":"<<this->inv_buffer[i]->getQuantity()<< "\n"; //ini harusnya getDurability
                }
          }
        
      }
      fw.close();
    }
}

