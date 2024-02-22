#include <iostream>
#include <string>

using namespace std;

int main() {
  int H, W;
  while (cin >> H >> W && H != 0 && W != 0) {
    string even_row, odd_row;
    for (int i = 1; i <= W; i++) {
      if (i % 2 == 0) {
        even_row += '#';
        odd_row += '.';
      } else {
        even_row += '.';
        odd_row += '#';
      }
    }

    for (int i = 1; i <= H; i++) {
      if (i % 2 == 0) {
        cout << even_row << endl;
      } else {
        cout << odd_row << endl;
      }
    }
    cout << endl;
  }
  return 0;
}