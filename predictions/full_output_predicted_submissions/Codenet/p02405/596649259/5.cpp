#include <iostream>
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  while (W != 0 && W != 0) {
    for (int i = 1; i <= W; i++) {
      for (int j = 1; j <= W; j++) {
        cout << ".#"[(i + j) % 2 == 0];
      }
      cout << endl;
    }
    cout << endl;
    cin >> H >> W;
  }
  return 0;
}