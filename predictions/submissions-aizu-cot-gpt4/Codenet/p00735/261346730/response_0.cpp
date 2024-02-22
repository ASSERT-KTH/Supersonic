#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
#define int long long
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
vector<int> lists;
bitset<300001> checked;
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  rep2(i, 2, 300000 + 1) {
    if (checked[i])
      continue;
    if (i % 7 == 1 || i % 7 == 6) {
      lists.push_back(i);
      int k = 1;
      while (i * k <= 300000) {
        checked[i * k] = true;
        k++;
      }
    }
  }
  vector<int> ans;
  while (true) {
    int n;
    cin >> n;
    if (n == 1)
      break;
    for (auto p : lists) {
      if (p > n)
        break;
      if (n % p == 0) {
        ans.push_back(p);
      }
    }
    cout << n << ':';
    for (auto p : ans) cout << " " << p;
    cout << endl;
    ans.clear();
  }
}