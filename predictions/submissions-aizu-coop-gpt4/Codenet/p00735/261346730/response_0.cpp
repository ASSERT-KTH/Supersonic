#include <iostream>
#include <vector>
#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> lists;
  bool checked[300000 + 1] = {};
  rep(i, 300000 / 7 + 1) {
    for(int j = 1; j <= 6; j+=5) {
      int num = i * 7 + j;
      if (num > 300000) break;
      if (checked[num]) continue;
      lists.push_back(num);
      for(int k = num * num; k <= 300000; k += num) {
        checked[k] = true;
      }
    }
  }
  while (true) {
    int n;
    cin >> n;
    if (n == 1) break;
    vector<int> ans;
    for (auto p : lists) {
      if (n % p == 0) {
        ans.push_back(p);
      }
    }
    cout << n << ':';
    rep(i, ans.size()) { cout << " " << ans[i]; }
    cout << endl;
  }
}