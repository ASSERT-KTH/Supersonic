#include <iostream>
#include <string>
using namespace std;

int main() {
  int H, W;
  string row;

  while (cin >> H >> W && (H != 0 || W != 0)) {
    row.assign(W, '#');

    for (int i = 1; i <= H; i++) {
      if (i == 1 || i == H) {
        cout << row << "\n";
      } else {
        cout << "#" << string(W - 2, '.') << "#\n";
      }
    }

    cout << "\n";
  }

  return 0;
}