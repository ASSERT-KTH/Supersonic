#include <iostream>
#include <string>
using namespace std;
int main() {
  int H, W;
  while (1) {
    cin >> H >> W;
    if (H == 0 && W == 0)
      break;
    string output;
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        if (i == 1 || i == H || j == 1 || j == W) {
          output += '#';
        } else {
          output += '.';
        }
      }
      output += '\n';
    }
    output += '\n';
    cout << output;
  }
}