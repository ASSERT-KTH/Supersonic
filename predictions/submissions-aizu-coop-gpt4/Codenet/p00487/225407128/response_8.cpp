#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define fs first
#define sc second
using namespace std;
typedef long long ll;
int n;
vector<pair<ll, int>> p, b;
vector<ll> a;
set<int> used, unused;
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  cin >> n;
  p.resize(n);
  b.resize(n);
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i].fs;
    p[i] = make_pair(a[i], i);
    b[i].sc = i;
    unused.insert(i);
  }
  sort(p.begin(), p.end());
  sort(b.begin(), b.end());
  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;
  for (int i = 0; i < n; i++) {
    if (unused.find(b[i].sc) != unused.end()) {
      sum += a[b[i].sc];
      unused.erase(b[i].sc);
      used.insert(b[i].sc);
      num++;
    }
    while (id < n && p[id].fs <= b[i].fs) {
      if (unused.find(p[id].sc) != unused.end()) {
        sum += p[id].fs;
        unused.erase(p[id].sc);
        used.insert(p[id].sc);
        num++;
      }
      id++;
    }
    if (sum <= num * b[i].fs)
      ans = max(ans, num);
    if (used.find(b[i].sc) != used.end()) {
      sum -= a[b[i].sc];
      used.erase(b[i].sc);
      num--;
    }
  }
  cout << ans << endl;
}