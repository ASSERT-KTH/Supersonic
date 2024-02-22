#include <iostream>
#include <string>
using namespace std;

int main() {
  int H, W;
  while (1) {
    cin >> H >> W;
    if (H == 0 && W == 0)
      break;
    for (int i = 1; i <= H; i++) {
      string line;
      if (i == 1 || i == H) {
        line = string(W, '#');
      } else {
        line += "#";
        line += string(W-2, '.');
        line += "#";
      }
      cout << line << endl;
    }
    cout << endl;
  }
}