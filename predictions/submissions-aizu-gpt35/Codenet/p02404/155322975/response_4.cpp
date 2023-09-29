#include <iostream>
using namespace std;
int main() {
  int H, W;
  while (cin >> H >> W && (H || W)) {
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        if (i == 1 || i == H || j == 1 || j == W) {
          cout << "#";
        } else {
          cout << ".";
        }
      }
      cout << endl;
    }
    cout << endl;
  }
}