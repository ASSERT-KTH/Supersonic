#include <iostream>
#include <string>
using namespace std;
int main() {
  int H, W;
  while (cin >> H >> W && H != 0 && W != 0) {
    string evenRow, oddRow;
    for (int i = 1; i <= W; i++) {
      evenRow += ".#"[i % 2];
      oddRow += ".#"[i % 2 == 0];
    }
    for (int i = 1; i <= H; i++) {
      cout << ((i % 2) ? oddRow : evenRow) << endl;
    }
    cout << endl;
  }
  return 0;
}