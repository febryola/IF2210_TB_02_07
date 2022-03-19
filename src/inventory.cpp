#include "inventory.hpp"
#include "exception.hpp"
#include <iostream>
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

}

void inventory :: addNonTool(nontool* item, int start){
    for(int i = start; i<size_inventory;i++){
        if(this->get(i)->getId()==item->getId()){
            if(this->get(i)->getQuantity()+item->getQuantity()<=MAX_SIZE){
                this->get(i)->setQuantity(this->get(i)->getQuantity()+item->getQuantity());
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
        if(this->get(i)->getId()==item->getId()){
            set(i,item);
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

void inventory :: moveToCraft(int slotSrc, int destSlot[], int N){

}

void inventory :: toAnotherSlot(int slotSrc, int destSlot[]){

}