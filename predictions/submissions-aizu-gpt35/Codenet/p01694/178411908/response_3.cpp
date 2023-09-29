#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    int ans = 0;
    char now, next;
    cin >> now;
    for (int i = 1; i < n; ++i) {
      cin >> next;
      if (now == 'l' && next == 'u')
        ans++;
      else if (now == 'r' && next == 'u')
        ans++;
      else if (now == 'l' && next == 'd')
        ans++;
      else if (now == 'r' && next == 'd')
        ans++;
      now = next;
    }
    cout << ans << endl;
  }
  return 0;
}