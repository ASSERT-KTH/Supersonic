#include <iostream>
#include <string>
using namespace std;
int main() {
  int n;
  while (cin >> n, n) {
    int ans = 0;
    string now = "", next;
    for (int i = 0; i < n; ++i) {
      cin >> next;
      if (now[0] == 'l' && next[0] == 'r' && now[1] != next[1])
        ans++;
      else if (now[0] == 'r' && next[0] == 'l' && now[1] != next[1])
        ans++;
      now = next;
    }
    cout << ans << endl;
  }
  return 0;
}