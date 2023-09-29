#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<ll> lists;
  bool checked[300000 + 1] = {};
  rep2(i, 2, 300000 + 1) {
    if (checked[i])
      continue;
    if (i % 7 == 1 || i % 7 == 6) {
      lists.pb(i);
      for(ll j = i*2; j <= 300000; j += i) {
        checked[j] = true;
      }
    }
  }
  int n;
  while (cin >> n && n != 1) {
    vector<ll> ans;
    for(auto &p : lists) {
      if(n % p == 0) {
        ans.pb(p);
      }
    }
    cout << n << ':';
    for(auto &i : ans) {
      cout << " " << i;
    }
    cout << '\n';
  }
}