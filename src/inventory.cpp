#include "inventory.hpp"
#include "exception.hpp"
#include "crafting.hpp"
#include "console.hpp"
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
        InventoryIndexOutOfBoundException* exc = new InventoryIndexOutOfBoundException(pos, size_inventory);
        throw exc;
    }
    else {
        return this->inv_buffer[pos]; 
    }                                          
}

void inventory :: set(int pos, item* items){
    if(pos < 0 || pos >= size_inventory){
        InventoryIndexOutOfBoundException* exc = new InventoryIndexOutOfBoundException(pos, size_inventory);
        throw exc;
    }
    else {
        (this->inv_buffer[pos]) = items; 
    }              
}

void inventory :: displayMenu(){
    cout << "\nInventory: " << endl;
    for(int i=0; i<size_inventory;i++){
        cout<<"[I" << i << " "
            << (this->inv_buffer[i])->getId()<<" "
            << (this->inv_buffer[i])->getQuantity()<<" "
            << (this->inv_buffer[i])->getDurability()<<"] ";
        if((i+1)%COLOM ==0){
            cout<<endl;
        }
    }
}

void inventory :: displayDetails(){
    cout << "\nInventory Details: " << endl;
        for(int i=0; i<size_inventory;i++){
            if((this->inv_buffer[i])->getDurability()>=0){
                cout<<"Jenis: Tool, Slot_inv: "<<i<<", Nama: "
                <<this->inv_buffer[i]->getName()<<
                " Durability: "<<this->inv_buffer[i]->getDurability()<<endl;
            }
            else if((this->inv_buffer[i])->getDurability()==-1){
                if(isEmpty(i)){
                    cout<< "Jenis: unknown, Slot_inv: "
                    <<i<<", Nama: unknown, Quantity: 0"<<endl;
                }
                else{
                    cout<<"Jenis: NonTool, Slot_inv: "
                    <<i<<", Nama: "<<this->inv_buffer[i]->getName()<<
                    ", Quantity: "<<this->inv_buffer[i]->getQuantity()<<endl;
                }
            }
        }
}

void inventory :: addNonTool(nontool* item){
    for(int i = 0; i<size_inventory; i++){
        //case 1: slot isi
        if(this->inv_buffer[i]->getId()==item->getId()){
            if(this->get(i)->getQuantity()+item->getQuantity()<=MAX_SIZE){ // jika slot isi + quantity item baru <= maksimum
                this->get(i)->setQuantity(this->get(i)->getQuantity()+item->getQuantity());
                return;
            }
            else { // jika slot isi + quantity item baru > maksimum
                item->setQuantity(item->getQuantity()-(MAX_SIZE-this->get(i)->getQuantity()));
                this->get(i)->setQuantity(MAX_SIZE);
                this->addNonTool(item);
                return;
            }
        }
        //case 2: slot kosong
        else if(isEmpty(i)){
            if(item->getQuantity()<=MAX_SIZE){
                set(i,item);
                return;
            }
            else { // item > MAX_SIZE
                nontool* temp = new nontool(item->getId(),item->getName(),item->getType(),MAX_SIZE);
                set(i,temp);
                item->setQuantity(item->getQuantity()-MAX_SIZE);
                this->addNonTool(item);
                return;
            }
        }
    }
}

void inventory :: addTool(tool* item){
    int qty = item->getQuantity();
    int i = 0;
    while (qty>0 && i<size_inventory) {
        if (isEmpty(i)) {
            tool* temp = new tool(item->getId(),item->getName(),item->getType(),1,item->getDurability());
            set(i,temp);
            qty--;
        }
        i++;
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
        InvalidDiscardException* exc = new InvalidDiscardException(this->inv_buffer[slot]->getQuantity(), quantity);
        throw exc;
    }
}

item* inventory :: moveToCraft(int slotInvent, int N){
    item *items = this->inv_buffer[slotInvent];
    item *items1 = this->inv_buffer[slotInvent];
    if(items->getQuantity()==N){
        set(slotInvent,new item());
    }
    else if(items->getQuantity()>N){
        items->setQuantity(items->getQuantity()-N);
    }
    else{
        cout<<"jumlah item tidak cukup"<<endl;//pake exception
    }
    return items1;
}

void inventory :: moveFromCraft(item* i, int slot){
    if (i->getName()==this->inv_buffer[slot]->getName()&&this->inv_buffer[slot]->getQuantity()<64&&this->inv_buffer[slot]->getDurability()==-1){
        this->inv_buffer[slot]->setQuantity(this->inv_buffer[slot]->getQuantity()+1);
    }
    if (this->inv_buffer[slot]->getQuantity()==0){
        set(slot,i);
    }
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

void inventory :: exportInventory(string namaFile){
    ofstream fw;
    fw.open(namaFile);
    if (fw.is_open())
    {
      for (int i = 0; i < size_inventory; i++) {
          if((this->inv_buffer[i])->getDurability()==-1){//nontool
                if(isEmpty(i)){
                    fw <<"0:0"<< "\n";
                }
                else{
                    fw << this->inv_buffer[i]->getId() <<":"<<this->inv_buffer[i]->getQuantity()<< "\n";
                }
                
          }
            else if((this->inv_buffer[i])->getDurability()>=0){//tool
                if(isEmpty(i)){
                    fw <<"0:0"<< "\n";
                }
                else{
                fw << this->inv_buffer[i]->getId() <<":"<<this->inv_buffer[i]->getDurability()<< "\n"; //ini harusnya getDurability
                }
          }
        
      }
      fw.close();
    }
}

int inventory::findItemPos(item i) {
    // diasumsikan item ada di dalam inventory
    int j = 0;
    while (j < size_inventory && !((*get(j))==i)) {
        j++;
    }
    
    return j;
}

void inventory::useTool(int slot) {
    // harus diperiksa i adalah tool atau nontool
    if (isEmpty(slot)) {
        UseEmptyException* exc = new UseEmptyException();
        throw exc;
    }
    else {
        (*get(slot)).useTool();
        if ((*get(slot)).getDurability() == 0) {
            set(slot, new item());
    }
    }
}

bool inventory::isEmpty(int slot) {
    return ((*get(slot)).getId() == 0);
}