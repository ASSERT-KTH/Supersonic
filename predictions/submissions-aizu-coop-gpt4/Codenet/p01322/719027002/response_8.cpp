#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n, m;
  unordered_map<string, int> score_map;
  string l;
  int ans;
  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    ans = 0;
    score_map.clear();
    for (int i = 0; i < n; i++) {
      cin >> l;
      int o;
      cin >> o;
      score_map[l] = o;
    }
    for (int i = 0; i < m; i++) {
      cin >> l;
      auto it = score_map.find(l);
      if (it != score_map.end()) {
        ans += it->second;
      }
    }
    cout << ans << endl;
  }
  return 0;
}