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

  // SAMPLE TESTING
  listCommand();
  cout << getColorANSI(YELLOW)<< "\nMasukkan command: \n"<<getColorANSI(NORMAL);
  string command;
  bool isRun = true;

  while (isRun) {
    cin >> command;

    if (command == "EXPORT") 
    {
      string outputPath;
      cin >> outputPath;
      cout << getColorANSI(NORMAL);
      (*inven).exportInventory(outputPath);
    } 
    else if (command == "SHOW") 
    {
      (*craft).show();
      cout << endl;
      (*inven).displayMenu();
    } 
    else if (command == "CRAFT")
    {
      cout << "TODO" << endl;
    } 
    else if (command == "GIVE") 
    {
      string itemName;
      int itemQty;
      cin >> itemName >> itemQty;
      int id = getIDFromName(itemName);
      string type = getTypeFromName(itemName);
      nontool *items = new nontool(id,itemName,type,itemQty);
      (*inven).addNonTool(items,0);
    } 

    else if (command == "MOVE") 
    {
      int slotSrc;
      int slotQty;
      int slotDest;
      cin >> slotSrc;
      cin >> slotQty;
      cin >> slotDest;
      
    } 
    else if (command == "DISCARD") 
    {
      int itemQty;
      string slot;
      cin >> slot;
      cin >> itemQty;
      (*inven).discard(itemQty, stoi(slot.substr(1, slot.size() - 1)));

    } 
    else if (command == "EXIT") 
    {
      isRun = false;
      exit(0);
    } 
    else if (command == "USE") 
    {
      string slotID;
      cin >> slotID;
    } 
    else 
    {
      // todo
      cout << getColorANSI(RED) << "\nInvalid command" << getColorANSI(NORMAL) << endl;
    }
  }
  return 0;
}
