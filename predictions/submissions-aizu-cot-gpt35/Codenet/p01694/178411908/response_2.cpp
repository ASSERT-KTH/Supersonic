#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    int ans = 0;
    int now = 0, next;
    for (int i = 0; i < n; ++i) {
      cin >> next;
      switch (now) {
        case 0:
          if (next == 1 || next == 3)
            ans++;
          break;
        case 1:
          if (next == 0 || next == 2)
            ans++;
          break;
        case 2:
          if (next == 1 || next == 3)
            ans++;
          break;
        case 3:
          if (next == 0 || next == 2)
            ans++;
          break;
      }
      now = next;
    }
    cout << ans << endl;
  }
  return 0;
}