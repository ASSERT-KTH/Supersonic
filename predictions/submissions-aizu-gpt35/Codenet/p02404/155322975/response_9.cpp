#include <iostream>
using namespace std;

int main() {
  int H, W;
  while (1) {
    cin >> H >> W;
    if (H == 0 && W == 0)
      break;

    // Print top row
    for (int j = 1; j <= W; j++) {
      cout << "#";
    }
    cout << endl;

    // Print middle rows
    for (int i = 2; i < H; i++) {
      cout << "#";
      for (int j = 2; j < W; j++) {
        cout << ".";
      }
      cout << "#" << endl;
    }

    // Print bottom row
    for (int j = 1; j <= W; j++) {
      cout << "#";
    }
    cout << endl << endl;
  }
  return 0;
}