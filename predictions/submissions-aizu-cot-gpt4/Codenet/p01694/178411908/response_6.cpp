#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  unordered_map<string, int> dir_map = {{"lu", 1}, {"ru", 2}, {"ld", 3}, {"rd", 4}};

  int n;
  while (cin >> n, n) {
    int ans = 0;
    int now = 0, next;
    string next_str;
    for (int i = 0; i < n; ++i) {
      cin >> next_str;
      next = dir_map[next_str];
      if ((now == 1 && next == 2) || (now == 2 && next == 1) || 
          (now == 3 && next == 4) || (now == 4 && next == 3))
        ans++;
      now = next;
    }
    cout << ans << '\n';
  }

  return 0;
}