#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
  int H, W;
  while (true) {
    cin >> H >> W;
    if (H == 0 || W == 0)
      break;
    string row;
    for (int i = 1; i <= H; i++) {
      row.clear();
      for (int j = 1; j <= W; j++) {
        if (i == 1 || i == H || j == 1 || j == W) {
          row += "#";
        } else {
          row += ".";
        }
      }
      cout << row << endl;
    }
    cout << endl;
  }
}