#include <iostream>
#include <string>
using namespace std;

int main() {
  int H, W;
  while (1) {
    cin >> H >> W;
    if (H == 0 && W == 0)
      break;
      
    string grid = "";
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        if (i == 1 || i == H || j == 1 || j == W) {
          grid += "#";
        } else {
          grid += ".";
        }
      }
      grid += "\n";
    }
    grid += "\n";
    
    cout << grid;
  }
}