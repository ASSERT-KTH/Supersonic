#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int H, W;
  cin >> H >> W;
  while (H != 0 && W != 0) {
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        cout << ".#"[(i + j) % 2 == 0];
      }
      cout << '\n';
    }
    cout << '\n';
    cin >> H >> W;
  }
  return 0;
}