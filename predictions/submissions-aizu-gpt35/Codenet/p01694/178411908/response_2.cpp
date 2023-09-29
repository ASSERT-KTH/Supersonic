#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  while (cin >> n, n) {
    int ans = 0;
    string now, next;
    cin >> now;
    for (int i = 1; i < n; ++i) {
      cin >> next;
      if (now[0] != next[0] && now[1] != next[1]) ++ans;
      now = next;
    }
    cout << ans << '\n';
  }
  return 0;
}