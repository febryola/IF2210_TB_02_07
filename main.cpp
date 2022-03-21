// sample main file, replace this with your own code
#include "src/item.cpp"
#include "src/tool.cpp"
#include "src/nontool.cpp"
#include "src/inventory.cpp"
#include "src/crafting.cpp"
#include "src/console.cpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
void listCommand(){
  cout << getColorANSI(RED) << "\nBerikut Daftar Command yang Dapat Digunakan: \n" <<getColorANSI(NORMAL);
  cout << "1. EXPORT  -> mengekspor hasil inputan menjadi file .out ke folder tests\n";
  cout << "2. GIVE    -> menambahkan item ke inventory\n";
  cout << "3. CRAFT   -> melakukan crafting\n";
  cout << "4. MOVE    -> memindahkan item ke slot lain atau ke crafting dan mengembalikan ke inventory\n";
  cout << "5. SHOW    -> menampilkan daftar item yang tersedia\n";
  cout << "6. USE     -> menggunakan tool yang tersedia\n";
  cout << "7. DISCARD -> membuang item dari inventory\n";
  cout << "8. EXIT    -> keluar dari program\n\n";
}

int main() {
  inventory *inven = new inventory();
  crafting *craft = new crafting();
  Console::printHeader();

  cout << getColorANSI(RED) << "Berikut Daftar Item yang Dapat Digunakan: \n" << getColorANSI(NORMAL)<<endl;
  string configPath = "./config";
  string itemConfigPath = configPath + "/item.txt";
  // read item from config file
  ifstream itemConfigFile(itemConfigPath);
  for (string line; getline(itemConfigFile, line);) {
    cout << line << endl;
    // do something
  }

  // read recipes
  /*for (const auto &entry :
       filesystem::directory_iterator(configPath + "/recipe")) {
    cout << entry.path() << endl;
    // read from file and do something
  }*/

  // sample interaction
  listCommand();
  cout << getColorANSI(YELLOW)<< "\nMasukkan command: \n"<<getColorANSI(NORMAL);
  string command;
  while (cin >> command) {
    if (command == "EXPORT") {
       string test = "tests/";
      string outputPath;
      cout << getColorANSI(GREEN)<< "Masukkan nama file: ";
      cin >> outputPath;
      cout << getColorANSI(NORMAL);
      (*inven).exportInventory(test+outputPath);
      cout << "File Exported" << endl;
      cout << getColorANSI(YELLOW)<< "\nMasukkan command: \n"<<getColorANSI(NORMAL);

    } else if (command == "SHOW") {
      (*craft).show();
      cout<<endl;
      (*inven).displayMenu();
      cout << getColorANSI(YELLOW)<< "\nMasukkan command: \n"<<getColorANSI(NORMAL);

    } else if (command == "CRAFT") {
      cout << "TODO" << endl;

    } else if (command == "GIVE") {
      string itemName;
      int itemQty;
      int slot;
      cout << "Masukkan nama item: ";
      cin >> itemName;
      int id = getIDFromName(itemName);
      string type = getTypeFromName(itemName);
      if(id<=12){
        cout << "Masukkan jumlah item: ";
        cin >> itemQty;
        cout << "Masukkan slot ID yang ingin ditempati: ";
        cin >> slot;
        nontool *items = new nontool(id,itemName,type,itemQty);
        (*inven).addNonTool(items,slot);
        cout << getColorANSI(BLUE)<<"Item " << itemName << " berhasil ditambahkan ke Inventory\n";
        cout << getColorANSI(YELLOW)<< "\nMasukkan command: \n"<<getColorANSI(NORMAL);
      }
      else{
        cout << "Masukkan slot ID yang ingin ditempati: ";
        cin >> slot;
        tool *items = new tool(id,itemName,type,1,10);
        (*inven).addTool(items,slot);
        cout << getColorANSI(BLUE)<<"Item " << itemName << " berhasil ditambahkan ke Inventory\n";
        cout << getColorANSI(YELLOW)<< "\nMasukkan command: \n"<<getColorANSI(NORMAL);
      }
      

    } else if (command == "MOVE") {
      int pilihan;
      int slotSrc;
      int slotQty;
      int slotDest;
      cout<<getColorANSI(RED)<<"Menu pada move\n"<<getColorANSI(NORMAL);
      cout<<"1. pindahkan item dari inventory ke craft\n";
      cout<<"2. pindahkan item dari slot inventory ke slot lain\n"<<getColorANSI(NORMAL);
      cout << getColorANSI(MAGENTA)<<"Masukkan pilihan: "<<getColorANSI(NORMAL);
      cin >> pilihan;
      cout << "Masukkan slot ID sumber: ";
      cin >> slotSrc;
      cout << "Masukkan slot ID Tujuan: ";
      cin >> slotDest;
      // need to handle multiple destinations
      if(pilihan==1){
        cout << "Masukkan banyak slot yang ingin dipindahkan: ";
        cin >> slotQty;
        (*inven).moveToCraft(slotSrc,slotQty,slotDest);
        cout << getColorANSI(BLUE)<<"Item pada inventory ID " << slotSrc << " berhasil dipindahkan ke craft ID "<< slotDest <<endl;
        cout << getColorANSI(YELLOW)<< "\nMasukkan command: \n"<<getColorANSI(NORMAL);
      }
      else{
        (*inven).toAnotherSlot(slotSrc,slotDest);
        cout << getColorANSI(BLUE)<<"Item pada inventory ID " << slotSrc << " berhasil dipindahkan ke inventory ID "<< slotDest <<endl;
        cout << getColorANSI(YELLOW)<< "\nMasukkan command: \n"<<getColorANSI(NORMAL);
      }
    }else if (command == "DISCARD") {
      int itemQty;
      int slot;
      cout << "Masukkan jumlah item: ";
      cin >> itemQty;
      cout << "Masukkan slot ID yang ingin ditempati: ";
      cin >> slot;
      (*inven).discard(itemQty,slot);
      cout << getColorANSI(BLUE)<<"Item pada slot " << slot << " berhasil dibuang sebanyak "<<itemQty<< " dari Inventory\n";
      cout << getColorANSI(YELLOW)<< "\nMasukkan command: \n"<<getColorANSI(NORMAL);

    }else if (command == "EXIT") {
      exit(0);

    }else if (command == "USE") {
      int slotID;
      cout<<"Masukkan slot ID item yang ingin digunakan: ";
      cin>>slotID;
      cout << getColorANSI(BLUE)<<"Tool pada slot " << slotID << " berhasil digunakan\n";
      cout << getColorANSI(YELLOW)<< "\nMasukkan command: \n"<<getColorANSI(NORMAL);

    } else {
      // todo
      cout << getColorANSI(RED) << "\nInvalid command" << endl;
      cout << getColorANSI(YELLOW)<< "\nMasukkan command: \n"<<getColorANSI(NORMAL);
    }
  }
  return 0;
}
