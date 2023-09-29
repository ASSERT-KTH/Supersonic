#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> lists;
  bool checked[300000 + 1] = {};
  for (int i = 2; i <= 300000; i += 7) {
    if (!checked[i]) {
      lists.push_back(i);
      for (int j = i; j <= 300000; j += i) {
        checked[j] = true;
      }
    }
    if (i + 5 <= 300000 && !checked[i + 5]) {
      lists.push_back(i + 5);
      for (int j = i + 5; j <= 300000; j += i + 5) {
        checked[j] = true;
      }
    }
  }
  while (true) {
    int n;
    cin >> n;
    if (n == 1)
      break;
    vector<int> ans;
    for (auto p : lists) {
      if (n % p == 0) {
        ans.push_back(p);
      }
    }
    cout << n << ':';
    rep(i, ans.size()) { cout << " " << ans[i]; }
    cout << '\n';
  }
}