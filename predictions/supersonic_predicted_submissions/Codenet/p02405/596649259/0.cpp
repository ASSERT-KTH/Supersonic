#include <iostream>
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  while (H != 0 && W != 0) {
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        cout << ".#" << (i + j) % 2;
      }
      cout << endl;
    }
    cout << endl;
    cin >> H >> W;
  }
  return 0;
}
