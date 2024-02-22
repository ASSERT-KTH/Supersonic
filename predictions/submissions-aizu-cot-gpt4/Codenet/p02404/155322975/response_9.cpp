#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int H, W;
  while (true) {
    cin >> H >> W;
    if (H == 0 && W == 0)
      break;

    string first_last_line(W, '#');
    string middle_line = '#' + string(W - 2, '.') + '#';
    
    cout << first_last_line << '\n';
    for (int i = 2; i < H; i++) {
      cout << middle_line << '\n';
    }
    if (H > 1) {
      cout << first_last_line << '\n';
    }
    cout << '\n';
  }
}