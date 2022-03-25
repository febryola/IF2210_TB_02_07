#include "recipe.hpp"
#include "item.hpp"
#include "nontool.hpp"
#include "tool.hpp"
#include "crafting.hpp"
#include "listOfRecipe.hpp"
#include <filesystem>
#include <fstream>
int main(){
    string words[4];
    string delimiter = " ";
    map<string, item*> itemMap;   
    string configPath = "../config";
    string itemConfigPath = configPath + "/item.txt";
    ifstream itemConfigFile(itemConfigPath);
    for (string line; getline(itemConfigFile, line);) {
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
    listOfRecipe lot = listOfRecipe();
    crafting ct = crafting();
    // tool* a = new tool(2, "a", "TOOL", 1, 2);
    // tool* b = new tool(3, "a", "TOOL", 1, 3);
    // cout << to_string(b->getDurability()) << endl;
    // ct.move(a, 0);
    // ct.move(b, 1);
    // item* baru = ct.craft(lot);
    // (*baru).printDetails();
    // cout << (*baru).getDurability() << endl;
    item* x = new nontool(4, "IRON_NUGGET", "NONTOOL", 0);
    item* x1 = new nontool(4, "OAK_PLANK", "NONTOOL", 0);
    item* x2 = new nontool(7, "STICK", "NONTOOL", 0);
    // item* x3 = new nontool(11, "IRON_NUGGET", "NONTOOL", 0);
    // item* x4 = new nontool(11, "IRON_NUGGET", "NONTOOL", 0);
    // item* x5 = new nontool(11, "IRON_NUGGET", "NONTOOL", 0);
    // item* x6 = new nontool(11, "IRON_NUGGET", "NONTOOL", 0);
    // item* x7 = new nontool(11, "IRON_NUGGET", "NONTOOL", 0);
    // item* x8 = new nontool(11, "IRON_NUGGET", "NONTOOL", 0);
    // item* x2 = new nontool(8, "COBBLESTONE", "STONE", 0);
    // item* x3 = new nontool(9, "BLACKSTONE", "STONE", 0);
    // item* x4 = new nontool(7, "STICK", "-", 0);
    // item* x5 = new nontool(7, "STICK", "-", 0);
    ct.move(x, 5);
    ct.move(x1, 2);
    ct.move(x2, 8);
    // ct.move(x3, 3);
    // ct.move(x4, 4);
    // ct.move(x5, 5);
    // ct.move(x6,6);
    // ct.move(x7, 7);
    // ct.move(x8, 8);
    //ct.show();
    item* baru = ct.craft(lot, itemMap);
    ct.showStringTable();
    baru->printDetails();
}