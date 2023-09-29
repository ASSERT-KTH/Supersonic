#include <algorithm>
#include <iostream>
#include <vector>
#define fs first
#define sc second
using namespace std;
typedef long long ll;
int n;
vector<pair<ll, int>> p, b;
vector<ll> a;
vector<bool> use;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  p.resize(n);
  b.resize(n);
  a.resize(n);
  use.assign(n, false);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i].fs;
    p[i] = {a[i], i};
    b[i].sc = i;
  }
  sort(p.begin(), p.end());
  sort(b.begin(), b.end());
  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;
  for (int i = 0; i < n; i++) {
    if (!use[b[i].sc]) {
      sum += a[b[i].sc];
      use[b[i].sc] = true;
      num++;
    }
    while (id < n && p[id].fs <= b[i].fs) {
      if (!use[p[id].sc]) {
        sum += p[id].fs;
        use[p[id].sc] = true;
        num++;
      }
      id++;
    }
    while (id < n) {
      if (!use[p[id].sc]) {
        if (sum + p[id].fs > (num + 1) * b[i].fs)
          break;
        sum += p[id].fs;
        use[p[id].sc] = true;
        num++;
      }
      id++;
    }
    ans = max(ans, num);
    sum -= a[b[i].sc];
    num--;
  }
  cout << ans << '\n';
  return 0;
}