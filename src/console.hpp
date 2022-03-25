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
string getColorANSI(Color color);
namespace Console {
void printHeader();
}  // namespace Console