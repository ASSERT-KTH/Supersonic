#include <iostream>
#include <string>
using namespace std;
int main() {
  int H, W;
  while (cin >> H >> W && H != 0 && W != 0) {
    for (int i = 1; i <= H; i++) {
      string line;
      line.reserve(W);
      for (int j = 1; j <= W; j++) {
        line += ".#"[(i + j) % 2 == 0];
      }
      cout << line << '\n';
    }
    cout << '\n';
  }
  return 0;
}