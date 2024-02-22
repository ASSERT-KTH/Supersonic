#include <iostream>
using namespace std;
int main() {
  int H, W;
  char pattern[2] = {'.', '#'};
  cin >> H >> W;
  while (H != 0 && W != 0) {
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        cout << pattern[(i + j) & 1];
      }
      cout << endl;
    }
    cout << endl;
    cin >> H >> W;
  }
  return 0;
}