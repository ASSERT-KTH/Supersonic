#include <iostream>
#include <bitset>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    int ans = 0;
    int now = -1;
    bitset<4> pairs;
    for (int t = 0; t < n; ++t) {
      string next;
      cin >> next;
      int nextValue;
      switch (next[0]) {
        case 'l':
          if (next[1] == 'u') {
            nextValue = 0;
          } else {
            nextValue = 2;
          }
          break;
        case 'r':
          if (next[1] == 'u') {
            nextValue = 1;
          } else {
            nextValue = 3;
          }
          break;
      }
      if (now != -1) {
        pairs.set(now * 4 + nextValue);
      }
      now = nextValue;
    }
    ans = pairs.count();
    cout << ans << endl;
  }
  return 0;
}