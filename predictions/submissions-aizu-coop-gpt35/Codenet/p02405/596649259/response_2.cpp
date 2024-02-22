#include <iostream>
#include <string>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  while (H != 0 && W != 0) {
    string rowString;
    string grid(H * W, ' ');

    for (int i = 1; i <= H; i++) {
      rowString.clear();

      for (int j = 1; j <= W; j++) {
        grid[(i - 1) * W + j - 1] = ".#"[(i ^ j) == 0];
        rowString += grid[(i - 1) * W + j - 1];
      }

      rowString += '\n';
    }

    cout << rowString << endl;
    cin >> H >> W;
  }

  return 0;
}