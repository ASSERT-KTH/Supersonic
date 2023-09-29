#include <iostream>
using namespace std;
int main() {
  int H, W;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while (cin >> H >> W, H || W) {
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        cout << ".#"[((i + j) & 1)];
      }
      cout << '\n';
    }
    cout << '\n';
  }
  return 0;
}