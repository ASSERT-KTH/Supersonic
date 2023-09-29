#include <iostream>
#include <vector>
#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::vector<int> lists;
  bool checked[300000 + 1] = {};
  rep2(i, 2, 300000 + 1) {
    if (checked[i])
      continue;
    if (i % 7 == 1 || i % 7 == 6) {
      lists.pb(i);
      for (int k = i; k <= 300000; k += i) {
        checked[k] = true;
      }
    }
  }
  while (true) {
    int n;
    std::cin >> n;
    if (n == 1)
      break;
    std::vector<int> ans;
    for (const auto &p : lists) {
      if (n % p == 0) {
        ans.pb(p);
      }
    }
    std::cout << n << ':';
    for (const auto &p : ans) {
       std::cout << " " << p;
    }
    std::cout << '\n';
  }
}