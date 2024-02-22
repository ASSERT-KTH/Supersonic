#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int H, W;
  while (1) {
    cin >> H >> W;
    if (H == 0 && W == 0)
      break;
    string top_bottom = string(W, '#');
    string middle = "#" + string(W-2, '.') + "#";
    for (int i = 1; i <= H; i++) {
      if (i == 1 || i == H) {
        cout << top_bottom << '\n';
      } else {
        cout << middle << '\n';
      }
    }
    cout << '\n';
  }
  return 0;
}