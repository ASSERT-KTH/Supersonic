#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int n, m;
  vector<int> o(100);
  unordered_map<string, int> b;
  string l;
  int ans;

  while (cin >> n >> m, n || m) {
    ans = 0;
    b.clear();

    for (int i = 0; i < n; i++) {
      cin >> l >> o[i];
      b[l] = o[i];
    }

    for (int i = 0; i < m; i++) {
      cin >> l;
      for (auto &x : b) {
        bool f = true;
        for (int k = 0; k < 8 && f; k++) {
          if (x.first[k] != '*' && x.first[k] != l[k]) {
            f = false;
          }
        }
        if (f) {
          ans += x.second;
          break;
        }
      }
    }
    cout << ans << '\n';
  }
}