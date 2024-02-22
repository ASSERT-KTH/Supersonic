#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n, m;
  unordered_map<string, int> rules;
  string l;
  int ans;

  while (true) {
    cin >> n >> m;
    if (!n && !m) break;
    rules.clear();
    ans = 0;

    for (int i = 0; i < n; ++i) {
      cin >> l;
      cin >> rules[l];
    }

    for (int i = 0; i < m; ++i) {
      cin >> l;
      if (rules.count(l)) ans += rules[l];
    }

    cout << ans << endl;
  }

  return 0;
}