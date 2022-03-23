// sample main file, replace this with your own code
#include "src/item.cpp"
#include "src/tool.cpp"
#include "src/nontool.cpp"
#include "src/inventory.cpp"
#include "src/crafting.cpp"
#include "src/console.cpp"
#include "src/exception.cpp"
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
  /*
  string tool_name = "WOODEN_PICKAXE";
  tool* t = new tool(getIDFromName(tool_name), tool_name, getTypeFromName(tool_name), 1, 2);
  (*inven).addTool(t, 1);
  */
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
      //(*t).printDetails();
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
      string slotSrc;
      int slotQty;
      string slotDest;
      cin >> slotSrc;
      cin >> slotQty;
      cin >> slotDest;
      if(slotSrc[0]=='I')
      {
        if(slotDest[0]=='I'){
          (*inven).toAnotherSlot(stoi(slotSrc.substr(1, slotSrc.size()-1)),stoi(slotDest.substr(1, slotDest.size()-1)));
        }
        else if(slotDest[0]=='C'){
          item*makan=(*inven).moveToCraft(stoi(slotSrc.substr(1, slotSrc.size()-1)),slotQty);
          for(int i=0;i<slotQty;i++){
            (*craft).move(makan,stoi(slotDest.substr(1, slotDest.size()-1)));
          }
        }
      }
      
    } 
    else if (command == "DISCARD") 
    {
      int itemQty;
      string slot;
      cin >> slot;
      cin >> itemQty;
      try {
        (*inven).discard(itemQty, stoi(slot.substr(1, slot.size() - 1)));
      }
      catch (BaseException* e) {
        e->printMessage();
      }

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
      try {
        (*inven).useTool(stoi(slotID.substr(1, slotID.size() - 1)));
      }
      catch (BaseException* e) {
        e->printMessage();
      }
    } 
    else 
    {
      // todo
      cout << getColorANSI(RED) << "\nInvalid command" << getColorANSI(NORMAL) << endl;
    }
  }
  return 0;
}
