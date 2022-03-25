#include "src/item.cpp"
#include "src/tool.cpp"
#include "src/nontool.cpp"
#include "src/inventory.cpp"
#include "src/crafting.cpp"
#include "src/console.cpp"
#include "src/exception.cpp"
#include "src/listOfRecipe.cpp"
#include "src/recipe.cpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
using namespace std;

void listCommand() {
  // Prosedur untuk menampilkan daftar command
  cout << getColorANSI(RED) << "\nBerikut Daftar Command yang Dapat Digunakan: \n" <<getColorANSI(NORMAL);
  cout << "1. EXPORT  -> mengekspor hasil inputan menjadi file .out ke folder tests\n";
  cout << "2. GIVE    -> menambahkan item ke inventory\n";
  cout << "3. CRAFT   -> melakukan crafting\n";
  cout << "4. MOVE    -> memindahkan item ke slot lain atau ke crafting dan mengembalikan ke inventory\n";
  cout << "5. SHOW    -> menampilkan daftar item yang tersedia\n";
  cout << "6. USE     -> menggunakan tool yang tersedia\n";
  cout << "7. DISCARD -> membuang item dari inventory\n";
  cout << "8. HELP    -> menampilkan daftar command\n";
  cout << "9. EXIT    -> keluar dari program\n";
}

