#include <iostream>
#include <string>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  while (H != 0 && W != 0) {
    for (int i = 1; i <= H; i++) {
      string line;
      for (int j = 1; j <= W; j++) {
        line += ".#"[(i + j) % 2 == 0];
      }
      cout << line << endl;
    }
    cout << endl;
    cin >> H >> W;
  }
  return 0;
}