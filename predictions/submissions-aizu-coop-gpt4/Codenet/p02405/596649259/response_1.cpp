#include <iostream>
#include <string>
using namespace std;
int main() {
  int H, W;
  cin >> H >> W;
  while (H != 0 && W != 0) {
    string row1 = string(W / 2, ".#"), row2 = string(W / 2, "#.");
    if(W % 2){
        row1 += ".";
        row2 += "#";
    }
    for (int i = 1; i <= H; i++) {
      if(i % 2 == 1) cout << row1 << endl;
      else cout << row2 << endl;
    }
    cout << endl;
    cin >> H >> W;
  }
  return 0;
}