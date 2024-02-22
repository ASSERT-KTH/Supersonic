#include <iostream>
using namespace std;

int main() {
  int H, W;
  while (1) {
    cin >> H >> W;
    if (H == 0 && W == 0)
      break;
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        char c = '.';
        if (i == 1 || i == H || j == 1 || j == W) {
          c = '#';
        }
        cout << c;
      }
      cout << endl;
    }
    cout << endl;
  }
}