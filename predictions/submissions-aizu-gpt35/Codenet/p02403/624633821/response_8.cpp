#include <iostream>
using namespace std;
int main() {
  int a = 0, b = 0, H, W;
  while (1) {
    cin >> H >> W;
    if (H == 0 && W == 0)
      break;
    cout << string(W, '#') << endl;
    for (int i = 1; i < H-1; i++) {
      cout << "#" << string(W-2, ' ') << "#" << endl;
    }
    cout << string(W, '#') << endl << endl;
  }
  return 0;
}