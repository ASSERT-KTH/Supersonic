#include <iostream>
using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    int ans = 0;
    string now, next;
    cin >> now;
    for (int i = 1; i < n; ++i) {
      cin >> next;
      if ((now[0] == 'l' && next[0] == 'r') || (now[0] == 'r' && next[0] == 'l') ||
          (now[0] == 'l' && next[0] == 'd') || (now[0] == 'r' && next[0] == 'd'))
        ans++;
      now = next;
    }
    cout << ans << endl;
  }
  return 0;
}