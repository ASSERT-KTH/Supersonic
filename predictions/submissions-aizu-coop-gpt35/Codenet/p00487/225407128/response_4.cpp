#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<pair<ll, int>> p(n), b(n);
  vector<ll> a(n);
  vector<bool> use(n, false);

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i].first;
    p[i] = {a[i], i};
    b[i].second = i;
  }

  partial_sort(p.begin(), p.begin() + n, p.end());
  partial_sort(b.begin(), b.begin() + n, b.end());

  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;

  for (int i = 0; i < n; i++) {
    if (!use[b[i].second]) {
      sum += a[b[i].second];
      use[b[i].second] = true;
      num++;
    }

    while (id < n && p[id].first <= b[i].first && !use[p[id].second]) {
      sum += p[id].first;
      use[p[id].second] = true;
      num++;
      id++;
    }

    while (id < n && !use[p[id].second]) {
      if (sum + p[id].first <= (num + 1) * b[i].first) {
        sum += p[id].first;
        use[p[id].second] = true;
        num++;
      }
      id++;
    }

    if (sum <= num * b[i].first)
      ans = max(ans, num);

    sum -= a[b[i].second];
    num--;
  }

  cout << ans << endl;

  return 0;
}