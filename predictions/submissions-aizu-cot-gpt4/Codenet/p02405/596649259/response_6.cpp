#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int H, W;
  char pattern[] = ".#";
  while (cin >> H >> W && H != 0 && W != 0) {
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        cout << pattern[(i + j) % 2];
      }
      cout << '\n';
    }
    cout << '\n';
  }
  return 0;
}