int main() {
  // Deklarasi variabel
  string configPath = "./config";
  string itemConfigPath = configPath + "/item.txt";
  string delimiter = " ";
  string words[4];
  inventory *inven = new inventory();
  //crafting *craft = new crafting();
  map<string, item*> itemMap;
  crafting craft1 = crafting();
  listOfRecipe lor = listOfRecipe();

  // Print welcome screen
  Console::printHeader();

  cout << getColorANSI(RED) << "Berikut Daftar Item yang Dapat Digunakan: \n" << getColorANSI(NORMAL);

  // Read item from config file, and store it in map
  ifstream itemConfigFile(itemConfigPath);
  for (string line; getline(itemConfigFile, line);) {
    cout << line << endl;
    for (int i=0; i<4; i++) {
      words[i] = line.substr(0, line.find(delimiter));
      line.erase(0, line.find(delimiter) + delimiter.length());
    }
    if (words[3] == "TOOL") {
      item *newItem = new tool(stoi(words[0]), words[1], words[2], 0, 10);
      itemMap[words[1]] = newItem;
    } else {
      item *newItem = new nontool(stoi(words[0]), words[2], words[3], 0);
      itemMap[words[1]] = newItem;
    }
  }

  // read recipes
  /*for (const auto &entry :
       filesystem::directory_iterator(configPath + "/recipe")) {
    cout << entry.path() << endl;
    // read from file and do something
  }*/

  // SAMPLE TESTING
  listCommand();
  string command;
  bool isRun = true;
  /*
  string tool_name = "WOODEN_PICKAXE";
  tool* t = new tool(getIDFromName(tool_name), tool_name, getTypeFromName(tool_name), 1, 2);
  (*inven).addTool(t);
  */
  while (isRun) {
    cout << getColorANSI(YELLOW)<< "\nMasukkan command: \n"<<getColorANSI(NORMAL);
    cout << "> ";
    cin >> command;

    // command EXPORT <NAMA_FILE>
    // EXPORT inventory.txt
    /* 
    Export inventory. Semua item pada inventory akan di export ke file argumen. 
    Format dari hasil export adalah sebagai berikut:
      1. Untuk item nontool: <ITEM_ID_0>:<ITEM_QTY_0>
      2. Untuk item tool: <ITEM_ID_0>:<ITEM_DURA_0>
      3. Jika tidak ada item pada slot, keluarkan “0:0”. 
    *//*
    <ITEM_ID_0>:<ITEM_QTY_0>
    <ITEM_ID_1>:<ITEM_DURA_1>
    ...
    <ITEM_ID_26>:<ITEM_QTY_26>
    *//*
    1:64
    24:10
    ...
    0:0
    0:0
    *//*
    I.S. : -
    F.S. : muncul file dengan nama NAMA_FILE yang berisi pasangan 
    ITEM_ID dengan ITEM_QTY / ITEM_DURA untuk setiap slot pada inventory.
    */
    if (command == "EXPORT") {
      string outputPath;
      cin >> outputPath;
      cout << getColorANSI(NORMAL);
      (*inven).exportInventory(outputPath);
    } 

    // command SHOW
    /* 
    Menampilkan crafting table dan inventory. Ilustrasi tampilan ada di spek.
    I.S. : -
    F.S. : isi slot crafting dan inventory ditampilkan
    */
    else if (command == "SHOW") {
      //(*craft).show();
      (*inven).displayMenu();
    } 

    // command CRAFT
    /* 
    Craft Item. 
    Jika terdapat resep yang memenuhi, Item bahan akan hilang dan Item hasil akan muncul. 
    Item akan otomatis ditambahkan ke inventory dengan algoritma yang sama dengan command GIVE. 
    I.S. : Slot crafting membentuk pattern sesuai salah satu recipe.
    F.S. :
      1. Seluruh slot crafting kosong
      2. Item hasil crafting ditambahkan ke inventory sesuai ketentuan di atas.
    */
    else if (command == "CRAFT") {
      try {
        item* hasilCraft = craft1.craft(lor, itemMap);
        if (hasilCraft->getDurability() == -1) { // Nontool
            (*inven).add(hasilCraft);
          }
          cout << "\nItem " << hasilCraft->getName() << " berhasil ditambahkan ke inventory";
          (*inven).displayMenu();
      } 
      catch (CraftIndexOutOfBoundException exc_1) { 
          exc_1.printMessage();
      } 
      catch (CraftSlotExistException exc_2) {
          exc_2.printMessage();
      } 
      catch (CraftDifferentTypeException exc_3) {
          exc_3.printMessage();
      } 
      catch (InvalidRecipeException exc_4) {
          exc_4.printMessage();
      }
    } 

    // command GIVE <ITEM_NAME> <ITEM_QTY>
    // GIVE OAK_WOOD 10
    /*
    Menambahkan Item ke Inventory.
    Sejumlah Item dengan jenis yang sama akan ditambahkan ke slot inventory:
    - Berisi item nontool dengan jenis yang sama
    - Memiliki quantity < 64 (tidak penuh)
    I.S. : -
    F.S. : Item ITEM_NAME pada inventory bertambah sebanyak ITEM_QTY. 
    Otomatis masuk pada slot ID inventory sesuai ketentuan di atas.
    */
    else if (command == "GIVE") {
      /* kalo item > slot sisa blm kehandle | DONE */
      try {
        string itemName;
        int itemQty;
        cin >> itemName >> itemQty;
        if (itemMap.find(itemName) != itemMap.end()) { // item ada di config
          int id = itemMap[itemName]->getId();
          string type = itemMap[itemName]->getType();
          if (itemMap[itemName]->getDurability() == -1) { // Nontool
            nontool *items = new nontool(id,itemName,type,itemQty);
            (*inven).addNonTool(items,0);
          } else { // Tool
            tool *items = new tool(id,itemName,type,itemQty,itemMap[itemName]->getDurability());
            (*inven).addTool(items,0);
          }
          cout << "\nItem " << itemName << " berhasil ditambahkan ke inventory";
          (*inven).displayMenu();
        } else { // item tidak ada di config
          cout << "Item tidak ditemukan" << endl;
        }
      }
      catch (InvalidAddItemException exc) {
        exc.printMessage();
      }
    } 

    // command MOVE; ada tiga varian: inven -> craft, inven -> inven, craft -> inven
    // MOVE <INVENTORY_SLOT_ID> N <CRAFTING_SLOT_ID_1> <CRAFTING_SLOT_ID_2> ...
    // MOVE I0 N C0 C1 C2 ... CN
    /*
    Memindahkan Item ke slot crafting. 
    Satu jenis item dapat dipindahkan ke beberapa slot crafting. 
    Jumlah item harus lebih besar atau sama dengan jumlah slot crafting.
    I.S. : Jumlah Item pada INVENTORY_SLOT_ID sebanyak Qty, dengan Qty >= N (jumlah slot crafting).
    F.S. : 
      1. Jumlah Item pada INVENTORY_SLOT_ID sebanyak Qty - N.
      2. CRAFTING_SLOT_ID_1 hingga N berisi Item yang sama dengan INVENTORY_SLOT_ID dengan jumlah masing-masing 1.
    */
    // MOVE <INVENTORY_SLOT_ID_SRC> 1 <INVENTORY_SLOT_ID_DEST>
    // MOVE I0 1 I1
    /*
    Menumpuk Item. Dua buah item non tool yang sama pada inventory dapat ditumpuk.
    I.S. :
      1. Jumlah Item pada INVENTORY_SLOT_ID_SRC sebanyak Qty1.
      2. Jumlah Item pada INVENTORY_SLOT_ID_DEST sebanyak Qty2.
    F.S. :
      1. Jumlah Item pada INVENTORY_SLOT_ID_SRC sebanyak 0 (item hilang / habis), jika memungkinkan.
      2. Jumlah Jumlah Item pada INVENTORY_SLOT_ID_DEST sebanyak Qty1 + Qty2, namun maksimal sebanyak 64.
    */
    // MOVE <CRAFTING_SLOT_ID> 1 <INVENTORY_SLOT_ID>
    // MOVE C0 1 I0
    /*
    Mengembalikan Item dari slot crafting ke inventory.
    I.S. :
      1. CRAFTING_SLOT_ID tidak kosong.
      2. INVENTORY_SLOT_ID kosong / berisi item dengan jenis yang sama dan tidak penuh.
    F.S. : 
      1. CRAFTING_SLOT_ID kosong.
      2. Jumlah Item pada INVENTORY_SLOT_ID bertambah 1.
    */
    else if (command == "MOVE") {
      try {
        string slotSrc;
        int slotQty;
        string slotDest;
        cin >> slotSrc;
        cin >> slotQty;
        cin >> slotDest;
        if(slotSrc[0]=='I') {
          if(slotDest[0]=='I') { // inven -> inven
            // ini kalo stoi gagal blm kehandle, tambahin exception
            (*inven).toAnotherSlot(stoi(slotSrc.substr(1, slotSrc.size()-1)),stoi(slotDest.substr(1, slotDest.size()-1)));
          }
          else if(slotDest[0]=='C') { // inven -> craft
            item*makan=(*inven).moveToCraft(stoi(slotSrc.substr(1, slotSrc.size()-1)),slotQty);
            for(int i=0;i<slotQty;i++){
              craft1.move(makan,stoi(slotDest.substr(1, slotDest.size()-1)));
            }
          }
        } else if (slotSrc[0]=='C') {
          if (slotDest[0]=='I') { // craft -> inven
            item* itemgajadi = craft1.move(stoi(slotSrc.substr(1,slotSrc.size()-1)));
            
          }
        }
      }
      catch (FullStackException e) {
        e.printMessage();
      }

    } 

    // command DISCARD <INVENTORY_SLOT_ID> <ITEM_QTY>
    // DISCARD I0 32
    /*
    Membuang item di slot inventory dengan kuantitas yang diberikan. 
    Gagal bila kuantitas item lebih kecil dari item yang dijadikan masukan perintah.
    I.S. : Kuantitas item lebih besar sama dengan item pada ITEM_QTY.
    F.S. : Item pada inventory slot INVENTORY_SLOT_ID berkurang sebanyak ITEM_QTY. 
    Hapus item pada slot bila item pada INVENTORY_SLOT_ID = 0.
    */
    else if (command == "DISCARD") {
      int itemQty;
      string slotID;
      cin >> slotID;
      cin >> itemQty;
      int slot = stoi(slotID.substr(1, slotID.size() - 1));
      string name = (*inven).get(slot)->getName();
      try {
        (*inven).discard(itemQty, slot);
        cout << "\nItem " << name << " berhasil dibuang sejumlah " << itemQty << endl;
      }
      catch (InvalidDiscardException exc) {
        exc.printMessage();
      }
    } 

    // command USE <INVENTORY_SLOT_ID>
    // USE I0
    /* 
    Menggunakan Item. Item tool dapat digunakan dan durabilitasnya akan berkurang.
    I.S. : INVENTORY_SLOT_ID berisi Item tool.
    F.S. : Durability Item pada INVENTORY_SLOT_ID berkurang 1. 
    Jika durabilitynya mencapai 0, maka item hilang dari inventory.
    */
    else if (command == "USE") {
      string slotID;
      cin >> slotID;
      int slot = stoi(slotID.substr(1, slotID.size() - 1));
      try {
        string name = (*inven).get(slot)->getName();
        (*inven).useTool(slot);
        int durability = (*inven).get(slot)->getDurability();
        cout << "\nBerhasil menggunakan " <<  name << endl;
        if (durability > 0) {
          cout << "Durability " << name << ": " << durability << endl;
        }
        else {
          cout << "Durability item " << name << " telah mencapai 0, item dihapus dari inventory" << endl;
        }
      }
      catch (BaseException* e) {
        e->printMessage();
      }
    } 

    // command HELP
    /*
    Menampilkan daftar perintah yang tersedia.
    */
    else if (command == "HELP") {
      listCommand();
    }

    // command EXIT
    /*
    Keluar dari permainan.
    */
    else if (command == "EXIT") {
      delete inven;
      //delete craft;
      isRun = false;
      exit(0);
    } 

    else { // invalid command
      cout << getColorANSI(RED) << "Invalid command" << getColorANSI(NORMAL) << endl;
    }
  }

  return 0;
}
