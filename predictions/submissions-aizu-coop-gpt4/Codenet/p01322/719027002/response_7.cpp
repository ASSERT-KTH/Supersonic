#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, ans;
  unordered_map<string, int> map;
  string l;

  while(cin >> n >> m && (n || m)) {
    ans = 0;
    map.clear();

    for (int i = 0; i < n; i++) {
      cin >> l;
      for (auto &c : l) if (c == '*') c = '?';
      cin >> map[l];
    }

    for (int i = 0; i < m; i++) {
      cin >> l;
      ans += map[l];
    }

    cout << ans << endl;
  }

  return 0;
}