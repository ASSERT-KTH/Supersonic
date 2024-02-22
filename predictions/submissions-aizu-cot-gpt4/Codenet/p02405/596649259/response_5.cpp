#include <iostream>
using namespace std;
int main() {
  int H, W;
  while (cin >> H >> W && H != 0 && W != 0) {
    char buffer[H * W + H + 1];
    int pos = 0;
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        buffer[pos++] = ".#"[(i + j) % 2 == 0];
      }
      buffer[pos++] = '\n';
    }
    buffer[pos] = '\0';
    cout << buffer << endl;
  }
  return 0;
}