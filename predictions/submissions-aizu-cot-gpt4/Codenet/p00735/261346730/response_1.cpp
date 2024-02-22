#include <vector>
#include <iostream>
using namespace std;
#define int long long
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> lists;
  lists.reserve(300000);
  bool checked[300000 + 1] = {};
  rep2(i, 2, 300000 + 1) {
    if (checked[i])
      continue;
    if (i % 7 == 1 || i % 7 == 6) {
      lists.emplace_back(i);
      for(int j = i; j <= 300000; j += i) {
        checked[j] = true;
      }
    }
  }
  vector<int> ans;
  ans.reserve(300000);
  while (true) {
    int n;
    cin >> n;
    if (n == 1)
      break;
    ans.clear();
    for (auto p : lists) {
      if (n % p == 0) {
        ans.emplace_back(p);
      }
    }
    cout << n << ':';
    for(auto a : ans) { cout << " " << a; }
    cout << '\n';
  }
}