#include <iostream>
#include <string>
using namespace std;
int main() {
  int H, W;
  while (cin >> H >> W && H != 0 && W != 0) {
    string line1, line2;
    for (int j = 1; j <= W; j++) {
      line1 += ".#"[(j % 2 == 0)];
      line2 += ".#"[(j % 2 != 0)];
    }
    for (int i = 1; i <= H; i++) {
      if(i % 2 == 0) cout << line2 << '\n';
      else cout << line1 << '\n';
    }
    cout << '\n';
  }
  return 0;
}