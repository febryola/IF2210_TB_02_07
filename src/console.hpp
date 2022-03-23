#pragma once
#include <string>
#include <vector>

using namespace std;
enum Color {
  NORMAL,
  HIDDEN,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE
};
namespace Console {
void printHeader();
int getIDFromName(string name);
string getTypeFromName(string name);
}  // namespace Console